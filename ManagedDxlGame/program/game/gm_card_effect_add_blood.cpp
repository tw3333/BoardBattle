#include "gm_card_effect_add_blood.h"

#include "gm_board.h"
#include "gm_unit.h"
#include "gm_unit_ally.h"
#include "gm_unit_enemy.h"

void CardEffectAddBlood::Effect(std::vector<Unit*> units)
{
}

bool CardEffectAddBlood::CanEffectExcute(std::vector<SquarePos> range_square_pos, Board* board) {

	//‘ÎÛ‚ªˆêl‚à‚¢‚È‚¢ê‡‚Í‚Å‚«‚È‚¢
	for (auto square : range_square_pos) {

		if (board->getBoardSquare(square.row, square.col)->GetAllyPtrInSquare() 
			|| board->getBoardSquare(square.row, square.col)->GetEnemyPtrInSquare())
		{
			return true;
		}
	}

	return false;
}

void CardEffectAddBlood::EffectExcute(std::vector<SquarePos> target_square_pos, Board* board) {
	
	
	for (auto square : target_square_pos) {
		bool hit = false;

		if (board->getBoardSquare(square.row, square.col)->GetAllyPtrInSquare()
			|| board->getBoardSquare(square.row, square.col)->GetEnemyPtrInSquare()) 
		{
			
			for (auto &state : board->getBoardSquare(square.row, square.col)->GetUnitPtrInSquare()->GetBattleState()) {

				if (state.GetState() == State::Blood) {
					state.SetTurnCount(3);
					hit = true;
				}

			}

		}

		if (!hit) {

			board->getBoardSquare(square.row, square.col)->GetUnitPtrInSquare()->AddBattleState(BattleState(State::Blood,3,3));

		}

	}

}

bool CardEffectAddBlood::CanEffectExcuteFromRange(std::vector<SquarePos> range_square, Board* board) {

	//‘ÎÛ‚ªˆê‘Ì‚Å‚à‚¢‚ê‚Î‚¢‚¢
	for (auto &square : range_square) {

		if (board->getBoardSquare(square.row, square.col)->GetAllyPtrInSquare()
			|| board->getBoardSquare(square.row, square.col)->GetEnemyPtrInSquare())
		{
			return true;
		}
	
	}


	return false;
}
