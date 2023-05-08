#include "../game/gm_scene_battle_camera.h"





void SceneBattleCamera::Update() {

	//if (CTRL_TYPE_FREE_LOOK == ctrl_type_) {
	//	tnl::Quaternion xq = tnl::Quaternion::RotationAxis({ 1, 0, 0 }, free_look_angle_xy_.x);
	//	tnl::Quaternion yq = tnl::Quaternion::RotationAxis({ 0, 1, 0 }, free_look_angle_xy_.y);
	//	tnl::Quaternion wq = xq * yq;
	//	pos_ = target_ + tnl::Vector3::TransformCoord({ 0, 0, -target_distance_ }, wq);
	//}

	if (camera_type_ == CameraType::Main) {
		
		target_ = pos_ + tnl::Vector3::TransformCoord({ 0, 0, 1 }, rot_);
		pos_ = { DXE_WINDOW_WIDTH / 10 * 8 / 2, 680, -605 + (DXE_WINDOW_HEIGHT) / 10 * 8 / 2 };



	}

	//CameraÇÃçXêV
	dxe::Camera::update();

}