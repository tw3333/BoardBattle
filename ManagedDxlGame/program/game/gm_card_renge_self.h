#include "gm_card_range.h"

class Unit;
class UnitAlly;
class Board;

class CardRangeSelf : public CardRange {
public:

	CardRangeSelf(){}
	~CardRangeSelf(){}

	void DisplayRange(UnitAlly* act_ally, Board* board) override;
	std::vector<Unit*> GetUnitInRange(UnitAlly* act_ally, std::vector<Unit*> all_units) override;

};