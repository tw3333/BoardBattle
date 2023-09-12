#include "gm_card_effect_move.h"

#include "gm_board.h"
#include "gm_unit_ally.h"

void CardEffectMove::Effect(std::vector<Unit*> units)
{
}

bool CardEffectMove::CanEffectExcute(std::vector<SquarePos> range_square_pos, Board* board) {

	for (auto square : range_square_pos) {

		if (!board->getBoardSquare(square.row, square.col)->GetIsCanMove()) {
			return false;
		}
		
	}

	return true;
}

void CardEffectMove::EffectExcute(std::vector<SquarePos> target_square_pos, Board* board) {

	for (auto unit : board->GetPartyUnitsInBoard()) {

		if (unit->GetIsTurn()) {

			unit->SetUnitSquarePos(target_square_pos[0].row,target_square_pos[0].col);

		}

	}

}