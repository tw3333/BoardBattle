#pragma once
#include <array>

#include "gm_square.h"
#include "gm_unit.h"
#include "gm_unit_ally.h"
#include "gm_unit_enemy.h"



class EnemyAction {
public:


	EnemyAction(std::array<std::array<Square*, 10>, 10>& board_squares,std::vector<UnitAlly*>& party)
	: board_squares_(board_squares),party_(party)
	{}

	virtual ~EnemyAction() {}


	virtual void Execute(UnitEnemy* unit_enemy) = 0;






private:



protected:


	std::array<std::array<Square*, 10>, 10>& board_squares_;
	std::vector<UnitAlly*>& party_;

};