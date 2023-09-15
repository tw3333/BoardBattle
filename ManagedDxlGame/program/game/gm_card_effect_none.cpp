#include "gm_card_effect_none.h"

void CardEffectNone::Effect(std::vector<Unit*> units)
{
}

bool CardEffectNone::CanEffectExcute(std::vector<SquarePos> range_square_pos, Board* board)
{
	return false;
}

void CardEffectNone::EffectExcute(std::vector<SquarePos> target_square_pos, Board* board)
{

	int test = 0;

}
