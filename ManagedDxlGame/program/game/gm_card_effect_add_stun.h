#pragma once
#include "gm_card_effect.h"

class CardEffectAddStun : public CardEffect {
public:

	CardEffectAddStun(int ref_num) :CardEffect(ref_num){}
	~CardEffectAddStun(){}

	void Effect(std::vector<Unit*> untis) override;
	void EffectExcute(std::vector<SquarePos> target_square_pos, Board* board) override;
	bool CanEffectExcute(std::vector<SquarePos> target_square_pos, Board* board) override;


private:



};