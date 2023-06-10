#pragma once
#include "gm_unit.h"
#include "../dxlib_ext/dxlib_ext.h"
#include "gm_data_enemy.h"
#include "gm_object_enemy.h"


class UnitEnemy : public Unit {
public:

	UnitEnemy(){}
	~UnitEnemy(){}


	void Update();

	void SetBoardPos(int row, int col);



private:
	
	EnemyData* enemy_data_ = nullptr;
	ObjEnemy* obj_ = nullptr;



	//ステータス
	int max_hp_;
	int current_hp_;

	int max_move_cost_;
	int current_move_cost_;

	int speed_;




};