#pragma once
#include "gm_object_square.h"
//memo
//盤面の１マスを表すクラス

class Square {
public:

	Square(int row, int col){
		
		obj_ = ObjSquare::Create();
		SetSquarePos(row,col);

		obj_->Update(0);
	}
	~Square(){}

	struct SquarePos {
		int row;
		int col;
	};

	void SetSquarePos(int row, int col);
	ObjSquare* getObj() { return obj_; }
	//tnl::Vector3 getBeginPos() { return begin_pos_; }
	//tnl::Vector3 getEndPos() { return end_pos_; }
	int test_ = 1;

private:

	ObjSquare* obj_;
	
	SquarePos square_pos_ = {0,0};
	
};