#include "gm_card_effect_add_card_cost.h"

#include "gm_board.h"
#include "gm_unit.h"
#include "gm_unit_ally.h"
#include "gm_unit_enemy.h"


void CardEffectAddCardCost::Effect(std::vector<Unit*> units)
{
}

bool CardEffectAddCardCost::CanEffectExcute(std::vector<SquarePos> range_square_pos, Board* board) {

	for (auto square : range_square_pos) {

		if (board->getBoardSquare(square.row, square.col)->GetAllyPtrInSquare()) {
			return true;
		}

	}

	//ˆê‘Ì‚à‚¢‚È‚¯‚ê‚Îfalse
	return false;
}

void CardEffectAddCardCost::EffectExcute(std::vector<SquarePos> target_square_pos, Board* board) {

	bool hit = false;
	for (auto square : target_square_pos) {

		if (board->getBoardSquare(square.row, square.col)->GetAllyPtrInSquare()) {

			for (auto state : board->getBoardSquare(square.row, square.col)->GetAllyPtrInSquare()->GetBattleState()) {

				if (state.GetState() == State::AddCardCost) {
					state.AddValue(add_card_cost_);
					hit = true;
				}
			}
		}

		if (!hit) {
			board->getBoardSquare(square.row, square.col)->GetAllyPtrInSquare()->AddBattleState(BattleState(State::AddCardCost, add_card_cost_));
		}

	}

}
