#include "gm_board.h"

void Board::Create() {

	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
				
			board_squares_[i][j] = new Square(i,j,omgr_.GetSquaresAtIndex(i,j));
			
		}
	}

}

void Board::Update(float delta_time) {

	UpdateCanMoveSquare();

	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {

			board_squares_[i][j]->getObj()->Update(delta_time);

		}

	}

	select_square_->Update(delta_time,camera_);

}


void Board::Render(dxe::Camera* camera) {
	
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {

			board_squares_[i][j]->getObj()->Render(camera);

		}
	}

	//Boardのグリット線
	for (int i = 0; i <= 10; ++i) {

		float mas_x = (w1 * 8) / 10;
		float mas_z = (h1 * 8) / 10;

		DrawLine3D({ 0,0,0 + (mas_z * i) }, { float(w1 * 8),0,0 + (mas_z * i) }, gray_);
		DrawLine3D({ 0 + (mas_x * i),0,0 }, { 0 + (mas_x * i),0,(float)(h1 * 8) }, gray_);
	}


	select_square_->Render(camera_);


}

void Board::UpdateCanMoveSquare() {

	//allyのいるマスを移動禁止
	for (int i = 0; i < sizeof(party_) / sizeof(party_[0]); ++i) {

		board_squares_[party_[i]->GetBoardPos().row][party_[i]->GetBoardPos().col]->SetIsCanMove(false);

	}


}