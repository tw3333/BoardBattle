#pragma once
#include "gm_card_effect.h"

class CardEffectAddShield : public CardEffect {
public:

	CardEffectAddShield(int add_shield_value) : add_shield_value_(add_shield_value){}
	~CardEffectAddShield(){}

	void Effect(std::vector<Unit*> units) override;


private:

	int add_shield_value_ = 0;



};