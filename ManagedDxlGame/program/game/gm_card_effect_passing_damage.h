#pragma once
#include "gm_card_effect.h"


//memo
//渡されたマス目に移動、その通過したマス目にいたUnitにダメージを与える
//今の仕様だと敵にダメージを与えることしかできなくなる
//つまり、これは特定のカードに依存している実装にしまっている
//a



class CardEffectPassingDamage : public CardEffect {
public:

	CardEffectPassingDamage(int card_id, int ref_num,int damage) : CardEffect(card_id, ref_num) {
		damage_ = damage;
	}
	~CardEffectPassingDamage() {}

	void Effect(std::vector<Unit*> untis) override;
	void EffectExcute(std::vector<SquarePos> target_square_pos, Board* board) override;
	bool CanEffectExcute(std::vector<SquarePos> target_square_pos, Board* board) override;



private:

	int damage_ = 0;

};