#include "gm_select_square.h"

void SelectSquare::Update(float delta_time,dxe::Camera* camera) {

	tnl::Vector3 msv = tnl::Input::GetMousePosition();
	tnl::Vector3 ray = tnl::Vector3::CreateScreenRay(
		msv.x
		, msv.y
		, camera->screen_w_
		, camera->screen_h_
		, camera->view_
		, camera->proj_);

	tnl::Vector3 hit;

	//if (tnl::IsIntersectLinePlane(camera_->pos_, camera_->pos_ + (ray * 10000.0f), { 10, 10, 10 }, { 0, 1, 0 }, &hit)) {
	//	sprite_->pos_ = hit;
	//}







}