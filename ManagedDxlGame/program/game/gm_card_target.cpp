#include "gm_card_target.h"

#include "gm_board.h"


//memo
//今後、絶対にn体指定しなければいけないという効果を作る際はここにそれを追加する

bool CardTarget::IsTargetInRange(std::vector<SquarePos> range, Board* board)
{

	if (target_type_ == TARGETTYPE::InRange) {

		//一体でもいればok
		if (to_target_ == TOTARGET::Ally) {

			for (auto square : range) {

				if (board->getBoardSquare(square.row, square.col)->GetAllyPtrInSquare()) {
					return true;
				}

			}
		}
		else if (to_target_ == TOTARGET::Enemy) {

			for (auto square : range) {

				if (board->getBoardSquare(square.row, square.col)->GetEnemyPtrInSquare()) {
					return true;
				}

			}
		}
		else if (to_target_ == TOTARGET::All) {

			for (auto square : range) {

				if (board->getBoardSquare(square.row, square.col)->GetUnitPtrInSquare()) {
					return true;
				}
			}

		}
		else if (to_target_ == TOTARGET::CanMoveSqure) {

			for (auto square : range) {

				if (board->getBoardSquare(square.row, square.col)->GetIsCanMove()) {
					return true;
				}
			}

		}

	}

	return false;
}
