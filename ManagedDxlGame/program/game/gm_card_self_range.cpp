#include "gm_card_self_range.h"

#include "gm_unit_ally.h"
#include "gm_unit_enemy.h"
#include "gm_board.h"
#include "gm_card.h"

void CardSelfRange::Range(Card* card, UnitAlly* act_ally, Board* board) {

	card->AddRangeAllyUnits(act_ally);


}
