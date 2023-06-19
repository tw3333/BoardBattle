#pragma once
#include <array>
#include <cmath>

#include "gm_square.h"
#include "gm_unit.h"
#include "gm_unit_ally.h"
#include "gm_unit_enemy.h"

class Square;
class UnitAlly;
class UnitEnemy;

class EnemyAction {
public:


	virtual ~EnemyAction() {}


	virtual void Move(UnitEnemy* action_enemy, std::vector<UnitAlly*> party, std::vector<UnitEnemy*> enemies, const std::array<std::array<Square*, 10>, 10>& squares) = 0; //各Enemyの移動
	virtual void Action(UnitEnemy* action_enemy, std::vector<UnitAlly*> party, std::vector<UnitEnemy*> enemies,  const std::array<std::array<Square*, 10>, 10>& squares) = 0; //各Enemyの特有のAction

	virtual void Execute(UnitEnemy* action_enemy,std::vector<UnitAlly*> party, std::vector<UnitEnemy*> enemies, const std::array<std::array<Square*, 10>, 10>& squares) = 0; //各Enemyの行動
	virtual void Render(dxe::Camera* camera) = 0; //Effectの描画




private:


protected:
	
	bool IsAdjacentAlly(UnitEnemy* unit_enemy, UnitAlly* unit_ally);
	bool IsAllyNearby(UnitEnemy* unit_enemy, std::vector<UnitAlly*> party);
	bool IsValidPosition(int row, int col) {
		return 0 <= row && row < 9 && 0 <= col && col < 9;
	}


};