#pragma once
#include "gm_card_effect.h"

class CardEffectAddTaunt : public CardEffect {
public:

	CardEffectAddTaunt(int add_taunt_value) : add_taunt_value_(add_taunt_value){}
	~CardEffectAddTaunt();

	void Effect(std::vector<Unit*> untis) override;



private:

	int add_taunt_value_ = 0;



};