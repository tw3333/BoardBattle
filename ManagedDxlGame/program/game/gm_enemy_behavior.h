#pragma once

//memo
//UnitEnemy�̊e�s���̊��N���X
class Board;
class UnitEnemy;


class EnemyBehavior {
public:

	virtual void Move(UnitEnemy* turn_enemy, Board* board) = 0;
	virtual void Act(UnitEnemy* turn_enemy, Board* board) = 0;
	

};