#pragma once
#include "gm_object_square.h"


class ObjMoveSelectFlame : public ObjSquare {
public:

	ObjMoveSelectFlame(){}
	~ObjMoveSelectFlame(){}

	enum {
		MoveSelectFlame,
		PartsMax
	};
	

	static ObjMoveSelectFlame* Create();
	void Update(float delta_time) override;



private:

	float alpha_ = 1.0;
	int dxlib_blend_mode_ = DX_BLENDMODE_ALPHA;

};