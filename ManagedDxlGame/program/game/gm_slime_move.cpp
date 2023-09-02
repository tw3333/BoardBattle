#include "gm_slime_move.h"

#include "gm_unit.h"
#include "gm_unit_ally.h"
#include "gm_unit_enemy.h"
#include "gm_board.h"
#include "gm_data_board.h"


void SlimeMove::Move(UnitEnemy* turn_enemy, Board* board) {

	//
    if (IsAllyAdjacent(turn_enemy,board)) {
        return;
    }














}

bool SlimeMove::IsAllyAdjacent(UnitEnemy* turn_enemy, Board* board) {

    // 上下左右の方向ベクトル
    std::vector<SquarePos> directions = {
        {0, 1},  // 右
        {0, -1}, // 左
        {1, 0},  // 下
        {-1, 0}  // 上
    };

    for (const auto& dir : directions) {
        SquarePos adjacentPos = { turn_enemy->GetUnitSquarePos().row + dir.row, turn_enemy->GetUnitSquarePos().col + dir.col};

        // Allyがその位置にいるか確認
        for (auto ally : board->GetPartyUnits()) {
            if (ally->GetUnitSquarePos().row == adjacentPos.row && ally->GetUnitSquarePos().col == adjacentPos.col) {
                return true;  // 上下左右にAllyがいる
            }
        }
    }

    return false;
}
