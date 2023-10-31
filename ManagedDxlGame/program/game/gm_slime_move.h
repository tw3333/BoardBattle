#pragma once
#include "gm_enemy_move.h"
#include <random>
#include <chrono>
#include <iostream>
#include "gm_data_board.h"


// ƒOƒ[ƒoƒ‹‚È—”¶¬Ší
static std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

class SlimeMove : public EnemyMove {
public:

	SlimeMove() {};
	~SlimeMove() {};


	void Move(UnitEnemy* turn_enemy, Board* board) override;
	bool IsAllyAdjacent(UnitEnemy* turn_enemy, Board* board);



	
};