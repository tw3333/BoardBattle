#pragma once

//memo
//Enemy�̈ړ�������������N���X
class Board;
class UnitEnemy;



class EnemyMove {
public:

	virtual void Move(UnitEnemy* turn_enemy, Board* board) = 0;


};