#pragma once
#include "gm_unit.h"
#include "gm_object_ally.h"
#include "gm_data_ally.h"
#include "gm_object_manager.h"


//memo
//盤面上のUnitとしてのAllyを表すクラス
//AllyDataクラスのポインタを渡して作成


class UnitAlly : public Unit {
public:

	UnitAlly(int id,AllyData* ally_data, int row, int col) {
	
		ally_data_ = ally_data;
		max_hp_ = ally_data_->GetHp();
		current_hp_ = max_hp_;
		max_card_cost_ = ally_data_->GetCost();
		current_card_cost_ = max_card_cost_;
		max_move_cost_ = ally_data_->GetMoveCost();
		speed_ = ally_data_->GetSpeed();


		obj_ = ObjAlly::Create(ally_data_);
		SetBoardPos(row, col);

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

	void SetBoardPos(int row, int col);
	

	//getter
	ObjAlly* getObj() { return obj_; }
	void SetObj(ObjAlly* obj) { obj_ = obj; }

	int GetMaxHp() { return max_hp_; }
	int GetCurrentHp() { return current_hp_; }
	int GetMaxCardCost() { return max_card_cost_;}
	int GetCurrentCardCost() { return current_card_cost_; }
	int GetMaxMoveCost() { return max_move_cost_; }
	int GetCurrentMoveCost() { return current_card_cost_; }
	int GetSpeed() { return speed_; }

	bool GetIsDead() { return is_dead_; }
	bool GetIs_Acted() { return is_acted_; }


private:

	AllyData* ally_data_ = nullptr;
	ObjAlly* obj_ = nullptr;

	//ステータス
	int max_hp_;
	int current_hp_;

	int max_card_cost_;
	int current_card_cost_;

	int max_move_cost_;
	int current_move_cost_;

	int speed_;


	//状態
	bool is_dead_ = false;
	bool is_acted_ = false;

};
