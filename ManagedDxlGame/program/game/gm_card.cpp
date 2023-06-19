#include "gm_card.h"
#include "gm_unit_ally.h"
#include "gm_unit_enemy.h"
#include "gm_board.h"



void Card::DisplayRange(UnitAlly* turn_ally, Board* board) {

	int ally_row = turn_ally->GetBoardPos().row;
	int ally_col = turn_ally->GetBoardPos().col;

	
	if (range_type_a_ == RangeTypeA::None) {

		if (range_type_b_ == RangeTypeB::OnlyRight) {

			board->getBoardSquare(ally_row + range_num_, ally_col)->getObj()->parts_[ObjSquare::RangeTile]->is_render_ = true;

		}

	}

}
