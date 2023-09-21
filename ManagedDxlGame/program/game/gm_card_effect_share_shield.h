#pragma once
#include "gm_card_effect.h"

class CardEffectShareShield : public CardEffect {
public:

	CardEffectShareShield(int ref_num) : CardEffect(ref_num){}
	~CardEffectShareShield() {}

	void Effect(std::vector<Unit*> untis) override;
	void EffectExcute(std::vector<SquarePos> target_square_pos, Board* board) override;
	bool CanEffectExcute(std::vector<SquarePos> target_square_pos, Board* board) override;



private:




};