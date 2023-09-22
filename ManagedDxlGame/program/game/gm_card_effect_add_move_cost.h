#pragma once
#include "gm_card_effect.h"

class CardEffectAddMoveCost : public CardEffect {
public:

	CardEffectAddMoveCost(int card_id, int ref_num, int add_move_cost) : CardEffect(card_id, ref_num) {
		add_move_cost_ = add_move_cost;
	}
	~CardEffectAddMoveCost(){}
	
	void Effect(std::vector<Unit*> units) override;
	bool CanEffectExcute(std::vector<SquarePos> range_square_pos, Board* board) override;
	void EffectExcute(std::vector<SquarePos> target_square_pos, Board* board) override;

private:

	int add_move_cost_ = 0;



};