#include "gm_card_effect_add_stun.h"

#include "gm_board.h"
#include "gm_unit.h"
#include "gm_unit_enemy.h"
#include "gm_unit_ally.h"


void CardEffectAddStun::Effect(std::vector<Unit*> untis)
{
}

void CardEffectAddStun::EffectExcute(std::vector<SquarePos> target_square_pos, Board* board)
{

	bool flag = false;

	for (auto square : target_square_pos) {

		if (board->getBoardSquare(square.row, square.col)->GetAllyPtrInSquare()) {

			for (auto state: board->getBoardSquare(square.row, square.col)->GetAllyPtrInSquare()->GetBattleState()) {
				
				if (state.GetState() == State::Stun) {
					
					flag = true;

				}
	
			}

			if (flag = true) {

				for (auto state : board->getBoardSquare(square.row, square.col)->GetAllyPtrInSquare()->GetBattleState()) {

					if (state.GetState() == State::Stun) {

						state.SetTurnCount(3);

					}

				}

			}
			else if (flag == false) {

				board->getBoardSquare(square.row, square.col)->GetAllyPtrInSquare()->AddBattleState(BattleState(State::Stun,0,3));

			}

		}

		else if (board->getBoardSquare(square.row, square.col)->GetEnemyPtrInSquare()) {

			for (auto state : board->getBoardSquare(square.row, square.col)->GetEnemyPtrInSquare()->GetBattleState()) {

				if (state.GetState() == State::Stun) {

					flag = true;

				}

			}

			if (flag = true) {

				for (auto state : board->getBoardSquare(square.row, square.col)->GetEnemyPtrInSquare()->GetBattleState()) {

					if (state.GetState() == State::Stun) {

						state.SetTurnCount(3);

					}

				}

			}
			else if (flag == false) {

				board->getBoardSquare(square.row, square.col)->GetEnemyPtrInSquare()->AddBattleState(BattleState(State::Stun, 0, 3));

			}


		}

		flag = false;
	}

}

bool CardEffectAddStun::CanEffectExcute(std::vector<SquarePos> target_square_pos, Board* board)
{
	
	for (auto square : target_square_pos) {

		if (board->getBoardSquare(square.row, square.col)->GetAllyPtrInSquare()) {
			return true;
		}
		if (board->getBoardSquare(square.row, square.col)->GetEnemyPtrInSquare()) {
			return true;
		}
	}

	return false;
}
