#pragma once
#include "../dxlib_ext/dxlib_ext_camera.h"

//memo
//SceneBattleópÇÃcamera

class SceneBattleCamera : public dxe::Camera {
public:

	SceneBattleCamera() : dxe::Camera(DXE_WINDOW_WIDTH, DXE_WINDOW_HEIGHT) {
		target_ = main_camera_target_;
		
		rot_ *= tnl::Quaternion::RotationAxis({ 1, 0, 0 }, tnl::ToRadian(54));
	}
	~SceneBattleCamera() {}

	enum CameraType {
		Main
	};

	tnl::Quaternion rot_; 

	//int ctrl_type_ = CTRL_TYPE_QTN;

	tnl::Vector3 free_look_angle_xy_ = { tnl::ToRadian(30), 0, 0 };
	float target_distance_ = 100;
	
	


	//ÉÅÉìÉoä÷êî

	void Update();

	//g,s
	CameraType getCameraType() { return camera_type_; }
	void setCameraType(CameraType camera_type) { camera_type_ = camera_type; }
	

private:

	CameraType camera_type_ = Main;

	
	//float target_distance_ = 100;

	tnl::Vector3 main_camera_pos_;

	tnl::Vector3 main_camera_target_ = {(float)(DXE_WINDOW_WIDTH /10) * 8 / 2, 0, (float)(DXE_WINDOW_HEIGHT/10) * 8 /2 };

	//colorcode
	int red_ = GetColor(255,0,0);
	

};