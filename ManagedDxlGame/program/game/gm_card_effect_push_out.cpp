#include "gm_card_effect_push_out.h"

#include "gm_board.h"
#include "gm_unit.h"
#include "gm_unit_ally.h"
#include "gm_unit_enemy.h"

void CardEffectPushOut::Effect(std::vector<Unit*> untis)
{
}

void CardEffectPushOut::EffectExcute(std::vector<SquarePos> target_square_pos, Board* board) {

	SquarePos ally_pos;
	SquarePos pushed_pos;

	for (auto unit : board->GetPartyUnitsInBoard()) {

		if (unit->GetIsTurn()) {
			ally_pos = unit->GetUnitSquarePos();
		}

	}

	for (auto square : target_square_pos) {

		if (board->getBoardSquare(square.row, square.col)->GetUnitPtrInSquare()) {

			//Ž²‚©‚çã‰º¶‰E‚É‘Î‚µ‚Ä‚Ìˆ—
			//‚Â‚Ü‚èAupper,lower‚É‚Í‘Î‰ž‚µ‚Ä‚È‚¢
			if (board->getBoardSquare(square.row,square.col)->GetUnitPtrInSquare()->GetUnitSquarePos().row < ally_pos.row) {
				
				pushed_pos.row = (std::max)(0, board->getBoardSquare(square.row, square.col)->GetUnitPtrInSquare()->GetUnitSquarePos().row - push_num_);

				board->getBoardSquare(square.row, square.col)->GetUnitPtrInSquare()->SetUnitSquarePos(pushed_pos.row, board->getBoardSquare(square.row, square.col)->GetUnitPtrInSquare()->GetUnitSquarePos().col);
			}
			else if (board->getBoardSquare(square.row, square.col)->GetUnitPtrInSquare()->GetUnitSquarePos().row > ally_pos.row) {

				pushed_pos.row = (std::min)(9, board->getBoardSquare(square.row, square.col)->GetUnitPtrInSquare()->GetUnitSquarePos().row + push_num_);

				board->getBoardSquare(square.row, square.col)->GetUnitPtrInSquare()->SetUnitSquarePos(pushed_pos.row, board->getBoardSquare(square.row, square.col)->GetUnitPtrInSquare()->GetUnitSquarePos().col);
			}

			if (board->getBoardSquare(square.row, square.col)->GetUnitPtrInSquare()->GetUnitSquarePos().col < ally_pos.col) {

				pushed_pos.col = (std::max)(0, board->getBoardSquare(square.row, square.col)->GetUnitPtrInSquare()->GetUnitSquarePos().col - push_num_);

				board->getBoardSquare(square.row, square.col)->GetUnitPtrInSquare()->SetUnitSquarePos(board->getBoardSquare(square.row, square.col)->GetUnitPtrInSquare()->GetUnitSquarePos().row, pushed_pos.col);
			} 
			else if (board->getBoardSquare(square.row, square.col)->GetUnitPtrInSquare()->GetUnitSquarePos().col > ally_pos.col) {

				pushed_pos.col = (std::min)(9, board->getBoardSquare(square.row, square.col)->GetUnitPtrInSquare()->GetUnitSquarePos().col + push_num_);

				board->getBoardSquare(square.row, square.col)->GetUnitPtrInSquare()->SetUnitSquarePos(board->getBoardSquare(square.row, square.col)->GetUnitPtrInSquare()->GetUnitSquarePos().row, pushed_pos.col);
			}

		}

	}

}

bool CardEffectPushOut::CanEffectExcute(std::vector<SquarePos> target_square_pos, Board* board) {

	for (auto square : target_square_pos) {

		if (!board->getBoardSquare(square.row, square.col)->GetUnitPtrInSquare()) {
			return false;
		}
	}

	return true;
}
