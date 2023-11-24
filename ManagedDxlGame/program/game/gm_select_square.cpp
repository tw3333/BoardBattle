#include "gm_select_square.h"

#include "gm_object_square.h"

void SelectSquare::Update(float delta_time,dxe::Camera* camera) {

	obj_->Update(delta_time);

	
	is_mouse_in_board_ = false;

	tnl::Vector3 msv = tnl::Input::GetMousePosition();
	tnl::Vector3 ray = tnl::Vector3::CreateScreenRay(
		msv.x
		, msv.y
		, camera->screen_w_
		, camera->screen_h_
		, camera->view_
		, camera->proj_);

	tnl::Vector3 hit;
	
	if (tnl::IsIntersectLinePlane(camera->pos_, camera->pos_ + (ray * 10000.0f), { 10, 10, 10 }, { 0, 1, 0 }, &hit)) {
		hit_ = hit;
	}

	if (IsSelectFlameOutOfBoard(hit_)) {
		obj_->parts_[ObjSelectFlame::SelectFlame]->is_render_ = false;
	}
	else {
		obj_->parts_[ObjSelectFlame::SelectFlame]->is_render_ = true;
	}
	
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {

			float bx = board_squares_[i][j]->getObj()->getBeginPos().x;
			float bz = board_squares_[i][j]->getObj()->getBeginPos().z;
			float ex = board_squares_[i][j]->getObj()->getEndPos().x;
			float ez = board_squares_[i][j]->getObj()->getEndPos().z;

			if (bx < (float)hit_.x && hit_.x < ex 
				&& bz > (float)hit_.z && hit_.z > ez) 
			{	

				obj_->pos_.x = board_squares_[i][j]->getObj()->pos_.x;
				obj_->pos_.z = board_squares_[i][j]->getObj()->pos_.z;
				
				//�I������Ă���Square�̍��W���擾
				select_square_row_ = i;
				select_square_col_ = j;
				select_square_pos_ = { i,j};


				//�I������Ă���Square�̃|�C���^���擾
				select_square_ = board_squares_[i][j];

				select_square_obj_pos_.x = board_squares_[i][j]->getObj()->pos_.x;
				select_square_obj_pos_.z = board_squares_[i][j]->getObj()->pos_.z;

				//mouse��square��ɂ���
				is_mouse_in_board_ = true;

			}
		}
	}


}

void SelectSquare::Render(dxe::Camera* camera) {

	//obj_->Render(camera);

	if (select_square_) {

		if (select_square_->GetAllyPtrInSquare()) {
			//DrawStringEx(0,0,-1,"�����ɂ͖����������I");
		}
		else if (select_square_->GetEnemyPtrInSquare()) {
			//DrawStringEx(0,0,-1,"�����ɂ͓G�������I");
		}
	}
	else {
		//DrawStringEx(0,0,-1,"���̃R�[�h�͎��s���Ă�");
	}

	//DrawStringEx(0,100,-1,"test:%f",board_squares_[0][0]->getObj()->getBeginPos().x);


}

//�}�E�X���ՖʊO�ɏo�Ă��邩�ǂ���
//�����Ă�����true��Ԃ�
bool SelectSquare::IsSelectFlameOutOfBoard(tnl::Vector3 hit) {

	if (hit.x < 0 || board_w_ < hit.x || hit.z < 0 || board_h_ < hit.z) {
		return true;
	}




	return false;
}