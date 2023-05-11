#pragma once
#include "gm_object.h"
#include "../dxlib_ext/dxlib_ext_camera.h"

class ObjBoard : public GameObject {
public:

	ObjBoard(){}
	~ObjBoard(){}

	enum {
		Board,
		PartsMax
	};

	//ÉÅÉìÉoä÷êî
	static ObjBoard* Create();
	void Update(float delta_time) override;
	

private:

	tnl::Vector3 size_ = {DXE_WINDOW_WIDTH /10 * 8,0,DXE_WINDOW_HEIGHT / 10 * 8};
	
	float size_w_ = (DXE_WINDOW_WIDTH / 10) * 8;
	float size_h_ = (DXE_WINDOW_HEIGHT / 10) * 8;



};
