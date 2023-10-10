#include "gm_card_effect_passing_damage.h"

#include "gm_board.h"
#include "gm_unit.h"
#include "gm_unit_ally.h"
#include "gm_unit_enemy.h"


void CardEffectPassingDamage::Effect(std::vector<Unit*> untis)
{
}

void CardEffectPassingDamage::EffectExcute(std::vector<SquarePos> target_square_pos, Board* board) {


    SquarePos turn_ally_pos; // ”­“®Œ³‚ÌAlly‚ÌˆÊ’u
    SquarePos pass_ally_pos = target_square_pos[0]; // ˆÚ“®‚·‚éAlly‚ÌˆÊ’u

    for (auto ally : board->GetPartyUnitsInBoard()) {
        if (ally->GetIsTurn()) {
            turn_ally_pos = ally->GetUnitSquarePos();

            // ˆÚ“®ˆ—
            ally->SetUnitSquarePos(target_square_pos[0].row, target_square_pos[0].col);
        }
    }

    int row_s = turn_ally_pos.row;
    int row_e = pass_ally_pos.row;
    int col_s = turn_ally_pos.col;
    int col_e = pass_ally_pos.col;

    if (row_s > row_e) {
        std::swap(row_s, row_e);
    }

    if (col_s > col_e) {
        std::swap(col_s, col_e);
    }


    for (auto enemy : board->GetEnemyUnitsInBoard()) {
        if ((enemy->GetUnitSquarePos().row >= row_s && enemy->GetUnitSquarePos().row <= row_e)
            && (enemy->GetUnitSquarePos().col >= col_s && enemy->GetUnitSquarePos().col <= col_e)) {
            enemy->DecreaseCurrentHp(damage_);
        }
    }

}

bool CardEffectPassingDamage::CanEffectExcute(std::vector<SquarePos> target_square_pos, Board* board) {	

	for (auto square : target_square_pos) {

		if (!board->getBoardSquare(square.row, square.col)->GetIsCanMove()) {
			return false;
		}

	}

	return true;
}
