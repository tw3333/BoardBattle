#pragma once
#include "gm_card_range.h"



class CardRangeDown : public CardRange {
public:

	CardRangeDown(int leave, int range) : leave_(leave), range_(range){}
	~CardRangeDown(){}


	void DisplayRange(UnitAlly* act_ally, Board* board) override;
	std::vector<Unit*> GetUnitInRange(UnitAlly* act_ally, std::vector<Unit*> all_units) override;



private:

	int leave_ = 0;
	int range_ = 0;



};
