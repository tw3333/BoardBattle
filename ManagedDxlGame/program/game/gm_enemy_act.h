#pragma once

//memo
//Enemyの行動を実装する基底クラス

class Board;
class UnitEnemy;

class EnemyAct {
public:

	virtual void Act(UnitEnemy* turn_enemy, Board* board) = 0;


};