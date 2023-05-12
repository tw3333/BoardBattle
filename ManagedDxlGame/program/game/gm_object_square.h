#pragma once
#include "gm_object.h"
class ObjSquare : public GameObject {
public:

	ObjSquare(){}
	~ObjSquare(){}

	enum {

		BaseSquare,
		RangeTarget,
		Obstacle,
		PartsMax

	};


	static ObjSquare* Create();
	void Update(float delta_time) override;

private:






};