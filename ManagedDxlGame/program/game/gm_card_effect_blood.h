#pragma once
#include "gm_card_effect.h"

class CardEffectBlood : public CardEffect {
public:

	CardEffectBlood(int ref_num) : CardEffect(ref_num) {}
	~CardEffectBlood() {}

	//virtual CardEffect* CreateClone() = 0;

	void Effect(std::vector<Unit*> untis) override;
	void EffectExcute(std::vector<SquarePos> target_square_pos, Board* board) override;
	bool CanEffectExcute(std::vector<SquarePos> target_square_pos, Board* board) override;


private:




};