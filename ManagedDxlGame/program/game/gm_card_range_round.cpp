#include "gm_card_range_round.h"

void CardRangeRound::DisplayRange(UnitAlly* act_ally, Board* board)
{
}

std::vector<Unit*> CardRangeRound::GetUnitInRange(UnitAlly* act_ally, std::vector<Unit*> all_units)
{
	return std::vector<Unit*>();
}

std::vector<SquarePos> CardRangeRound::GetRangeSquarePos(SquarePos axis_pos)
{
    std::vector<SquarePos> range_square_pos;

    for (int i = -range_ - leave_; i <= range_ + leave_; ++i) {
        for (int j = -range_ - leave_; j <= range_ + leave_; ++j) {

            // 軸を中心とした現在のマス位置を計算
            int range_row = axis_pos.row + i;
            int range_col = axis_pos.col + j;

            // leave_ の範囲外、かつ range_ の範囲内のマスだけを取得
            if ((std::abs(i) > leave_ && std::abs(i) <= range_ + leave_) ||
                (std::abs(j) > leave_ && std::abs(j) <= range_ + leave_)) {
                if (0 <= range_row && range_row <= 9 && 0 <= range_col && range_col <= 9) {
                    range_square_pos.emplace_back(SquarePos(range_row, range_col));
                }
            }
        }
    }

    return range_square_pos;
}
