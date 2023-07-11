#pragma once
#include <vector>

//memo
//Cardのrangeを作成する基底クラス

class Unit;
class UnitAlly;
class Board;

//memo
//カードの射程の表示、また範囲内にいるUnitを指定する


class CardRange {
public:

	virtual void DisplayRange(UnitAlly* act_ally, Board* board);
	virtual std::vector<Unit*> GetUnitInRange(UnitAlly* act_ally, std::vector<Unit*> all_units);

protected:

	bool is_specify_target_ = false;
	int target_num_ = 0;




};