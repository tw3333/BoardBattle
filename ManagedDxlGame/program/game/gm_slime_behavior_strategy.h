#pragma once
#include "gm_enemy_behavior_strategy.h"

class UnitEnemy;
class UnitAlly;
class Board;


class SlimeBehaviorStrategy : public EnemyBehaviorStrategy {
public:

	void Move(UnitEnemy* act_enemy, Board* board) override;
	void Act(UnitEnemy* act_enemy, Board* board) override;




};