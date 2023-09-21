#include "gm_card_effect_add_move_cost.h"

void CardEffectAddMoveCost::Effect(std::vector<Unit*> units)
{
}

bool CardEffectAddMoveCost::CanEffectExcute(std::vector<SquarePos> range_square_pos, Board* board)
{
	return false;
}

void CardEffectAddMoveCost::EffectExcute(std::vector<SquarePos> target_square_pos, Board* board)
{
}
