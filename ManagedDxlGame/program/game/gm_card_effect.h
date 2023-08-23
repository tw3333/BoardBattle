#pragma once
#include <vector>

class Unit;


class CardEffect {
public:

	CardEffect(int ref_num) : effect_ref_num_(ref_num) {}

	virtual void Effect(std::vector<Unit*> untis) = 0;
	//virtual void ExcuteEffect(std::vector<EffectBoardPos> effect_board_pos) = 0;
	
	//int effect_ref_num_ = 0;

	int GetEffectRefNum() { return effect_ref_num_; }

protected:

	int effect_ref_num_ = 0; //CardTargetとの参照番号


};