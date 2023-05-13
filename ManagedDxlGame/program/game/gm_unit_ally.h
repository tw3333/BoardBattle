#pragma once
#include "gm_unit.h"
#include "gm_object_ally.h"
#include "gm_data_ally.h"

//memo
//盤面上のUnitとしてのAllyを表すクラス
//AllyDataクラスのポインタを渡して作成


class UnitAlly : public Unit {
public:

	UnitAlly(AllyData* ally_data, int row, int col) {
	
		ally_data_ = ally_data;
		obj_ = ObjAlly::Create(ally_data_);
		setBoardPos(row, col);
		obj_->Update(0);

	}
	~UnitAlly(){}

	
	void Update();
	//void InitializeBoardAndObjPos(int row, int col);

	//setter
	//void setBoardPos(int row, int col) { 
	//	board_pos_.row = row;
	//	board_pos_.col = col;
	//}

	void setBoardPos(int row, int col);

	//getter
	ObjAlly* getObj() { return obj_; }


private:

	AllyData* ally_data_ = nullptr;
	ObjAlly* obj_ = nullptr;

	//状態
	bool is_dead_ = false;
	bool is_acted_ = false;

	BoardPos board_pos_;

};
