#pragma once
#include <vector>

class Unit;
class UnitAlly;
class Board;

//memo
//�J�[�h�̎˒��̕\���A�܂��͈͓��ɂ���Unit���w�肷��

//�ǂ����ΏۂƂ��邩
enum class Target{
	Ally,
	Enemy,
	All
};

class CardRange {
public:

	virtual void DisplayRange(UnitAlly* act_ally, Board* board) = 0;
	virtual std::vector<Unit*> GetUnitInRange(UnitAlly* act_ally, std::vector<Unit*> all_units) = 0;
	virtual std::vector<SquarePos> GetRangeSquarePos() = 0;

	bool GetIsUnitInRange() { return is_unit_in_range_; }


protected:

	Target target_;
	bool is_unit_in_range_ = false;


	std::vector<SquarePos> range_square_pos_;
};