#pragma once
#include "gm_card_range.h"


class SelfRange : public CardRange{
public:

	std::vector<Unit*> GetUnitInRange(UnitAlly* act_ally, std::vector<Unit*> all_units) override;



};