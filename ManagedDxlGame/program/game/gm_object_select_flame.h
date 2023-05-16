#pragma once
#include "gm_object_square.h"

class ObjSelectFlame : public ObjSquare {
public:

	ObjSelectFlame() {}
	~ObjSelectFlame(){}
	
	enum {
		SelectFlame,
		PartsMax
	};


	static ObjSelectFlame* Create();
	void Update(float delta_time) override;

private:

	float alpha_ = 1.0f;
	int dxlib_blend_mode_ = DX_BLENDMODE_ALPHA;



};