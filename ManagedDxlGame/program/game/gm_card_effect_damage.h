#pragma once
#include "gm_card_effect.h"


//memo
//damageの数値分だけダメージを与える

class CardEffectDamage : public CardEffect {
public:

	
	CardEffectDamage(int ref_num, int damage) 
	: damage_(damage), CardEffect(ref_num) {}


	void Effect(std::vector<Unit*> units) override;
	void EffectExcute(std::vector<SquarePos> target_square_pos, Board* board) override;
	bool CanEffectExcute(std::vector<SquarePos> target_square_pos, Board* board) override;


private:

	int damage_ = 0;



};