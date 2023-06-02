#pragma once
#include "gm_object_square.h"
#include "gm_object_manager.h"

//memo
//�Ֆʂ̂P�}�X��\���N���X

class Square {
public:

	Square(int row, int col, ObjSquare* obj){
		
		obj_ = obj;
		SetSquarePos(row, col);

	}
	~Square(){}

	struct SquarePos {
		int row;
		int col;
	};

	void SetSquarePos(int row, int col);
	void SetObj(ObjSquare* obj) { obj_ = obj; }
	ObjSquare* getObj() { return obj_; }
	int test_ = 1;


private:

	ObjSquare* obj_;
	
	SquarePos square_pos_ = {0,0};


};