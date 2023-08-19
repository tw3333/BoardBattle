#pragma once
#include "gm_card_effect.h"


//memo
//damage�̐��l�������_���[�W��^����

class CardEffectDamage : public CardEffect {
public:

	
	CardEffectDamage(int ref_num, int damage) 
	: damage_(damage), CardEffect(ref_num) {}


	void Effect(std::vector<Unit*> units) override;



private:

	int damage_ = 0;



};