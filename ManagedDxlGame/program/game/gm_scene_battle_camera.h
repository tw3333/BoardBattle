#pragma once
#include "../dxlib_ext/dxlib_ext_camera.h"

//memo
//SceneBattleópÇÃcamera

class SceneBattleCamera : public dxe::Camera {
public:

	SceneBattleCamera() : dxe::Camera(DXE_WINDOW_WIDTH, DXE_WINDOW_HEIGHT) {}
	~SceneBattleCamera() {}

	enum CameraType {
		Main
	};



	void Update();

	tnl::Quaternion rot_;

	enum {
		CTRL_TYPE_FREE_LOOK
		, CTRL_TYPE_QTN
	};

	int ctrl_type_ = CTRL_TYPE_QTN;

	tnl::Vector3 free_look_angle_xy_ = { tnl::ToRadian(30), 0, 0 };
	float target_distance_ = 100;

	//ÉÅÉìÉoä÷êî
	

	//g,s
	CameraType getCameraType() { return camera_type_; }
	void setCameraType(CameraType camera_type) { camera_type_ = camera_type; }
	

private:

	CameraType camera_type_ = Main;

	//float target_distance_ = 100;

	tnl::Vector3 main_camera_pos_;



	

};