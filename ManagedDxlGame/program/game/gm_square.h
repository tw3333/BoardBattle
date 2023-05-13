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

private:

	ObjSquare* obj_ = nullptr;
	
	SquarePos square_pos_ = {0,0};



};