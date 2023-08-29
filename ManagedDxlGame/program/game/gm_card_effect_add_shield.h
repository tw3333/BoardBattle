#pragma once
#include "gm_card_effect.h"

class CardEffectAddShield : public CardEffect {
public:

	CardEffectAddShield(int ref_num, int add_shield_value) 
	: add_shield_value_(add_shield_value), CardEffect(ref_num){}
	~CardEffectAddShield(){}

	void Effect(std::vector<Unit*> units) override;
	bool CanEffectExcute(std::vector<SquarePos> range_square_pos, Board* board) override;
	void EffectExcute(std::vector<SquarePos> target_square_pos, Board* board) override;



private:

	int add_shield_value_ = 0;


};