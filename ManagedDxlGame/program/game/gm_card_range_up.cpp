#include "gm_card_range_up.h"

#include "gm_square.h"
#include "gm_board.h"
#include "gm_unit.h"
#include "gm_unit_ally.h"


void CardRangeUP::DisplayRange(UnitAlly* act_ally, Board* board) {

	for (int i = 1; i <= range_; ++i) {

		int display_tile_row = act_ally->GetBoardPos().row - leave_ - i;
		int display_tile_col = act_ally->GetBoardPos().col;

		if (0 <= display_tile_row && display_tile_row <= 9) {

			board->getBoardSquare(display_tile_row, display_tile_col)->SetRenderRangeTile(true);


		}
		
	}

}

std::vector<Unit*> CardRangeUP::GetUnitInRange(UnitAlly* act_ally, std::vector<Unit*> all_units) {

	std::vector<Unit*> range_units;

	for (int i = 1; i <= range_; ++i) {

		int range_row = act_ally->GetBoardPos().row - leave_ - i;
		int range_col = act_ally->GetBoardPos().col;

		if (0 <= range_row && range_row <= 9) {

			for (auto unit : all_units) {

				if (unit->GetBoardPos().row == range_row && unit->GetBoardPos().col == range_col) {

					range_units.push_back(unit);

				}

			}

		}

	}

}
