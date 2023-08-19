#pragma once
#include "gm_card_effect.h"


class CardEffectHeal : public CardEffect {
public:

	CardEffectHeal(int ref_num, int heal_amount) 
	: heal_amount_(heal_amount), CardEffect(ref_num){}
	~CardEffectHeal() {}

	void Effect(std::vector<Unit*> units) override;




private:

	int heal_amount_ = 0;




};