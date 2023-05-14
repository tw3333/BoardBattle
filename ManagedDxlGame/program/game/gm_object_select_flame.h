#pragma once
#include "gm_object_square.h"

class ObjSelectFlame : public ObjSquare {
public:

	ObjSelectFlame() {}
	~ObjSelectFlame(){}

	static ObjSelectFlame* Create();
	void Update(float delta_time) override;

private:


};