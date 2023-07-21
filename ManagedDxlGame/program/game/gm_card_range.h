#pragma once
#include <vector>

class Unit;
class UnitAlly;
class Board;

//memo
//カードの射程の表示、また範囲内にいるUnitを指定する

//どちらを対象とするか
enum class Target{
	Ally,
	Enemy,
	All
};

class CardRange {
public:

	virtual void DisplayRange(UnitAlly* act_ally, Board* board) = 0;
	virtual std::vector<Unit*> GetUnitInRange(UnitAlly* act_ally, std::vector<Unit*> all_units) = 0;




protected:

	Target target_;



};