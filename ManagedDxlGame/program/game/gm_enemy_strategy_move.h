#pragma once
#include <array>
#include <vector>

#include "gm_unit.h"
#include "gm_unit_ally.h"
#include "gm_unit_enemy.h"
#include "gm_square.h"



class EnemyMoveStrategy {
public:

	virtual void Move(UnitEnemy* action_enemy, std::vector<UnitAlly*> party, std::vector<UnitEnemy*> enemies, std::array<std::array<Square*, 10>, 10>& squares) = 0;



private:
protected:





};