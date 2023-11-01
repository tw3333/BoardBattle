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
            //座標を更新
            turn_enemy->SetUnitSquarePos(best_direction.row, best_direction.col);
        }

        return;
    }

    //Range内にAllyがいない場合は一番近いAllyに近づく
    std::vector<UnitAlly*> nearest_allies;
    int min_distance = INT_MAX;

    for (auto ally : board->GetPartyUnitsInBoard()) {
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
    UnitAlly* target_ally = nearest_allies[dist(a_rng)];

    SquarePos start = turn_enemy->GetUnitSquarePos();
    SquarePos target_pos = target_ally->GetUnitSquarePos();
    final_pos_ = start;
    target_pos_ = target_pos;

    // BFSによる計算
    SquarePos directions[] = { {-2, 0}, {2, 0}, {0, -2}, {0, 2} };
    std::vector<std::vector<bool>> visited(10, std::vector<bool>(10, false));
    std::queue<std::pair<SquarePos, int>> q;
    SquarePos startPos = turn_enemy->GetUnitSquarePos();
    SquarePos targetPos = target_ally->GetUnitSquarePos();

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

}

void AttackPopoBehavior::Act(UnitEnemy* turn_enemy, Board* board) {

    //turn_enemyの位置を取得
    SquarePos turn_enemy_pos = turn_enemy->GetUnitSquarePos();

    //上下左右隣り合っているマスを取得
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
    std::vector<UnitAlly*> around_ally;
    
    for (auto &pos : around_pos) {
        if (board->getBoardSquare(pos.row, pos.col)->GetAllyPtrInSquare()) {
            around_ally.push_back(board->getBoardSquare(pos.row, pos.col)->GetAllyPtrInSquare());
        }
    }

    UnitAlly* target_ally = nullptr;

    //いなかったら終了
    if (around_ally.empty()) { return; }
    else if (!around_ally.empty()) {    //いる場合

        // taunt_ 値でソート
        std::sort(around_ally.begin(), around_ally.end(), [](UnitAlly* a, UnitAlly* b) {
            return a->GetTauntValue() < b->GetTauntValue();
        });

        // 最も高い taunt_ 値を持つ要素をすべて収集
        int highest_taunt = around_ally.back()->GetTauntValue();
        std::vector<UnitAlly*> highest_taunt_allies;
        std::copy_if(around_ally.begin(), around_ally.end(), std::back_inserter(highest_taunt_allies), [highest_taunt](UnitAlly* unit) {
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

        mgr.PlayCardSE(11);
        mgr.PlayAllyDamagedVoice(target_ally->GetAllyData()->GetAllyDataID());

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
