#pragma once

//memo
//Enemy‚ÌˆÚ“®‚ğÀ‘•‚·‚éŠî’êƒNƒ‰ƒX
class Board;
class UnitEnemy;



class EnemyMove {
public:

	virtual void Move(UnitEnemy* turn_enemy, Board* board) = 0;


};