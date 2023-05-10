#pragma once
#include "program/game/gm_object.h"
#include "../ManagedDxlGame/program/dxlib_ext/dxlib_ext_camera.h"
#include "../ManagedDxlGame/program/dxlib_ext/dxlib_ext_mesh.h"

class ObjBoard : public GameObject {
public:

	ObjBoard(){}
	~ObjBoard(){}

	enum {
		Board,
		PartsMax
	};

	//ÉÅÉìÉoä÷êî
	ObjBoard* Create();
	void Update(float delta_time) override;
	//void Render(dxe::Camera* camera) override;

private:

	tnl::Vector3 size_ = {DXE_WINDOW_WIDTH /10 * 8,0,DXE_WINDOW_HEIGHT / 10 * 8};
	
	float size_w_ = (DXE_WINDOW_WIDTH / 10) * 8;
	float size_h_ = (DXE_WINDOW_HEIGHT / 10) * 8;


};
