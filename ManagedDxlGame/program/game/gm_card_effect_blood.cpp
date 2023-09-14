#include "gm_card_effect_blood.h"

#include "gm_board.h"
#include "gm_unit.h"
#include "gm_unit_ally.h"
#include "gm_unit_enemy.h"


void CardEffectBlood::Effect(std::vector<Unit*> untis)
{
}

void CardEffectBlood::EffectExcute(std::vector<SquarePos> target_square_pos, Board* board)
{
	bool flag = false;

	for (auto square : target_square_pos) {

		if (board->getBoardSquare(square.row, square.col)->GetAllyPtrInSquare()) {

			for (auto state : board->getBoardSquare(square.row, square.col)->GetAllyPtrInSquare()->GetBattleState()) {

				if (state.GetState() == State::Blood) {

					flag = true;

				}

			}

			if (flag = true) {

				for (auto state : board->getBoardSquare(square.row, square.col)->GetAllyPtrInSquare()->GetBattleState()) {

					if (state.GetState() == State::Blood) {

						state.SetTurnCount(3);

					}

				}

			}
			else if (flag == false) {

				board->getBoardSquare(square.row, square.col)->GetAllyPtrInSquare()->AddBattleState(BattleState(State::Blood, 3, 3));

			}

		}

		else if (board->getBoardSquare(square.row, square.col)->GetEnemyPtrInSquare()) {

			for (auto state : board->getBoardSquare(square.row, square.col)->GetEnemyPtrInSquare()->GetBattleState()) {

				if (state.GetState() == State::Blood) {

					flag = true;

				}

			}

			if (flag = true) {

				for (auto state : board->getBoardSquare(square.row, square.col)->GetEnemyPtrInSquare()->GetBattleState()) {

					if (state.GetState() == State::Blood) {

						state.SetTurnCount(3);

					}

				}

			}
			else if (flag == false) {

				board->getBoardSquare(square.row, square.col)->GetEnemyPtrInSquare()->AddBattleState(BattleState(State::Blood, 3, 3));

			}


		}

		flag = false;
	}


}

bool CardEffectBlood::CanEffectExcute(std::vector<SquarePos> target_square_pos, Board* board)
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
