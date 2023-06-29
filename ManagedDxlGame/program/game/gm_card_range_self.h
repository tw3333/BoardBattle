#pragma once
#include "gm_card_range.h"


class SelfRange : public CardRange{
public:



	void DisplayRange(UnitAlly* act_ally, Board* board) override;
	std::vector<Unit*> GetUnitInRange(UnitAlly* act_ally, std::vector<Unit*> all_units) override;

};