#pragma once

//memo
//Enemy‚Ìs“®‚ğÀ‘•‚·‚éŠî’êƒNƒ‰ƒX

class Board;
class UnitEnemy;

class EnemyAct {
public:

	virtual void Act(UnitEnemy* turn_enemy, Board* board) = 0;


};