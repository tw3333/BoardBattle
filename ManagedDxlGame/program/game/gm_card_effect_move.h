#pragma once
#include "gm_card_effect.h"


//memo
//�n���ꂽ�}�X�ڂɈړ�������

class CardEffectMove : public CardEffect {
public:

	CardEffectMove(int ref_num) : CardEffect(ref_num) {}
	~CardEffectMove() {}

	void Effect(std::vector<Unit*> units) override;
	bool CanEffectExcute(std::vector<SquarePos> range_square_pos, Board* board) override;
	void EffectExcute(std::vector<SquarePos> target_square_pos, Board* board) override;


private:




};