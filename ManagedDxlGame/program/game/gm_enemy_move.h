#pragma once

//memo
//Enemyの移動を実装する基底クラス
class Board;
class UnitEnemy;



class EnemyMove {
public:

	virtual void Move(UnitEnemy* turn_enemy, Board* board) = 0;


};