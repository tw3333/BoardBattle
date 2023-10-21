#include "gm_unit_enemy.h"

#include "gm_board.h"
#include "gm_enemy_behavior_strategy.h"
#include "gm_slime_behavior_strategy.h"

void UnitEnemy::Update(float delta_time) {

	//状態Update(後で切り分け)
	if (current_hp_ == 0) {
		is_dead_ = true;
	}

	//ObjUpdate(後で切り分け)
	int w1 = ((DXE_WINDOW_WIDTH / 10) * 8) / 10;
	int h1 = ((DXE_WINDOW_HEIGHT / 10) * 8) / 10;
	int board_w = (DXE_WINDOW_WIDTH / 10) * 8;
	int board_h = (DXE_WINDOW_HEIGHT / 10) * 8;
	//obj_->pos_.z = board_h - (h1 / 2) - (h1) * board_pos_.row;
	//obj_->pos_.x = (w1 / 2) + ((w1) * board_pos_.col);
	//obj_->pos_.z = board_h - (h1 / 2) - (h1) * unit_square_pos_.row;
	//obj_->pos_.x = (w1 / 2) + ((w1) * unit_square_pos_.col);
	unit_obj_->pos_.z = board_h - (h1 / 2) - (h1)*unit_square_pos_.row;
	unit_obj_->pos_.x = (w1 / 2) + ((w1)*unit_square_pos_.col);
	unit_obj_->Update(delta_time);
}

void UnitEnemy::Render(dxe::Camera* camera) {

	if (unit_obj_) {
		unit_obj_->Render(camera);
	}


}

void UnitEnemy::InitEnemyObjPos() {

	int w1 = ((DXE_WINDOW_WIDTH / 10) * 8) / 10;
	int h1 = ((DXE_WINDOW_HEIGHT / 10) * 8) / 10;

	int board_w = (DXE_WINDOW_WIDTH / 10) * 8;
	int board_h = (DXE_WINDOW_HEIGHT / 10) * 8;


	//obj_->pos_.z = board_h - (h1 / 2) - (h1) * board_pos_.row;
	//obj_->pos_.x = (w1 / 2) + ((w1) * board_pos_.col);

	unit_obj_->pos_.z = board_h - (h1 / 2) - (h1) * unit_square_pos_.row;
	unit_obj_->pos_.x = (w1 / 2) + ((w1) * unit_square_pos_.col);

	unit_obj_->Update(0);
}


void UnitEnemy::Move(Board* board){

	//behavior_->Move(this,board);
	enemy_data_->GetEnemyMove()->Move(this, board);

	

}

void UnitEnemy::Act(Board* board) {

	//behavior_->Act(this,board);
	enemy_data_->GetEnemyAct()->Act(this, board);

}





