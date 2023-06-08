#include "gm_battle_phase_player_action_move.h"



void PhasePlayerActionMove::BeginPhase()
{
}

void PhasePlayerActionMove::EndPhase()
{
}

bool PhasePlayerActionMove::UpdateExecute(float delta_time) {

	select_square_row_ = select_square_->GetSelectSquareRow();
	select_square_col_ = select_square_->GetSelectSquareCol();

	DrawStringEx(500,30,-1,"PhasePlayerActionMove");

	DisplayMoveRange(turn_ally_);





	return true;
}

bool PhasePlayerActionMove::RenderExecute(dxe::Camera* camera){
	
	
		
	
	
	return true;
}

void PhasePlayerActionMove::DisplayMoveRange(UnitAlly* unit) {

	int ally_row = unit->GetBoardPos().row;
	int ally_col = unit->GetBoardPos().col;

	int move_cost = unit->GetCurrentMoveCost();

	CrearMoveRange();

	for (int row = (std::max)(0, ally_row - move_cost); row <= (std::min)(9, ally_row + move_cost); ++row) {
		for (int col = (std::max)(0, ally_col - move_cost); col <= (std::min)(9, ally_col + move_cost); ++col) {

			if ((row != ally_row || col != ally_col) && (std::max)(std::abs(ally_col - col), std::abs(ally_row - row)) <= move_cost) {
				
				// ˆÚ“®‰Â”\”ÍˆÍ“à‚É‚ ‚éÀ•W‚ð•\Ž¦
				if (board_squares_[row][col]->GetIsCanMove()) {

					board_squares_[row][col]->getObj()->parts_[ObjSquare::RangeTile]->is_render_ = true;

					
					if (tnl::Input::IsMouseTrigger(eMouseTrigger::IN_LEFT)) {

						if (row == select_square_row_ && col == select_square_col_) {

							
							
							unit->SetBoardPos(select_square_row_, select_square_col_);
							int distanceMoved = std::abs(ally_row - row) + std::abs(ally_col - col);
							unit->SetCurrentMoveCost(move_cost - distanceMoved);


						}

					}

				}


				//std::cout << "Square at (" << col << ", " << row << ") is within move range.\n";


			}

		}
	}

}

void PhasePlayerActionMove::CrearMoveRange() {

	for (auto& row : board_squares_) {
		for (auto& square : row) {
			square->getObj()->parts_[ObjSquare::RangeTile]->is_render_ = false;
		}
	}


}


