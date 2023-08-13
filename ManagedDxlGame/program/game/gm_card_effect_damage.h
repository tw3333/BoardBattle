#pragma once
#include "gm_card_effect.h"


//memo
//damage�̐��l�������_���[�W��^����

class CardEffectDamage : public CardEffect {
public:

	CardEffectDamage(int damage) : damage_(damage) {}


	void Effect(std::vector<Unit*> units) override;



private:

	int damage_;

};