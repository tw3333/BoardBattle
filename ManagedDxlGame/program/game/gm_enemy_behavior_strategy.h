#pragma once

class UnitEnemy;
class Board;

class EnemyBehaviorStrategy {
public:
	
	virtual void Move(UnitEnemy* turn_enemy, Board* board) = 0;
	virtual void Act(UnitEnemy* turn_enemy, Board* board) = 0;

};