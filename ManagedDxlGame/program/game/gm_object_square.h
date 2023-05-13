#pragma once
#include "gm_object.h"
class ObjSquare : public GameObject {
public:

	ObjSquare(){}
	~ObjSquare(){}

	enum {

		BaseSquare,
		PartsMax

	};

	struct SquareSize {
		float w = (DXE_WINDOW_WIDTH / 10) * 8 / 10;
		float h = (DXE_WINDOW_HEIGHT / 10) * 8 / 10;
	};

	static ObjSquare* Create();
	void Update(float delta_time) override;

	//getter
	SquareSize getSquareSize() { return square_size_; }

private:


	SquareSize square_size_;


};