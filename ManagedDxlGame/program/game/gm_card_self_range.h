#pragma once
#include "gm_card_range.h"

//memo
//自身を指定する

class CardSelfRange : public CardRange {
public:

	CardSelfRange() {}
	~CardSelfRange() {}

	void Range(Card* card, UnitAlly* act_ally, Board* board) override;



private:





};