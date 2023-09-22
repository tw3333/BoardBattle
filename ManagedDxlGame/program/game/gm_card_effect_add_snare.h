#pragma once
#include "gm_card_effect.h"

class CardEffectAddSnare : public CardEffect {
public:

	CardEffectAddSnare(int card_id, int ref_num,int snare_turn_count) : CardEffect(card_id, ref_num) {
		snare_turn_count_ = snare_turn_count;
	}
	~CardEffectAddSnare() {}

	void Effect(std::vector<Unit*> untis) override;
	void EffectExcute(std::vector<SquarePos> target_square_pos, Board* board) override;
	bool CanEffectExcute(std::vector<SquarePos> target_square_pos, Board* board) override;


private:

	int snare_turn_count_ = 0;


};