#include "gm_select_square.h"

void SelectSquare::Update(float delta_time,dxe::Camera* camera) {

	obj_->Update(delta_time);

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
		obj_->parts_[0]->is_render_ = false;
	}
	else {
		obj_->parts_[0]->is_render_ = true;
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
				select_square_row_ = i;
				select_square_col_ = j;
			}
		}
	}


}

void SelectSquare::Render(dxe::Camera* camera) {

	obj_->Render(camera);

	DrawStringEx(0,100,-1,"test:%f",board_squares_[0][0]->getObj()->getBeginPos().x);
}

//マウスが盤面外に出ているかどうか
bool SelectSquare::IsSelectFlameOutOfBoard(tnl::Vector3 hit) {

	if (hit.x < 0 || board_w_ < hit.x || hit.z < 0 || board_h_ < hit.z) {
		return true;
	}
	return false;
}