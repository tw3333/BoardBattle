#pragma once
#include "gm_unit.h"


class UnitEnemy : public Unit {
public:

	UnitEnemy(){}
	~UnitEnemy(){}


	void Update();

	void SetBoardPos();



private:


	//ステータス
	int max_hp_;
	int current_hp_;

	int max_card_cost_;
	int current_card_cost_;

	int max_move_cost_;
	int current_move_cost_;

	int speed_;

};