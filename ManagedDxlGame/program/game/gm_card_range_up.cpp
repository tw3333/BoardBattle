#include "gm_card_range_up.h"

#include "gm_board.h"
#include "gm_unit_ally.h"


void CardRangeUP::DisplayRange(UnitAlly* act_ally, Board* board) {

	for (int i = 0; i < range_; ++i) {

		board->getBoardSquare(act_ally->GetBoardPos().row - leave_ + i, act_ally->GetBoardPos().col)->SetRenderRangeTile(true);



	}

	





}
