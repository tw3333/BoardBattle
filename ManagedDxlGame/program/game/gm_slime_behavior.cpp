#include "gm_slime_behavior.h"

#include "gm_unit_enemy.h"
#include "gm_unit_ally.h"
#include "gm_board.h"

#include <vector>
#include <cstdlib> // std::rand, std::srand
#include <ctime> // std::time
#include <climits> // INT_MAX
#include <cmath> // std::abs
#include <algorithm> // std::shuffle
#include <queue>

//memo
//all_units_.insert(all_units_.end(), party_units_.begin(), party_units_.end());


void SlimeBehavior::Move(UnitEnemy* turn_enemy, Board* board) {

	//Allyが隣接していたら移動しない
	if (IsAllyAdjacent(turn_enemy, board)) {
		return;
	}
	else {

		// 全てのAllyの隣接する移動可能なマスを集める
		std::vector<SquarePos> allAdjacentSquares = GetAllAlliesAdjacentSquares(board);

		// スライムの現在位置から最短距離にある隣接マスを探す
		SquarePos current_pos = turn_enemy->GetUnitSquarePos();
		std::pair<SquarePos, std::vector<SquarePos>> moveData = GetBestMoveAlongPath(current_pos, allAdjacentSquares, board, turn_enemy->GetCurrentMoveCost());

		// スライムをその位置に移動
		if (!moveData.second.empty()) {
			SquarePos new_pos = moveData.second.front(); // これが新しい位置
			sound_mgr_.PlayAllyMoveSE();
			turn_enemy->SetUnitSquarePos(new_pos.row, new_pos.col);
		}


	}

}

void SlimeBehavior::Act(UnitEnemy* turn_enemy, Board* board) {

	//turn_enemyの位置を取得
	SquarePos turn_enemy_pos = turn_enemy->GetUnitSquarePos();

	//上下左右隣り合っているマスを取得
	std::vector<SquarePos> around_pos = GetActRangePos(turn_enemy);


	//隣り合っているマスにUnitAllyがいたらaround_allyに追加
	std::vector<UnitAlly*> around_ally;
	for (auto pos : around_pos) {
		if (board->getBoardSquare(pos.row, pos.col)->GetAllyPtrInSquare()) {
			around_ally.push_back(board->getBoardSquare(pos.row, pos.col)->GetAllyPtrInSquare());
		}
	}

	UnitAlly* target_ally = nullptr;

	//いなかったら終了
	if (around_ally.empty()) { return; }
	//いる場合
	else if (!around_ally.empty()) {

		target_ally = ExtractMostTauntAlly(around_ally);
	}

	//
	board->getBoardSquare(target_ally->GetUnitSquarePos().row, target_ally->GetUnitSquarePos().col)->SetRenderTargetTile(true);
	board->getBoardSquare(target_ally->GetUnitSquarePos().row, target_ally->GetUnitSquarePos().col)->SetRenderCandidateTile(true);


	//damageを与える
	if (target_ally) {
		target_ally->DecreaseCurrentHp(turn_enemy->GetCurrentPower());

		anim_mgr_.GetAnim()[0]->SetObjPosToSquarePos(target_ally->GetUnitSquarePos().row, target_ally->GetUnitSquarePos().col);
		anim_mgr_.GetAnim()[0]->CardAnimPlay("anim_attack");

		sound_mgr_.PlayEnemyActSE(1);
		sound_mgr_.PlayAllyDamagedVoice(target_ally->GetAllyData()->GetAllyDataID());


		board->getBoardSquare(target_ally->GetUnitSquarePos().row, target_ally->GetUnitSquarePos().col)->SetRenderTargetTile(false);
		board->getBoardSquare(target_ally->GetUnitSquarePos().row, target_ally->GetUnitSquarePos().col)->SetRenderCandidateTile(false);
	}


}

