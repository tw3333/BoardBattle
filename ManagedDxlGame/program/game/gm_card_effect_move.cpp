#include "gm_card_effect_move.h"

#include "gm_board.h"

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

	


}
