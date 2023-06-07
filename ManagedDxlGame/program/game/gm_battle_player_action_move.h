#pragma once
#include <array>
#include <cmath> // for std::abs
#include <cstdlib> // for std::abs
#include <algorithm> // for other algorithmic functions

#include "gm_square.h"
#include "gm_unit_ally.h"


class PlayerActionMove {
public:

	PlayerActionMove(const std::array<std::array<Square*, 10>, 10> board_squares){
		board_squares_ = board_squares;
	}
	~PlayerActionMove(){}


	void Update(float delta_time);


	void SetTurnAlly(UnitAlly* unit_ally) { turn_ally_ = unit_ally; }
	void SetIsEnabled(bool flag) { is_enabled_ = flag; }

	void DisplayMoveRange(UnitAlly* unit);


private:

	bool is_enabled_ = false;
	UnitAlly* turn_ally_ = nullptr;

	std::array<std::array<Square*, 10>, 10> board_squares_;



};