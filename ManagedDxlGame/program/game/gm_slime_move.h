#pragma once
#include "gm_enemy_move.h"

class SlimeMove : public EnemyMove
{
public:

	SlimeMove() {};
	~SlimeMove() {};


	void Move(UnitEnemy* turn_enemy, Board* board) override;




};