#pragma once

//memo
//Enemy�̍s��������������N���X

class Board;
class UnitEnemy;

class EnemyAct {
public:

	virtual void Act(UnitEnemy* turn_enemy, Board* board) = 0;


};