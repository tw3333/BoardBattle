#pragma once
#include "gm_enemy_action.h"

class SlimeAction : public EnemyAction {
public:

	SlimeAction()
	:EnemyAction(board_squares_,party_)
	{}
	~SlimeAction(){}

	void Execute(UnitEnemy* unit_enemy) override;
	void Render(dxe::Camera* camera) override;

	void Move(UnitEnemy* unit_enemy);
	void Action(UnitEnemy* unit_enemy);
	bool IsAllyNearby(UnitEnemy* unit_enemy);
	bool IsAdjacentAlly(UnitEnemy* unit_enemy,UnitAlly* unit_ally);
	bool IsValidPosition(int row, int col) {
		return 0 <= row && row < 9 && 0 <= col && col < 9;
	}


private:

	int damage_ = 5;



};