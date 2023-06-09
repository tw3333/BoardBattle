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
	bool is_flashing_ = true;

private:

	float time_ = 0;
	const float PI_ = 3.14159265;
	float frequency_ = 1.3; //点滅の速度調整用変数
	float alpha_ = 1.0;
	int dxlib_blend_mode_ = DX_BLENDMODE_ALPHA;

};