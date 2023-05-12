#pragma once
#include "gm_unit.h"
#include "gm_object_ally.h"
#include "gm_data_ally.h"

//memo
//盤面上のUnitとしてのAllyを表すクラス
//AllyDataクラスのポインタを渡して作成


class UnitAlly : public Unit {
public:

	UnitAlly(AllyData* ally_data) {
	
		ally_data_ = ally_data;
		obj_ = ObjAlly::Create(ally_data_);
	}
	~UnitAlly(){}

	
	void Update();
	
	//setter
	void setBoardPos(int row, int col) { 
		board_pos_.row = row;
		board_pos_.col = col;
	}

	//getter
	ObjAlly* getObj() { return obj_; }


private:

	AllyData* ally_data_;
	ObjAlly* obj_;

	//状態
	bool is_dead_ = false;
	bool is_acted_ = false;

	BoardPos board_pos_;

};
