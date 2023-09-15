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
	
	for (auto ally : board->GetPartyUnitsInBoard()) {

		if (ally->GetIsTurn()) {
			turn_ally_pos = ally->GetUnitSquarePos();
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
