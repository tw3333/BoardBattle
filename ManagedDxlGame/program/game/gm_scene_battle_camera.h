#pragma once
#include "../dxlib_ext/dxlib_ext_camera.h"

//memo
//SceneBattle—p‚Ìcamera

class SceneBattleCamera : public dxe::Camera {
public:

	SceneBattleCamera() : dxe::Camera(DXE_WINDOW_WIDTH, DXE_WINDOW_HEIGHT) {}
	~SceneBattleCamera() {}

	enum CameraType {
		Main
	};

	void Update();

	//g,s
	CameraType getCameraType() { return camera_type_; }
	void setCameraType(CameraType camera_type) { camera_type_ = camera_type; }


private:

	CameraType camera_type_ = Main;

	float target_distance_ = 100;

	tnl::Vector3 main_camera_pos_;



	

};