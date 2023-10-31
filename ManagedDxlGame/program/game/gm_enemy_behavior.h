#pragma once

//memo
//UnitEnemyの各行動の基底クラス
class Board;
class UnitEnemy;


class EnemyBehavior {
public:

	virtual void Move(UnitEnemy* turn_enemy, Board* board) = 0;
	virtual void Act(UnitEnemy* turn_enemy, Board* board) = 0;
	

};