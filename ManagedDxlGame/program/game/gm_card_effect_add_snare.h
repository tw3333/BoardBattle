#pragma once
#include "gm_card_effect.h"

class CardEffectAddSnare : public CardEffect {
public:

	CardEffectAddSnare(int ref_num) : CardEffect(ref_num) {}
	~CardEffectAddSnare() {}

	void Effect(std::vector<Unit*> untis) override;
	void EffectExcute(std::vector<SquarePos> target_square_pos, Board* board) override;
	bool CanEffectExcute(std::vector<SquarePos> target_square_pos, Board* board) override;


private:




};