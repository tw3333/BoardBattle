#pragma once

class UnitEnemy;
class Board;

class EnemyBehaviorStrategy {
public:
	



	virtual void Move(UnitEnemy* enemy, Board* board) = 0;
	virtual void Act(UnitEnemy* enemy, Board* board) = 0;

};