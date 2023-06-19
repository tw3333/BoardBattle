#pragma once
#include "gm_enemy_action.h"

class Square;
class UnitAlly;
class UnitEnemy;

class SlimeAction : public EnemyAction {
public:

	SlimeAction(){}
	~SlimeAction(){}

	//void Execute(UnitEnemy* unit_enemy) override;
	//void Render(dxe::Camera* camera) override;

	void Move(UnitEnemy* action_enemy, std::vector<UnitAlly*> party, std::vector<UnitEnemy*> enemies, const std::array<std::array<Square*, 10>, 10>& squares) override;
	void Action(UnitEnemy* action_enemy, std::vector<UnitAlly*> party, std::vector<UnitEnemy*> enemies, const std::array<std::array<Square*, 10>, 10>& squares) override;

	void Execute(UnitEnemy* action_enemy, std::vector<UnitAlly*> party, std::vector<UnitEnemy*> enemies, const std::array<std::array<Square*, 10>, 10>& squares) override;
	void Render(dxe::Camera* camera) override;




private:

	int damage_ = 5;



};