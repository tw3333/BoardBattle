#include "gm_card_range_right.h"


#include "gm_board.h"
#include "gm_unit.h"
#include "gm_unit_ally.h"


void CardRangeRight::DisplayRange(UnitAlly* act_ally, Board* board) {

	for (int i = 1; i <= range_; ++i) {

		int display_tile_row = act_ally->GetBoardPos().row;
		int display_tile_col = act_ally->GetBoardPos().col + leave_ + i;

		if (0 <= display_tile_row && display_tile_row <= 9) {

			board->getBoardSquare(display_tile_row, display_tile_col)->SetRenderRangeTile(true);


		}

	}
	


}

std::vector<Unit*> CardRangeRight::GetUnitInRange(UnitAlly* act_ally, std::vector<Unit*> all_units) {




	return std::vector<Unit*>();
}
