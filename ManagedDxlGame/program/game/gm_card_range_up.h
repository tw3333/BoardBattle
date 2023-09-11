#pragma once
#include "gm_card_range.h"


//memo
//”­“®‚·‚éUnit‚©‚çŒvZ‚µ‚ÄA



class CardRangeUp : public CardRange {
public:

	CardRangeUp(int leave, int range_, Target target)
	:leave_(leave), range_(range_)
	{}
	~CardRangeUp(){}

	void DisplayRange(UnitAlly* act_allly, Board* board) override;
	std::vector<Unit*> GetUnitInRange(UnitAlly* act_ally, std::vector<Unit*> all_units) override;

	std::vector<SquarePos> GetRangeSquarePos(SquarePos axis_pos) override;



private:


	int leave_ = 0;
	int range_ = 0;





};
