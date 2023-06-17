#pragma once
#include <array>

#include "gm_square.h"
#include "gm_unit.h"
#include "gm_unit_ally.h"
#include "gm_unit_enemy.h"



class EnemyAction {
public:


	EnemyAction(std::array<std::array<Square*, 10>, 10> board_squares)
	: board_squares_(board_squares)
	{}

	virtual ~EnemyAction() {}


	virtual void execute(UnitEnemy* unit_enemy) = 0;






private:



protected:


	std::array<std::array<Square*, 10>, 10> board_squares_;


};