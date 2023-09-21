#pragma once
#include "gm_card_effect.h"

class CardEffectAddStun : public CardEffect {
public:

	CardEffectAddStun(int ref_num, int stun_turn_cnt) :CardEffect(ref_num){
		stun_turn_count_ = stun_turn_cnt;
	}
	~CardEffectAddStun(){}

	void Effect(std::vector<Unit*> untis) override;
	void EffectExcute(std::vector<SquarePos> target_square_pos, Board* board) override;
	bool CanEffectExcute(std::vector<SquarePos> target_square_pos, Board* board) override;


private:

	int stun_turn_count_ = 0;


};