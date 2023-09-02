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

    // �㉺���E�̕����x�N�g��
    std::vector<SquarePos> directions = {
        {0, 1},  // �E
        {0, -1}, // ��
        {1, 0},  // ��
        {-1, 0}  // ��
    };

    for (const auto& dir : directions) {
        SquarePos adjacentPos = { turn_enemy->GetUnitSquarePos().row + dir.row, turn_enemy->GetUnitSquarePos().col + dir.col};

        // Ally�����̈ʒu�ɂ��邩�m�F
        for (auto ally : board->GetPartyUnits()) {
            if (ally->GetUnitSquarePos().row == adjacentPos.row && ally->GetUnitSquarePos().col == adjacentPos.col) {
                return true;  // �㉺���E��Ally������
            }
        }
    }

    return false;
}
