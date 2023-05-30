#include "gm_unit_ally.h"

//AllyUnitの盤面上の座標のセット、またそれに対応したObjのPosの変更
void UnitAlly::SetBoardPos(int row, int col) {

	board_pos_ = { row, col };

	int w1 = ((DXE_WINDOW_WIDTH / 10) * 8) / 10;
	int h1 = ((DXE_WINDOW_HEIGHT / 10) * 8) / 10;

	int board_w = (DXE_WINDOW_WIDTH / 10) * 8;
	int board_h = (DXE_WINDOW_HEIGHT / 10) * 8;


	obj_->pos_.z = board_h - (h1 / 2) - (h1) * board_pos_.row;
	obj_->pos_.x = (w1 / 2) + ((w1) * board_pos_.col);

}



void UnitAlly::Update() {

	int w1 = ((DXE_WINDOW_WIDTH / 10) * 8) /10;
	int h1 = ((DXE_WINDOW_HEIGHT / 10) * 8) / 10;

	int board_w = (DXE_WINDOW_WIDTH / 10) * 8;
	int board_h = (DXE_WINDOW_HEIGHT / 10) * 8;


	obj_->pos_.z = board_h - (h1 / 2) - (h1) * board_pos_.row;
	obj_->pos_.x = (w1 / 2) + ((w1) * board_pos_.col);



}