#pragma once
#include "gm_enemy_behavior.h"

class HealPopoBehavior : public EnemyBehavior {
public:

	HealPopoBehavior(){}
	~HealPopoBehavior(){}

	void Move(UnitEnemy* turn_enemy, Board* board) override;
	void Act(UnitEnemy* turn_enemy, Board* board) override;





private:



};