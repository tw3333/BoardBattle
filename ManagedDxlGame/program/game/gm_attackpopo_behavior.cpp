#include "gm_attackpopo_behavior.h"

#include "gm_unit_ally.h"
#include "gm_unit_enemy.h"
#include "gm_board.h"

#include <vector>
#include <cstdlib> // std::rand, std::srand
#include <ctime> // std::time
#include <climits> // INT_MAX
#include <cmath> // std::abs
#include <algorithm> // std::shuffle
#include <queue>


void AttackPopoBehavior::Move(UnitEnemy* turn_enemy, Board* board) {

	//1.Range内にAllyがいた場合は移動しない
	if (IsAllyActInRange(turn_enemy, board)) {
		return;
	}

	//2.Allyが隣接していた場合一マス遠ざかる
	if (IsAllyAdjacent(turn_enemy, board)) {

		SquarePos enemy_pos = turn_enemy->GetUnitSquarePos();
		SquarePos directions[] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };  // 上、下、左、右

		int max_distance = INT_MIN;
		SquarePos best_direction = enemy_pos;

		for (auto dir : directions) {
			SquarePos new_pos = { enemy_pos.row + dir.row, enemy_pos.col + dir.col };
			int min_distance_for_this_dir = INT_MAX;

			for (auto ally : board->GetPartyUnitsInBoard()) {
				SquarePos ally_pos = ally->GetUnitSquarePos();
				int distance = CalDistance(new_pos, ally_pos);
				min_distance_for_this_dir = (std::min)(min_distance_for_this_dir, distance);
			}

			if (min_distance_for_this_dir > max_distance) {
				max_distance = min_distance_for_this_dir;
				best_direction = new_pos;
			}
		}

		//移動可能なら移動
		if (board->getBoardSquare(best_direction.row, best_direction.col)->GetIsCanMove()) {
			sound_mgr_.PlayAllyMoveSE();
			//座標を更新
			turn_enemy->SetUnitSquarePos(best_direction.row, best_direction.col);
		}

		return;
	}

	//3.Range内にAllyがいない場合は一番近いAllyに近づく
	if (!IsAllyActInRange(turn_enemy, board)) {

		// 全てのAllyの1マス先の移動可能なマスを集める
		std::vector<SquarePos> all_adjacent_squares = GetAllAlliesOneStepAwaySquares(board);

		//アタックポポの現在位置から最短距離にある隣接マスを探す
		SquarePos current_pos = turn_enemy->GetUnitSquarePos();
		std::pair<SquarePos, std::vector<SquarePos>> move_data = GetBestMoveAlongPath(current_pos, all_adjacent_squares, board, turn_enemy->GetCurrentMoveCost());

		//アタックポポをその位置に移動
		if (!move_data.second.empty()) {
			SquarePos new_pos = move_data.second.front(); // これが新しい位置
			sound_mgr_.PlayAllyMoveSE();
			turn_enemy->SetUnitSquarePos(new_pos.row, new_pos.col);
		}
	}

}

