#include "gm_battle_player_action_move.h"


void PlayerActionMove::Update(float delta_time) {

	if (is_enabled_) {

		DisplayMoveRange(turn_ally_);
		


		


	}

}

void PlayerActionMove::DisplayMoveRange(UnitAlly* unit) {

	int ally_row = unit->GetBoardPos().row;
	int ally_col = unit->GetBoardPos().col;

	int move_cost = unit->GetCurrentMoveCost();

	for (int row = (std::max)(0, ally_row - move_cost); row <= (std::min)(9, ally_row + move_cost); ++row) {
		for (int col = (std::max)(0, ally_col - move_cost); col <= (std::min)(9, ally_col + move_cost); ++col) {
			
			if ((row != ally_row || col != ally_col) && (std::max)(std::abs(ally_col - col), std::abs(ally_row - row)) <= move_cost) {
				// ˆÚ“®‰Â”\”ÍˆÍ“à‚É‚ ‚éÀ•W‚ð•\Ž¦

				if (board_squares_[row][col]->GetIsCanMove()) {

					board_squares_[row][col]->getObj()->parts_[ObjSquare::RangeTile]->is_render_ = true;



				}
				
				//std::cout << "Square at (" << col << ", " << row << ") is within move range.\n";


			}

		}
	}


}