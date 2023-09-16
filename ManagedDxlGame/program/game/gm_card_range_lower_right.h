#pragma once
#include "gm_card_range.h"



class CardRangeLowerRight : public CardRange {
public:

	CardRangeLowerRight(int leave, int range)
	:leave_(leave), range_(range)
	{}
	~CardRangeLowerRight(){}

	void DisplayRange(UnitAlly* act_ally, Board* board) override;
	std::vector<Unit*> GetUnitInRange(UnitAlly* act_ally, std::vector<Unit*> all_units) override;
	std::vector<SquarePos> GetRangeSquarePos(SquarePos axis_pos) override;


private:

	int leave_ = 0;
	int range_ = 0;

	const int init_leave_ = 0;
	const int init_range_ = 0;

};