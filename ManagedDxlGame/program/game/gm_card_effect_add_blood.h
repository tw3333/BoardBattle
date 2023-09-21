#pragma once
#include "gm_card_effect.h"

class CardEffectAddBlood : public CardEffect {
public:

	CardEffectAddBlood(int ref_num) : CardEffect(ref_num) {}
	~CardEffectAddBlood(){}

	void Effect(std::vector<Unit*> units) override;
	bool CanEffectExcute(std::vector<SquarePos> range_square_pos, Board* board) override;
	void EffectExcute(std::vector<SquarePos> target_square_pos, Board* board) override;




private:



};