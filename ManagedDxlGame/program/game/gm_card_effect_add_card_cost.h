#pragma once
#include "gm_card_effect.h"

class CardEffectAddCardCost : public CardEffect {
public:

	CardEffectAddCardCost(int card_id, int ref_num, int add_card_cost)
	: CardEffect(card_id, ref_num), add_card_cost_(add_card_cost) {}
	~CardEffectAddCardCost(){}

	void Effect(std::vector<Unit*> units) override;
	bool CanEffectExcute(std::vector<SquarePos> range_square_pos, Board* board) override;
	void EffectExcute(std::vector<SquarePos> target_square_pos, Board* board) override;


private:

	int add_card_cost_ = 0;



};