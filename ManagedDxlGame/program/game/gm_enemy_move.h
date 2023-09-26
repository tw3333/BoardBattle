#pragma once
#include "gm_data_board.h"

//memo
//Enemy�̈ړ�������������N���X
class Board;
class UnitEnemy;



class EnemyMove {
public:

	virtual void Move(UnitEnemy* turn_enemy, Board* board) = 0;

	SquarePos final_pos_;
	SquarePos target_pos_;
	SquarePos current_pos_;
};