#include "gm_card_range_lower_right.h"

void CardRangeLowerRight::DisplayRange(UnitAlly* act_ally, Board* board)
{
}

std::vector<Unit*> CardRangeLowerRight::GetUnitInRange(UnitAlly* act_ally, std::vector<Unit*> all_units)
{
	return std::vector<Unit*>();
}

std::vector<SquarePos> CardRangeLowerRight::GetRangeSquarePos(SquarePos axis_pos)
{
    std::vector<SquarePos> range_square_pos;

    for (int i = 1; i <= range_; ++i) {

        int range_row = axis_pos.row + leave_ + i;  // ‰º•ûŒü
        int range_col = axis_pos.col + leave_ + i;  // ‰E•ûŒü

        if (0 <= range_row && range_row <= 9 && 0 <= range_col && range_col <= 9) {

            range_square_pos.emplace_back(SquarePos(range_row, range_col));

        }
    }

    return range_square_pos;

}
