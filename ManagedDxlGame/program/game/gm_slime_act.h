#pragma once
#include "gm_enemy_act.h"


class SlimeAct : public EnemyAct {
public:

	SlimeAct(int damage) {
		damage_ = damage;
	
	}
	~SlimeAct() {}

	void Act(UnitEnemy* turn_enemy, Board* board) override;

private:

	int damage_ = 0;

};