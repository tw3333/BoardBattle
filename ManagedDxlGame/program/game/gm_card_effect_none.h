#pragma once
#include "gm_card_effect.h"


//Debug�p�A�����N�����Ȃ�


class CardEffectNone : public CardEffect {
public:

	CardEffectNone(int ref_num) : CardEffect(ref_num) {}
	~CardEffectNone() {}

	void Effect(std::vector<Unit*> units) override;
	bool CanEffectExcute(std::vector<SquarePos> range_square_pos, Board* board) override;
	void EffectExcute(std::vector<SquarePos> target_square_pos, Board* board) override;




private:





};