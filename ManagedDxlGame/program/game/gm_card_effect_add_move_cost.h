#pragma once
#include "gm_card_effect.h"

class CardEffectAddMoveCost : public CardEffect {
public:

	CardEffectAddMoveCost(int ref_num, int add_card_cost_value) : CardEffect(ref_num) {
		add_card_cost_value_ = add_card_cost_value;
	}
	~CardEffectAddMoveCost(){}
	
	void Effect(std::vector<Unit*> units) override;
	bool CanEffectExcute(std::vector<SquarePos> range_square_pos, Board* board) override;
	void EffectExcute(std::vector<SquarePos> target_square_pos, Board* board) override;

private:

	int add_card_cost_value_ = 0;



};