void AttackPopoBehavior::Act(UnitEnemy* turn_enemy, Board* board) {

	//turn_enemyの位置を取得
	SquarePos turn_enemy_pos = turn_enemy->GetUnitSquarePos();

	//Range内のマス目を取得
	std::vector<SquarePos> around_pos;
	if (turn_enemy_pos.row > 0) {
		around_pos.push_back(SquarePos(turn_enemy_pos.row - 2, turn_enemy_pos.col));
	}
	if (turn_enemy_pos.row < 9) {
		around_pos.push_back(SquarePos(turn_enemy_pos.row + 2, turn_enemy_pos.col));
	}
	if (turn_enemy_pos.col > 0) {
		around_pos.push_back(SquarePos(turn_enemy_pos.row, turn_enemy_pos.col - 2));
	}
	if (turn_enemy_pos.col < 9) {
		around_pos.push_back(SquarePos(turn_enemy_pos.row, turn_enemy_pos.col + 2));
	}

	//隣り合っているマスにUnitAllyがいたらaround_allyに追加
	std::vector<UnitAlly*> in_range_ally; //格納配列

	for (auto& pos : around_pos) {

		if (board->getBoardSquare(pos.row, pos.col)->GetAllyPtrInSquare()) {
			in_range_ally.push_back(board->getBoardSquare(pos.row, pos.col)->GetAllyPtrInSquare());
		}
	}

	//攻撃処理
	UnitAlly* target_ally = nullptr; //攻撃対象

	//いなかったら終了
	if (in_range_ally.empty()) { return; }
	else if (!in_range_ally.empty()) {    //いる場合

		// taunt_ 値でソート
		std::sort(in_range_ally.begin(), in_range_ally.end(), [](UnitAlly* a, UnitAlly* b) {
			return a->GetTauntValue() < b->GetTauntValue();
			});

		// 最も高い taunt_ 値を持つ要素をすべて収集
		int highest_taunt = in_range_ally.back()->GetTauntValue();
		std::vector<UnitAlly*> highest_taunt_allies;
		std::copy_if(in_range_ally.begin(), in_range_ally.end(), std::back_inserter(highest_taunt_allies), [highest_taunt](UnitAlly* unit) {
			return unit->GetTauntValue() == highest_taunt;
			});

		// ランダムに1つ選ぶ
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> distr(0, highest_taunt_allies.size() - 1);

		target_ally = highest_taunt_allies[distr(gen)];
	}

	//damageを与える
	if (target_ally) {
		target_ally->DecreaseCurrentHp(turn_enemy->GetCurrentPower());

		anim_mgr_.GetAnim()[0]->SetObjPosToSquarePos(target_ally->GetUnitSquarePos().row, target_ally->GetUnitSquarePos().col);
		anim_mgr_.GetAnim()[0]->CardAnimPlay("anim_flame");

		sound_mgr_.PlayCardSE(11);
		sound_mgr_.PlayAllyDamagedVoice(target_ally->GetAllyData()->GetAllyDataID());

	}

}

bool AttackPopoBehavior::IsAllyActInRange(UnitEnemy* turn_enemy, Board* board) {

	SquarePos directions[] = { {-2, 0}, {2, 0}, {0, -2}, {0, 2} };
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


bool AttackPopoBehavior::IsAllyAdjacent(UnitEnemy* turn_enemy, Board* board) {

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

std::pair<SquarePos, std::vector<SquarePos>> AttackPopoBehavior::GetBestMoveAlongPath(SquarePos start_pos, const std::vector<SquarePos>& targetPositions, Board* board, int move_cost) {

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

std::vector<SquarePos> AttackPopoBehavior::GetOneStepAwaySquares(SquarePos pos, Board* board) {

	std::vector<SquarePos> ret_one_step_away_squares;
	SquarePos directions[] = { {-2, 0}, {2, 0}, {0, -2}, {0, 2} }; // 1マス先の位置

	for (SquarePos dir : directions) {
		SquarePos one_step_away_pos = { pos.row + dir.row, pos.col + dir.col };

		if (one_step_away_pos.row >= 0 && one_step_away_pos.row < 10 && one_step_away_pos.col >= 0 && one_step_away_pos.col < 10
			&& board->getBoardSquares()[one_step_away_pos.row][one_step_away_pos.col]->GetIsCanMove()) {
			ret_one_step_away_squares.push_back(one_step_away_pos);
		}
	}

	return ret_one_step_away_squares;

}



std::vector<SquarePos> AttackPopoBehavior::GetAllAlliesOneStepAwaySquares(Board* board) {

	std::vector<SquarePos> ret_all_one_step_away_squares;

	for (int row = 0; row < 10; ++row) {
		for (int col = 0; col < 10; ++col) {
			if (board->getBoardSquares()[row][col]->GetAllyPtrInSquare()) {
				std::vector<SquarePos> one_step_away_squares = GetOneStepAwaySquares(SquarePos{ row, col }, board);
				ret_all_one_step_away_squares.insert(ret_all_one_step_away_squares.end(), one_step_away_squares.begin(), one_step_away_squares.end());
			}
		}
	}

	return ret_all_one_step_away_squares;

}
