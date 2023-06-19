#pragma once
#include "gm_enemy_action.h"
#include <random>

class EnemyActionMove : public EnemyAction {
public:

	EnemyActionMove() {}
	~EnemyActionMove(){}

	bool IsValidPosition(int row, int col) {
		return 0 <= row && row < 9 && 0 <= col && col < 9;
	}


	//void Execute(UnitEnemy* unit_enemy) override;
	

	//i‚Þ•ûŒü
	enum class Direction {
		Up,
		Down,
		Left,
		Right
	};

private:

	std::mt19937 engine_{ std::random_device{}() };  // —”¶¬Ší
	std::uniform_int_distribution<int> distribution_;  // ˆê—l•ª•z

};