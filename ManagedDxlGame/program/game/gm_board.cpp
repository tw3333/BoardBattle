#include "gm_board.h"

void Board::Create() {

	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++i) {

			board_squares_.push_back(new Square(i,j));

		}

	}

}

void Board::Update(float delta_time) {

	for (auto bs : board_squares_) {

		bs->getObj()->Update(delta_time);

	}

}


void Board::Render(dxe::Camera* camera) {

	for (auto bs : board_squares_) {

		bs->getObj()->Render(camera);

	}

}