bool SlimeBehavior::IsAllyAdjacent(UnitEnemy* turn_enemy, Board* board) {

	SquarePos directions[] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
	SquarePos enemy_pos = turn_enemy->GetUnitSquarePos();

	for (auto dir : directions) {
		SquarePos check_pos = { enemy_pos.row + dir.row, enemy_pos.col + dir.col };

		if (check_pos.row >= 0 && check_pos.row < 10 && check_pos.col >= 0 && check_pos.col < 10) {

			for (auto ally : board->GetPartyUnitsInBoard()) {
				if (ally->GetUnitSquarePos().row == check_pos.row && ally->GetUnitSquarePos().col == check_pos.col) {
					return true;
				}
			}




		}
	}

	return false;
}

std::vector<SquarePos> SlimeBehavior::GetActRangePos(UnitEnemy* turn_enemy) {

	std::vector<SquarePos> ret_act_range_pos;

	SquarePos turn_enemy_pos = turn_enemy->GetUnitSquarePos();

	// 上下左右のオフセット
	std::vector<SquarePos> offsets = {
		{-1, 0}, // 上
		{1, 0},  // 下
		{0, -1}, // 左
		{0, 1}   // 右
	};

	for (const auto& offset : offsets) {
		int newRow = turn_enemy_pos.row + offset.row;
		int newCol = turn_enemy_pos.col + offset.col;

		if (newRow >= 0 && newRow < 10 && newCol >= 0 && newCol < 10) {
			ret_act_range_pos.push_back(SquarePos(newRow, newCol));
		}

	}

	return ret_act_range_pos;
}


std::pair<SquarePos, std::vector<SquarePos>> SlimeBehavior::GetBestMoveAlongPath(SquarePos start_pos, const std::vector<SquarePos>& targetPositions, Board* board, int move_cost) {
	
	std::queue<SquarePos> q;
	std::map<SquarePos, SquarePos> prev;
	std::vector<SquarePos> path;
	std::vector<std::vector<bool>> visited(10, std::vector<bool>(10, false));
	SquarePos directions[] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} }; // 上、下、左、右

	q.push(start_pos);
	visited[start_pos.row][start_pos.col] = true;
	prev[start_pos] = { -1, -1 };

	while (!q.empty()) {
		SquarePos current = q.front();
		q.pop();

		if (std::find(targetPositions.begin(), targetPositions.end(), current) != targetPositions.end()) {
			for (SquarePos at = current; at != SquarePos{-1, -1}; at = prev[at]) {
				path.push_back(at);
			}
			std::reverse(path.begin(), path.end());
			break;
		}

		for (SquarePos dir : directions) {
			SquarePos next = { current.row + dir.row, current.col + dir.col };
			if (next.row >= 0 && next.row < 10 && next.col >= 0 && next.col < 10 && !visited[next.row][next.col] && board->getBoardSquares()[next.row][next.col]->GetIsCanMove()) {
				q.push(next);
				visited[next.row][next.col] = true;
				prev[next] = current;
			}
		}
	}

	// 最短経路をmove_cost分だけ進む
	std::vector<SquarePos> movePath;
	int path_length = path.size();
	if (path_length > 1 && move_cost > 0) { // path_length > 1 はスタート位置を含むため
		int moves = (std::min)(path_length - 1, move_cost); // スタート位置は除外してカウント
		movePath.assign(path.begin() + 1, path.begin() + 1 + moves); // +1 はスタート位置をスキップ
	}

	SquarePos final_pos = movePath.empty() ? start_pos : movePath.back();
	return { final_pos, movePath };
}



////移動処理
////最も近いAllyを探す
//UnitAlly* target_ally = this->GetNearestAlly(turn_enemy, board);


////移動先を決定
//SquarePos start = turn_enemy->GetUnitSquarePos();
//SquarePos target_pos = target_ally->GetUnitSquarePos();
//final_pos_ = start;
//target_pos_ = target_pos;

//// BFSのためのデータ構造
//SquarePos directions[] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
//std::vector<std::vector<bool>> visited(10, std::vector<bool>(10, false));
//std::queue<std::pair<SquarePos, int>> q;
//SquarePos startPos = turn_enemy->GetUnitSquarePos();
//SquarePos targetPos = target_ally->GetUnitSquarePos();

