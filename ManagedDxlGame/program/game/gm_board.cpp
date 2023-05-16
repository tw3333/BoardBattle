#include "gm_board.h"

void Board::Create() {

	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
		
			test_board_squares_[i][j] = new Square(i,j);

		}
	}

}

void Board::Update(float delta_time) {

	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {

			test_board_squares_[i][j]->getObj()->Update(delta_time);



		}

	}

}


void Board::Render(dxe::Camera* camera) {
	
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {

			test_board_squares_[i][j]->getObj()->Render(camera);


		}
	}

}