#pragma once
#include <vector>

//memo
//Cardのrangeを作成する基底クラス

class Unit;
class UnitAlly;

class CardRange {
public:

	virtual std::vector<Unit*> GetUnitInRange(UnitAlly* act_ally, std::vector<Unit*> all_units);



};