#pragma once
#include "gm_card_effect.h"


//memo
//“n‚³‚ê‚½ƒ}ƒX–Ú‚ÉˆÚ“®‚³‚¹‚é

class CardEffectMove : public CardEffect {
public:

	CardEffectMove(int card_id, int ref_num) : CardEffect(card_id, ref_num) {}
	~CardEffectMove() {}

	void Effect(std::vector<Unit*> units) override;
	bool CanEffectExcute(std::vector<SquarePos> range_square_pos, Board* board) override;
	void EffectExcute(std::vector<SquarePos> target_square_pos, Board* board) override;


private:




};