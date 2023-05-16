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
	tnl::Vector3 getSize() { return size_; }
	tnl::Vector3 getBeginPos() { return begin_pos_; } 
	tnl::Vector3 getEndPos() { return end_pos_; } 

private:


	SquareSize square_size_;
	
	tnl::Vector3 size_ = {
		(DXE_WINDOW_WIDTH / 10)*8/10,0,
		(DXE_WINDOW_HEIGHT / 10) * 8 / 10
	};

	//ObjSquareの始点x,z
	tnl::Vector3 begin_pos_ = {
		pos_.x - (DXE_WINDOW_WIDTH / 10) * 8 / 10 / 2,0,
		pos_.z + (DXE_WINDOW_HEIGHT / 10) * 8 / 10 / 2
	}; 

	//ObjSquareの終点x,z
	tnl::Vector3 end_pos_ = {
		pos_.x + (DXE_WINDOW_WIDTH / 10) * 8 / 10 / 2,0,
		pos_.z - (DXE_WINDOW_HEIGHT / 10) * 8 / 10 / 2
	};


};