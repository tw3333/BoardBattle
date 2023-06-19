#pragma once
#include "gm_object_square.h"
#include "gm_object_manager.h"



//memo
//�Ֆʂ̂P�}�X��\���N���X
class Unit;
class UnitAlly;
class UnitEnemy;


class Square {
public:

	Square(int row, int col, ObjSquare* obj){
		
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
	
	//UnitEnemy* GetUnitEnemy() { return unit_enemy_; }
	//UnitAlly* GetUnitAlly() { return unit_ally_; }
	//void SetUnitEnemy(UnitEnemy* unit);
	//void SetUnitAlly(UnitAlly* unit);

private:

	bool is_can_move_ = true;
	bool enemy_in_square_  = false;
	bool ally_in_square_ = false;

	ObjSquare* obj_;


	SquarePos square_pos_ = {0,0};


};