//q.push({ startPos, turn_enemy->GetCurrentMoveCost() });
//visited[startPos.row][startPos.col] = true;

//SquarePos nextPos = startPos;

//while (!q.empty()) {
//	SquarePos currPos = q.front().first;
//	int remainingMove = q.front().second;
//	q.pop();

//	int currDist = std::abs(currPos.row - targetPos.row) + std::abs(currPos.col - targetPos.col);

//	for (SquarePos dir : directions) {
//		SquarePos adjPos = { currPos.row + dir.row, currPos.col + dir.col };
//		int newDist = std::abs(adjPos.row - targetPos.row) + std::abs(adjPos.col - targetPos.col);

//		if (adjPos.row >= 0 && adjPos.row < 10 && adjPos.col >= 0
//			&& adjPos.col < 10 && !visited[adjPos.row][adjPos.col]
//			&& board->getBoardSquares()[adjPos.row][adjPos.col]->GetIsCanMove())
//		{
//			if (remainingMove > 0 && newDist < currDist) { //移動可能かつターゲットに近づく場合
//				q.push({ adjPos, remainingMove - 1 });
//				visited[adjPos.row][adjPos.col] = true;
//				nextPos = adjPos;  //次の座標に更新
//			}
//		}
//	}
//}

////座標を更新
//sound_mgr_.PlayAllyMoveSE();
//turn_enemy->SetUnitSquarePos(nextPos.row, nextPos.col);



//11/11
//	//Allyが隣接していたら移動しない
//if (IsAllyAdjacent(turn_enemy, board)) {
//	return;
//}
//else {
//
//	// 移動処理
//	// 最も近いAllyを探す
//	UnitAlly* target_ally = this->GetNearestAlly(turn_enemy, board);
//
//	// 移動先を決定
//	SquarePos start = turn_enemy->GetUnitSquarePos();
//	SquarePos target_pos = target_ally->GetUnitSquarePos();
//	final_pos_ = start;
//	target_pos_ = target_pos;
//
//	// BFSのためのデータ構造
//	SquarePos directions[] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
//	std::vector<std::vector<bool>> visited(10, std::vector<bool>(10, false));
//	std::queue<std::pair<SquarePos, int>> q;
//	SquarePos startPos = turn_enemy->GetUnitSquarePos();
//	SquarePos targetPos = target_ally->GetUnitSquarePos();
//
//	q.push({ startPos, turn_enemy->GetCurrentMoveCost() });
//	visited[startPos.row][startPos.col] = true;
//
//	SquarePos bestPos = startPos;
//	int bestDist = std::abs(startPos.row - targetPos.row) + std::abs(startPos.col - targetPos.col);
//
//	while (!q.empty()) {
//		SquarePos currPos = q.front().first;
//		int remainingMove = q.front().second;
//		q.pop();
//
//		int currDist = std::abs(currPos.row - targetPos.row) + std::abs(currPos.col - targetPos.col);
//
//		for (SquarePos dir : directions) {
//			SquarePos adjPos = { currPos.row + dir.row, currPos.col + dir.col };
//			int newDist = std::abs(adjPos.row - targetPos.row) + std::abs(adjPos.col - targetPos.col);
//
//			if (adjPos.row >= 0 && adjPos.row < 10 && adjPos.col >= 0
//				&& adjPos.col < 10 && !visited[adjPos.row][adjPos.col]
//				&& board->getBoardSquares()[adjPos.row][adjPos.col]->GetIsCanMove())
//			{
//				if (remainingMove > 0 && newDist < currDist) { // 移動可能かつターゲットに近づく場合
//					q.push({ adjPos, remainingMove - 1 });
//					visited[adjPos.row][adjPos.col] = true;
//					if (newDist < bestDist) {
//						bestDist = newDist;
//						bestPos = adjPos;
//					}
//				}
//			}
//		}
//	}
//
//	// 座標を更新
//	sound_mgr_.PlayAllyMoveSE();
//	turn_enemy->SetUnitSquarePos(bestPos.row, bestPos.col);
//}