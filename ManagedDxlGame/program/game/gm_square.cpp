#include "gm_square.h"
#include "gm_unit.h"
#include "gm_unit_ally.h"
#include "gm_unit_enemy.h"



void Square::Update(float delta_time) {

	//Unitがいるときは移動不可に
	if (ally_ptr_in_square_ || enemy_ptr_in_square_) {
		is_can_move_ = false;
	}
	else {
		is_can_move_ = true;
	}


	//各Unitごとにフラグ更新ん
	if (ally_ptr_in_square_) {
		ally_in_square_ = true;
	} else {
		ally_in_square_ = false;
	}
	if (enemy_ptr_in_square_) {
		enemy_in_square_ = true;
	} else{
		enemy_in_square_ = false;
	}



	obj_->Update(delta_time);
}

void Square::Render(dxe::Camera* camera) {

	obj_->Render(camera);

}

//Squareを何マスに設置するかの関数
//この関数でSquareの持つObjの位置もfit
void Square::SetSquarePos(int row, int col) {

	square_pos_ = { row, col };

	//int w1 = ((DXE_WINDOW_WIDTH / 10) * 8) / 10;
	//int h1 = ((DXE_WINDOW_HEIGHT / 10) * 8) / 10;

	//int board_w = (DXE_WINDOW_WIDTH / 10) * 8;
	//int board_h = (DXE_WINDOW_HEIGHT / 10) * 8;


	//obj_->pos_.z = board_h - (h1 / 2) - (h1) * square_pos_.row;
	//obj_->pos_.x = (w1 / 2) + ((w1)*square_pos_.col);

	//obj_->Update(0);

}

void Square::InitObjPos() {

	int w1 = ((DXE_WINDOW_WIDTH / 10) * 8) / 10;
	int h1 = ((DXE_WINDOW_HEIGHT / 10) * 8) / 10;

	int board_w = (DXE_WINDOW_WIDTH / 10) * 8;
	int board_h = (DXE_WINDOW_HEIGHT / 10) * 8;

	obj_->pos_.z = board_h - (h1 / 2) - (h1) * square_pos_.row;
	obj_->pos_.x = (w1 / 2) + ((w1) * square_pos_.col);

}

////SquareにUnitEnemyを持たせる。その際UnitAllyのポインタをnullptrに
//void Square::SetUnitEnemy(UnitEnemy* unit) {
//
//	if (unit_ally_) {
//		unit_ally_ = nullptr;
//	}
//
//	unit_enemy_ = unit;
//
//
//}
//
////SquareにUnitAllyを持たせる。その際UnitEnemyのポインタをnullptrに
//void Square::SetUnitAlly(UnitAlly* unit) {
//
//	if (unit_enemy_) {
//		unit_enemy_ = nullptr;
//	}
//
//	unit_ally_ = unit;
//
//}

