#pragma once
#include "gm_object_square.h"
#include "gm_object_manager.h"



//memo
//盤面の１マスを表すクラス
class Unit;
class UnitAlly;
class UnitEnemy;


class Square {
public:

	Square(int row, int col, ObjSquare* obj) {

		obj_ = obj;
		SetSquarePos(row, col);

	}

	struct SquarePos {
		int row;
		int col;
	};

	void SetSquarePos(int row, int col);
	void SetObj(ObjSquare* obj) { obj_ = obj; }
	ObjSquare* getObj() { return obj_; }
	int test_ = 1;

	bool GetIsCanMove() { return is_can_move_; }
	void SetIsCanMove(bool flag) { is_can_move_ = flag; }
	bool GetEnemyInSquare() { return enemy_in_square_; }
	void SetEnemyInSquare(bool flag) { enemy_in_square_ = flag; }
	bool GetAllyInSquare() { return ally_in_square_; }
	void SetAllyInSquare(bool flag) { ally_in_square_ = flag; }

	void SetRenderRangeTile(bool flag) { obj_->parts_[ObjSquare::RangeTile]->is_render_ = flag; }
	bool GetRenderRangeTile() { return obj_->parts_[ObjSquare::RangeTile]->is_render_; }
	void SetRenderCandidateTile(bool flag) { obj_->parts_[ObjSquare::CandidateTile]->is_render_ = flag; }
	bool GetRenderCandidateTile() { return obj_->parts_[ObjSquare::CandidateTile]->is_render_; }
	void SetRenderTargetTile(bool flag) { obj_->parts_[ObjSquare::TargetTile]->is_render_ = flag; }
	bool GetRenderTargetTile() { return obj_->parts_[ObjSquare::TargetTile]->is_render_; }

	UnitAlly* GetAllyPtrInSquare() { return ally_ptr_in_square_; }
	void SetAllyPtrInSquare(UnitAlly* ptr) { ally_ptr_in_square_ = ptr; }
	UnitEnemy* GetEnemyPtrInSquare() { return enemy_ptr_in_square_; }
	void SetEnemyPtrInSquare(UnitEnemy* ptr) { enemy_ptr_in_square_ = ptr; }
	Unit* GetUnitPtrInSquare() { return unit_ptr_in_square_; }
	void SetUnitPtrInSquare(Unit* ptr) { unit_ptr_in_square_ = ptr; }



private:

	SquarePos square_pos_ = { 0,0 };

	bool is_can_move_ = true;
	bool enemy_in_square_ = false;
	bool ally_in_square_ = false;

	ObjSquare* obj_;

	Unit* unit_ptr_in_square_ = nullptr;
	UnitAlly* ally_ptr_in_square_ = nullptr;
	UnitEnemy* enemy_ptr_in_square_ = nullptr;

};