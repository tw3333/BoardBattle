#pragma once
#include "gm_card_range.h"


//memo
//”­“®‚·‚éUnit‚©‚çŒvZ‚µ‚ÄA



class CardRangeUP : public CardRange {
public:

	CardRangeUP(int leave, int range_, bool is_specify_target, int target_num)
	:leave_(leave), range_(range_)
	{
		is_specify_target_ = is_specify_target;
		target_num_ = target_num;
	}
	~CardRangeUP(){}

	void DisplayRange(UnitAlly* act_allly, Board* board) override;
	std::vector<Unit*> GetUnitInRange(UnitAlly* act_ally, std::vector<Unit*> all_units) override;





private:


	int leave_ = 0;
	int range_ = 0;





};
