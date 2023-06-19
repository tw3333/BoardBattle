#pragma once
#include "gm_card_range.h"

#include <string>


class OnlySideRange : public CardRange {
public:

	OnlySideRange(int range_size, std::string side) : range_size_(range_size) {
		
		if (side == "Left") {
			side_ = Side::Left;
		}
		else if (side == "Right") {
			side_ = Side::Right;
		}
		else if (side == "Up") {
			side_ = Side::Up;
		}
		else if (side == "Down") {
			side_ = Side::Down;
		}
	
	}
	~OnlySideRange() {}

	void Range(Card* card, UnitAlly* act_ally, Board* board) override;

	enum class Side {
		Left,
		Right,
		Up,
		Down
	};
	

private:


	Side side_;
	int range_size_;
	

};