#include "gm_card_target.h"

#include "gm_board.h"


//memo
//¡ŒãAâ‘Î‚Én‘Ìw’è‚µ‚È‚¯‚ê‚Î‚¢‚¯‚È‚¢‚Æ‚¢‚¤Œø‰Ê‚ğì‚éÛ‚Í‚±‚±‚É‚»‚ê‚ğ’Ç‰Á‚·‚é

void CardTarget::ResetCardTarget() {

	if (!target_squares_pos_.empty()) {
		target_squares_pos_.clear();
	}

	is_specified_ = false;
	is_determined_ = false;

}

bool CardTarget::IsTargetInRange(std::vector<SquarePos> range, Board* board)
{

	if (target_type_ == TARGETTYPE::InRange) {

		//ˆê‘Ì‚Å‚à‚¢‚ê‚Îok
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
