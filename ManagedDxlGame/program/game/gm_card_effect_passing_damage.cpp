#include "gm_card_effect_passing_damage.h"

#include "gm_board.h"
#include "gm_unit.h"
#include "gm_unit_ally.h"
#include "gm_unit_enemy.h"


void CardEffectPassingDamage::Effect(std::vector<Unit*> untis)
{
}

void CardEffectPassingDamage::EffectExcute(std::vector<SquarePos> target_square_pos, Board* board) {

	SquarePos turn_ally_pos;
	SquarePos pass_ally_pos;
	
	for (auto ally : board->GetPartyUnitsInBoard()) {

		if (ally->GetIsTurn()) {
			turn_ally_pos = ally->GetUnitSquarePos();
		}
	}

	//ˆÚ“®ˆ—
	for (auto square : target_square_pos) {

		board->getBoardSquare(turn_ally_pos.row, turn_ally_pos.col)->GetAllyPtrInSquare()->SetUnitSquarePos(square.row, square.col);

	}

	//’Ê‰ßDamageˆ—
	for (auto square : target_square_pos) {
		pass_ally_pos = square;
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

	row_s += (row_e - row_s) != 0 ? 1 : 0;
	col_s += (col_e - col_s) != 0 ? 1 : 0;
	row_e += (row_e - row_s) != 0 ? 1 : 0;
	col_e += (row_e - col_s) != 0 ? 1 : 0;

	for (auto enemy: board->GetEnemyUnitsInBoard()) {

		if ((enemy->GetUnitSquarePos().row > row_s && enemy->GetUnitSquarePos().row < row_e)
			&& (enemy->GetUnitSquarePos().col > col_s && enemy->GetUnitSquarePos().col < col_e))
		{
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
