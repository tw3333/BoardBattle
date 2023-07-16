#pragma once
#include "gm_card_range.h"

class CardRangeLeft : public CardRange {
public:
	
	CardRangeLeft(int leave, int range_,Target target)
	: leave_(leave), range_(range_)
	{

		target_ = target;


	}
	~CardRangeLeft(){}

	void DisplayRange(UnitAlly* act_ally, Board* board) override;
	std::vector<Unit*> GetUnitInRange(UnitAlly* act_ally, std::vector<Unit*> all_units) override;



private:


	int leave_ = 0;
	int range_ = 0;


};