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



private:





};