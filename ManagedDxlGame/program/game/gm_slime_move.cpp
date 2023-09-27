#include "gm_slime_move.h"

#include <vector>
#include <cstdlib> // std::rand, std::srand
#include <ctime> // std::time
#include <climits> // INT_MAX
#include <cmath> // std::abs
#include <algorithm> // std::shuffle
#include <queue>

#include "gm_unit.h"
#include "gm_unit_ally.h"
#include "gm_unit_enemy.h"
#include "gm_board.h"
#include "gm_data_board.h"
#include <set>


void SlimeMove::Move(UnitEnemy* turn_enemy, Board* board) {

    if (IsAllyAdjacent(turn_enemy, board)) {
        return;
    }

    std::vector<UnitAlly*> nearest_allies;
    int min_distance = INT_MAX;

    for (auto ally : board->GetPartyUnits()) {
        int distance = std::abs(turn_enemy->GetUnitSquarePos().row - ally->GetUnitSquarePos().row)
            + std::abs(turn_enemy->GetUnitSquarePos().col - ally->GetUnitSquarePos().col);

        if (distance < min_distance) {
            nearest_allies.clear();
            nearest_allies.push_back(ally);
            min_distance = distance;
        }
        else if (distance == min_distance) {
            nearest_allies.push_back(ally);
        }
    }

    std::uniform_int_distribution<int> dist(0, nearest_allies.size() - 1);
    UnitAlly* target_ally = nearest_allies[dist(rng)];

    SquarePos start = turn_enemy->GetUnitSquarePos();
    SquarePos target_pos = target_ally->GetUnitSquarePos(); 
    final_pos_ = start;
    target_pos_ = target_pos;

    // BFSのためのデータ構造
    SquarePos directions[] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    std::vector<std::vector<bool>> visited(10, std::vector<bool>(10, false));
    std::queue<std::pair<SquarePos, int>> q;
    SquarePos startPos = turn_enemy->GetUnitSquarePos();
    SquarePos targetPos = target_ally->GetUnitSquarePos();

    //qの生成
    q.push({ startPos, turn_enemy->GetCurrentMoveCost() });
    visited[startPos.row][startPos.col] = true;

    SquarePos nextPos = startPos;

    while (!q.empty()) {
        SquarePos currPos = q.front().first;
        int remainingMove = q.front().second;
        q.pop();

        for (SquarePos dir : directions) {
            SquarePos adjPos = { currPos.row + dir.row, currPos.col + dir.col };

            if (adjPos.row >= 0 && adjPos.row < 10 && adjPos.col >= 0 && adjPos.col < 10 && !visited[adjPos.row][adjPos.col] && board->getBoardSquares()[adjPos.row][adjPos.col]->GetIsCanMove()) {
                
                //隣り合った場合探索終了
                if (std::abs(adjPos.row - targetPos.row) + std::abs(adjPos.col - targetPos.col) == 1 && remainingMove > 0) {
                    nextPos = adjPos;
                    break;
                }
                if (remainingMove > 1) {
                    q.push({ adjPos, remainingMove - 1 });
                    visited[adjPos.row][adjPos.col] = true;
                }
            }
        }
    }

    // Update slime's position
    turn_enemy->SetUnitSquarePos(nextPos.row, nextPos.col);

}

bool SlimeMove::IsAllyAdjacent(UnitEnemy* turn_enemy, Board* board) {

    SquarePos directions[] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    SquarePos enemy_pos = turn_enemy->GetUnitSquarePos();

    for (auto dir : directions) {
        SquarePos check_pos = { enemy_pos.row + dir.row, enemy_pos.col + dir.col };

        if (check_pos.row >= 0 && check_pos.row < 10 && check_pos.col >= 0 && check_pos.col < 10) {
                
            for (auto ally : board->GetPartyUnits()) {
                if (ally->GetUnitSquarePos().row == check_pos.row && ally->GetUnitSquarePos().col == check_pos.col) {
					return true;
				}
			}
        }
    }

    return false;
}

