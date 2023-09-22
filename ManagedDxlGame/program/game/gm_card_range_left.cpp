#include "gm_card_range.h"
#include "gm_card_range_left.h"

#include "gm_board.h"
#include "gm_unit.h"
#include "gm_unit_ally.h"

void CardRangeLeft::DisplayRange(UnitAlly* act_ally, Board* board) {

	for (int i = 1; i <= range_; ++i) {

		int display_tile_row = act_ally->GetUnitSquarePos().row;
		int display_tile_col = act_ally->GetUnitSquarePos().col - leave_ - i;

		if (0 <= display_tile_col && display_tile_col <= 9) {

			board->getBoardSquare(display_tile_row, display_tile_col)->SetRenderRangeTile(true);

		}

	}


}

std::vector<Unit*> CardRangeLeft::GetUnitInRange(UnitAlly* act_ally, std::vector<Unit*> all_units) {

	std::vector<Unit*> range_units;

	for (int i = 1; i <= range_; ++i) {

		int range_row = act_ally->GetUnitSquarePos().row;
		int range_col = act_ally->GetUnitSquarePos().col - leave_ - i;

		if (0 <= range_row && range_row <= 9) {

			if (target_ == Target::Ally) {

				for (auto u : all_units) {
					if (u->GetUnitType() == UnitType::Ally
						&& u->GetUnitSquarePos().row == range_row && u->GetUnitSquarePos().col == range_col) {

						is_unit_in_range_ = true;
						range_units.push_back(u);
					}
					else {
						is_unit_in_range_ = false;
					}
				}
			}
			else if (target_ == Target::Enemy) {

				for (auto u : all_units) {
					if (u->GetUnitType() == UnitType::Enemy && u->GetUnitSquarePos().row == range_row && u->GetUnitSquarePos().col == range_col) {

						is_unit_in_range_ = true;
						range_units.push_back(u);
					}
					else {
						is_unit_in_range_ = false;
					}
				}
			}
			else if (target_ == Target::All) {

				for (auto unit : all_units) {

					if (unit->GetUnitSquarePos().row == range_row && unit->GetUnitSquarePos().col == range_col) {

						is_unit_in_range_ = true;
						range_units.push_back(unit);
					}
					else {
						is_unit_in_range_ = false;
					}
				}
			}

		}

	}

	
	return range_units;
}

std::vector<SquarePos> CardRangeLeft::GetRangeSquarePos(SquarePos axis_pos) {

	std::vector<SquarePos> range_square_pos;

	for (int i = 1; i <= range_; ++i) {

		int range_row = axis_pos.row;
		int range_col = axis_pos.col - leave_ - i;

		if (0 <= range_col && range_col <= 9) {

			range_square_pos.emplace_back(SquarePos(range_row, range_col));

		}

	}

	return range_square_pos;
}
