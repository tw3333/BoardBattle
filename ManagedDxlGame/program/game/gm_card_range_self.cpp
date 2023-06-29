#include "gm_card_range_self.h"

#include "program/game/gm_board.h"
#include "program/game/gm_unit.h"
#include "program/game/gm_unit_ally.h"


void SelfRange::DisplayRange(UnitAlly* act_ally, Board* board) {

	board->getBoardSquare(act_ally->GetBoardPos().row, act_ally->GetBoardPos().col)
		->getObj()->parts_[ObjSquare::RangeTile]->is_render_ = true;

	board->getBoardSquare(act_ally->GetBoardPos().row, act_ally->GetBoardPos().col)
		->getObj()->parts_[ObjSquare::CandidateTile]->is_render_ = true;


}

std::vector<Unit*> SelfRange::GetUnitInRange(UnitAlly* act_ally, std::vector<Unit*> all_units)
{

	std::vector<Unit*> range;

	range.push_back(act_ally);




	return range;
}

