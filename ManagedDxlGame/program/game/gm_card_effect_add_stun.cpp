#include "gm_card_effect_add_stun.h"

#include "gm_board.h"
#include "gm_unit.h"
#include "gm_unit_enemy.h"
#include "gm_unit_ally.h"


void CardEffectAddStun::Effect(std::vector<Unit*> untis)
{
}

void CardEffectAddStun::EffectExcute(std::vector<SquarePos> target_square_pos, Board* board) {

	for (auto square : target_square_pos) {

		if (board->getBoardSquare(square.row, square.col)->GetAllyPtrInSquare()
			|| board->getBoardSquare(square.row, square.col)->GetEnemyPtrInSquare())
		{
			bool hit = false;
			for (auto state : board->getBoardSquare(square.row, square.col)->GetUnitPtrInSquare()->GetBattleState()) {

				if (state.GetState() == State::Stun) {

					state.AddTrunCount(stun_turn_count_);
					hit = true;
				}
			}

			if (!hit) {
				board->getBoardSquare(square.row, square.col)->GetUnitPtrInSquare()->AddBattleState(BattleState(State::Stun, 0, stun_turn_count_));
			}
		}
	}

}

bool CardEffectAddStun::CanEffectExcute(std::vector<SquarePos> target_square_pos, Board* board)
{
	
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
