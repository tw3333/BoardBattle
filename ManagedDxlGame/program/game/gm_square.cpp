#include "gm_square.h"
#include "gm_unit.h"
#include "gm_unit_ally.h"
#include "gm_unit_enemy.h"



void Square::Update(float delta_time) {

	//Unit������Ƃ��͈ړ��s��
	if (ally_ptr_in_square_ || enemy_ptr_in_square_) {
		is_can_move_ = false;
	}
	else {
		is_can_move_ = true;
	}


	//�eUnit���ƂɃt���O�X�V��
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

//Square�����}�X�ɐݒu���邩�̊֐�
//���̊֐���Square�̎���Obj�̈ʒu��fit
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

////Square��UnitEnemy����������B���̍�UnitAlly�̃|�C���^��nullptr��
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
////Square��UnitAlly����������B���̍�UnitEnemy�̃|�C���^��nullptr��
//void Square::SetUnitAlly(UnitAlly* unit) {
//
//	if (unit_enemy_) {
//		unit_enemy_ = nullptr;
//	}
//
//	unit_ally_ = unit;
//
//}