//void SlimeMove::Move(UnitEnemy* turn_enemy, Board* board) {
//
//    //隣り合っていたら移動しない
//    if (IsAllyAdjacent(turn_enemy, board)) {
//        return;
//    }
//
//    //隣り合ってない場合
//    //targetなるallyを取得
//    UnitAlly* target_ally = nullptr;
//    std::vector<UnitAlly*> candidate_target_ally;
//    int min_distance = INT_MAX;
//    int max_taunt = INT_MIN;
//
//    for (auto ally : board->GetPartyUnits()) {
//
//        int distance = std::abs(turn_enemy->GetUnitSquarePos().row - ally->GetUnitSquarePos().row) + std::abs(turn_enemy->GetUnitSquarePos().col - ally->GetUnitSquarePos().col);
//
//        if (ally->GetTauntValue() > max_taunt || (ally->GetTauntValue() == max_taunt && distance < min_distance)) {
//            candidate_target_ally.clear();
//            candidate_target_ally.push_back(ally);
//            min_distance = distance;
//            max_taunt = ally->GetTauntValue();
//        }
//        else if (ally->GetTauntValue() == max_taunt && distance == min_distance) {
//            candidate_target_ally.push_back(ally);
//        }
//    }
//
//    //taunt値が同じAllyがいる場合、ランダムに1体選択
//    std::srand(std::time(nullptr));
//    int randomIndex = std::rand() % candidate_target_ally.size();
//    target_ally = candidate_target_ally[randomIndex];
//
//
//    //Targetに移動(BTS探索使用)
//    std::vector<std::vector<bool>> visited(10, std::vector<bool>(10, false));
//    std::queue<std::pair<SquarePos, int>> q;
//    SquarePos directions[] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} }; //上下左右の方向ベクトル
//
//    int remaining_move = turn_enemy->GetCurrentMoveCost();
//    SquarePos final_pos = turn_enemy->GetUnitSquarePos();
//    SquarePos nearest_target_pos = final_pos;
//
//
//
//    int nearest_distance = INT_MAX;
//
//    q.push({ turn_enemy->GetUnitSquarePos(), remaining_move });
//
//    while (!q.empty()) {
//        SquarePos cur = q.front().first;
//        remaining_move = q.front().second;
//        q.pop();
//
//        if (visited[cur.row][cur.col] || !board->getBoardSquares()[cur.row][cur.col]->GetIsCanMove()) {
//            continue;
//        }
//
//        visited[cur.row][cur.col] = true;
//
//        int distance_to_target = std::abs(cur.row - target_ally->GetUnitSquarePos().row)
//            + std::abs(cur.col - target_ally->GetUnitSquarePos().col);
//
//        if (distance_to_target == 1 && remaining_move >= 0) {
//            nearest_target_pos = cur;
//            nearest_distance = 0;
//            break;
//        }
//
//        if (remaining_move == 0 && distance_to_target < nearest_distance) {
//            nearest_distance = distance_to_target;
//            nearest_target_pos = cur;
//        }
//
//        ////Allyに隣り合った場合移動終了
//        //if (std::abs(cur.row - target_ally->GetUnitSquarePos().row) + std::abs(cur.col - target_ally->GetUnitSquarePos().col) == 1) {
//        //    //turn_enemy->SetUnitSquarePos(cur.row, cur.col);
//        //    final_pos = cur;
//        //    break;
//        //}
//
//
//        for (SquarePos dir : directions) {
//            SquarePos next = { cur.row + dir.row, cur.col + dir.col };
//            if (next.row >= 0 && next.row < 10 && next.col >= 0 && next.col < 10) {
//                if (!visited[next.row][next.col] && remaining_move - 1 >= 0) {
//                    q.push({ next, remaining_move - 1 });
//                }
//            }
//        }
//
//    }
//
//    if (nearest_distance <= remaining_move) {
//        final_pos = nearest_target_pos;
//    }
//
//    turn_enemy->SetUnitSquarePos(final_pos.row, final_pos.col);
//    //turn_enemy->SetUnitSquarePos(1, 1);
//
//}

//bool SlimeMove::IsAllyAdjacent(UnitEnemy* turn_enemy, Board* board) {
//
//    // 上下左右の方向ベクトル
//    std::vector<SquarePos> directions = {
//        {0, 1},  // 右
//        {0, -1}, // 左
//        {1, 0},  // 下
//        {-1, 0}  // 上
//    };
//
//    for (const auto& dir : directions) {
//        SquarePos adjacentPos = { turn_enemy->GetUnitSquarePos().row + dir.row, turn_enemy->GetUnitSquarePos().col + dir.col };
//
//        // Allyがその位置にいるか確認
//        for (auto ally : board->GetPartyUnits()) {
//            if (ally->GetUnitSquarePos().row == adjacentPos.row && ally->GetUnitSquarePos().col == adjacentPos.col) {
//
//
//                return true;  // 上下左右にAllyがいる
//            }
//        }
//    }
//
//    return false;
//}