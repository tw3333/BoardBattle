#include "gm_card_effect_add_move_cost.h"

#include "gm_board.h"
#include "gm_unit.h"
#include "gm_unit_ally.h"
#include "gm_unit_enemy.h"

void CardEffectAddMoveCost::Effect(std::vector<Unit*> units)
{
}

bool CardEffectAddMoveCost::CanEffectExcute(std::vector<SquarePos> range_square_pos, Board* board) {

	//”ÍˆÍ‚ÉAlly‚ª‚¢‚È‚¢ê‡‚Í‚Å‚«‚È‚¢
	for (auto square : range_square_pos) {

		if (board->getBoardSquare(square.row, square.col)->GetAllyPtrInSquare()) {
			return true;
		}

	}



	return false;
}

void CardEffectAddMoveCost::EffectExcute(std::vector<SquarePos> target_square_pos, Board* board) {

	bool hit = false;
	for (auto square : target_square_pos) {

		if (board->getBoardSquare(square.row, square.col)->GetAllyPtrInSquare()) {

			for (auto &state : board->getBoardSquare(square.row, square.col)->GetAllyPtrInSquare()->GetBattleState()) {

				if (state.GetState() == State::AddMoveCost) {
					state.AddValue(add_move_cost_);
					hit = true;
				}
			}
		}

		if (!hit) {
			board->getBoardSquare(square.row, square.col)->GetAllyPtrInSquare()->AddBattleState(BattleState(State::AddMoveCost, add_move_cost_));
		}

	}

}
