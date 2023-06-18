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

	void move(UnitEnemy* unit_enemy);
	void Action(UnitEnemy* unit_enemy);


private:





};