#pragma once
#include "gm_card_effect.h"

//memo
//������n�}�X���������o���Ƃ�������

class CardEffectPushOut : public CardEffect {
public:

	CardEffectPushOut(int ref_num,int push_num) : CardEffect(ref_num) {
		push_num_ = push_num;
	}
	~CardEffectPushOut() {}

	void Effect(std::vector<Unit*> untis) override;
	void EffectExcute(std::vector<SquarePos> target_square_pos, Board* board) override;
	bool CanEffectExcute(std::vector<SquarePos> target_square_pos, Board* board) override;



private:

	int push_num_ = 0; //���̐��l�����������o��


};