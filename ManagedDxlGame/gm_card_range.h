#pragma once
#include <vector>

//memo
//Card��range���쐬������N���X

class Unit;
class UnitAlly;
class Board;

class CardRange {
public:

	virtual void DisplayRange(UnitAlly* act_ally, Board* board);
	virtual std::vector<Unit*> GetUnitInRange(UnitAlly* act_ally, std::vector<Unit*> all_units);



};