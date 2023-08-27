#pragma once
#include <vector>

#include "gm_data_board.h"

class Unit;
class UnitAlly;
class Board;

//memo
//カードの射程の表示、また範囲内にいるUnitを指定する

//どちらを対象とする
enum class Target{
	Ally,
	Enemy,
	All
};

//どこを軸にするか
enum class RangeAxis {
	ActAlly,
	SelectSquare
};


class CardRange {
public:

	virtual void DisplayRange(UnitAlly* act_ally, Board* board) = 0;
	virtual std::vector<Unit*> GetUnitInRange(UnitAlly* act_ally, std::vector<Unit*> all_units) = 0;
	_axis_pos) = 0; //範囲のマスの座標を返す

	bool GetIsUnitInRange() { return is_unit_in_range_; }
	std::vector<SquarePos> GetTargetSquarePos() { return range_square_pos_; }


protected:

	Target target_;

	RangeAxis axis_;
	bool is_unit_in_range_ = false;


	std::vector<SquarePos> range_square_pos_;
};