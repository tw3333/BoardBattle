#include "gm_healpopo_behavior.h"

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



void HealPopoBehavior::Move(UnitEnemy* turn_enemy, Board* board) {

	//Range内にAllyがいた場合は移動しない
	if (IsAllyActInRange(turn_enemy, board)) {
		return;
	}

	//Allyが隣接していた場合一マス遠ざかる
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


	if (!IsAllyActInRange(turn_enemy, board)) {

		//Range内にEnemyがいない場合は一番近いEnemyに近づく
		std::vector<UnitEnemy*> nearest_enemies;
		int min_distance = INT_MAX;

		for (auto enemy : board->GetEnemyUnitsInBoard()) {
			int distance = std::abs(turn_enemy->GetUnitSquarePos().row - enemy->GetUnitSquarePos().row)
				+ std::abs(turn_enemy->GetUnitSquarePos().col - enemy->GetUnitSquarePos().col);

			if (distance < min_distance) {
				nearest_enemies.clear();
				nearest_enemies.push_back(enemy);
				min_distance = distance;
			}
			else if (distance == min_distance) {
				nearest_enemies.push_back(enemy);
			}
		}

		std::uniform_int_distribution<int> dist(0, nearest_enemies.size() - 1);
		UnitEnemy* target_enemy = nearest_enemies[dist(h_rng)];

		SquarePos start = turn_enemy->GetUnitSquarePos();
		SquarePos target_pos = target_enemy->GetUnitSquarePos();
		final_pos_ = start;
		target_pos_ = target_pos;

		// BFSによる計算
		SquarePos directions[] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
		std::vector<std::vector<bool>> visited(10, std::vector<bool>(10, false));
		std::queue<std::pair<SquarePos, int>> q;
		SquarePos startPos = turn_enemy->GetUnitSquarePos();
		SquarePos targetPos = target_enemy->GetUnitSquarePos();

		q.push({ startPos, turn_enemy->GetCurrentMoveCost() });
		visited[startPos.row][startPos.col] = true;

		SquarePos nextPos = startPos;

		while (!q.empty()) {
			SquarePos currPos = q.front().first;
			int remainingMove = q.front().second;
			q.pop();

			int currDist = std::abs(currPos.row - targetPos.row) + std::abs(currPos.col - targetPos.col);

			for (SquarePos dir : directions) {
				SquarePos adjPos = { currPos.row + dir.row, currPos.col + dir.col };
				int newDist = std::abs(adjPos.row - targetPos.row) + std::abs(adjPos.col - targetPos.col);

				if (adjPos.row >= 0 && adjPos.row < 10 && adjPos.col >= 0 && adjPos.col < 10 && !visited[adjPos.row][adjPos.col] && board->getBoardSquares()[adjPos.row][adjPos.col]->GetIsCanMove()) {

					if (remainingMove > 0 && newDist < currDist) { //移動可能かつターゲットに近づく場合
						q.push({ adjPos, remainingMove - 1 });
						visited[adjPos.row][adjPos.col] = true;
						nextPos = adjPos;  //次の座標に更新
					}
				}
			}
		}

		//座標更新
		turn_enemy->SetUnitSquarePos(nextPos.row, nextPos.col);
		sound_mgr_.PlayAllyMoveSE();
		return;
	}

}

void HealPopoBehavior::Act(UnitEnemy* turn_enemy, Board* board) {

	//turn_enemyの位置を取得
	SquarePos turn_enemy_pos = turn_enemy->GetUnitSquarePos();

	//Range内のマス目を取得
	std::vector<SquarePos> in_range_pos;
	if (turn_enemy_pos.row > 0) {
		in_range_pos.push_back(SquarePos(turn_enemy_pos.row - 1, turn_enemy_pos.col));
	}
	if (turn_enemy_pos.row < 9) {
		in_range_pos.push_back(SquarePos(turn_enemy_pos.row + 1, turn_enemy_pos.col));
	}
	if (turn_enemy_pos.col > 0) {
		in_range_pos.push_back(SquarePos(turn_enemy_pos.row, turn_enemy_pos.col - 1));
	}
	if (turn_enemy_pos.col < 9) {
		in_range_pos.push_back(SquarePos(turn_enemy_pos.row, turn_enemy_pos.col + 1));
	}

	//Range内にUnitEnemyがいたらin_range_enemyに追加
	std::vector<UnitEnemy*> in_range_enemy; //Range内のUnitEnemyを格納

	for (auto& pos : in_range_pos) {
		if (board->getBoardSquare(pos.row, pos.col)->GetEnemyPtrInSquare()) {
			in_range_enemy.push_back(board->getBoardSquare(pos.row, pos.col)->GetEnemyPtrInSquare());
		}
	}


	UnitEnemy* target_enemy = nullptr;

	//いなかったら終了
	if (in_range_enemy.empty()) { return; }
	else if (!in_range_enemy.empty()) {    //いる場合

		//CurrentHp値でソート
		std::sort(in_range_enemy.begin(), in_range_enemy.end(), [](UnitEnemy* a, UnitEnemy* b) {
			return a->GetCurrentHp() > b->GetCurrentHp();
			});

		// 最も少ないCurrentHp値を持つ要素をすべて収集
		int lowest_hp = in_range_enemy.back()->GetCurrentHp();
		std::vector<UnitEnemy*> lowest_hp_enemies;
		std::copy_if(in_range_enemy.begin(), in_range_enemy.end(), std::back_inserter(lowest_hp_enemies), [lowest_hp](UnitEnemy* unit) {
			return unit->GetCurrentHp() == lowest_hp;
			});

		// ランダムに1つ選ぶ
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> distr(0, lowest_hp_enemies.size() - 1);

		target_enemy = lowest_hp_enemies[distr(gen)];
	}

	//target_enemyのHPを回復
	if (target_enemy) {

		if (target_enemy->GetMaxHp() == target_enemy->GetCurrentHp()) {
			return;
		}


		target_enemy->IncreareCurrentHp(target_enemy->GetCurrentPower()); //Power値を使用

		anim_mgr_.GetAnim()[0]->SetObjPosToSquarePos(target_enemy->GetUnitSquarePos().row, target_enemy->GetUnitSquarePos().col);
		anim_mgr_.GetAnim()[0]->CardAnimPlay("anim_heal");

		sound_mgr_.PlayCardSE(12);
	}


}

bool HealPopoBehavior::IsAllyActInRange(UnitEnemy* turn_enemy, Board* board) {

	SquarePos directions[] = { {-2, 0}, {2, 0}, {0, -2}, {0, 2} };
	SquarePos enemy_pos = turn_enemy->GetUnitSquarePos();

	for (auto dir : directions) {
		SquarePos check_pos = { enemy_pos.row + dir.row, enemy_pos.col + dir.col };

		if (check_pos.row >= 0 && check_pos.row < 10 && check_pos.col >= 0 && check_pos.col < 10) {

			for (auto ally : board->GetEnemyUnitsInBoard()) {
				if (ally->GetUnitSquarePos().row == check_pos.row && ally->GetUnitSquarePos().col == check_pos.col) {
					return true;
				}
			}
		}
	}

	return false;

}

bool HealPopoBehavior::IsAllyAdjacent(UnitEnemy* turn_enemy, Board* board) {

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
