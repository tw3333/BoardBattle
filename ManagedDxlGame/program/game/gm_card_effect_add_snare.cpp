#include "gm_card_effect_add_snare.h"

#include "gm_board.h"
#include "gm_unit.h"
#include "gm_unit_ally.h"
#include "gm_unit_enemy.h"



void CardEffectAddSnare::Effect(std::vector<Unit*> untis)
{
}

void CardEffectAddSnare::EffectExcute(std::vector<SquarePos> target_square_pos, Board* board) {

	for (auto square : target_square_pos) {

		if (board->getBoardSquare(square.row, square.col)->GetAllyPtrInSquare()
			|| board->getBoardSquare(square.row, square.col)->GetEnemyPtrInSquare())
		{
			bool hit = false;
			for (auto state : board->getBoardSquare(square.row, square.col)->GetUnitPtrInSquare()->GetBattleState()) {

				if (state.GetState() == State::Snare) {

					state.AddTrunCount(snare_turn_count_);
					hit = true;
				}
			}

			if (!hit) {
				board->getBoardSquare(square.row, square.col)->GetUnitPtrInSquare()->AddBattleState(BattleState(State::Blood, 0, snare_turn_count_));
			}
		}
	}

}

bool CardEffectAddSnare::CanEffectExcute(std::vector<SquarePos> target_square_pos, Board* board) {

	for (auto square : target_square_pos) {

		if (board->getBoardSquare(square.row, square.col)->GetAllyPtrInSquare()) {
			return true;
		}
		else if (board->getBoardSquare(square.row, square.col)->GetEnemyPtrInSquare()) {
			return true;
		}

	}

	return false;
}
