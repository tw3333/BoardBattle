#pragma once
#include "gm_data_board.h"
#include <vector>
#include "gm_anim_manager.h"

//memo
//Enemy‚ÌˆÚ“®‚ðŽÀ‘•‚·‚éŠî’êƒNƒ‰ƒX
class Board;
class UnitEnemy;



class EnemyMove {
public:

	virtual void Move(UnitEnemy* turn_enemy, Board* board) = 0;

	SquarePos final_pos_;
	SquarePos target_pos_;
	SquarePos current_pos_;

	std::vector<SquarePos> move_route_;

};