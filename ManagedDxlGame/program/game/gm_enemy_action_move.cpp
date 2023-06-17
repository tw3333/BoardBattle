#include "gm_enemy_action_move.h"

void EnemyActionMove::Execute(UnitEnemy* unit_enemy) {

	if (unit_enemy->GetMoveType() == UnitEnemy::MoveType::NotMove) {
		return;
	}

	if (unit_enemy->GetMoveType() == UnitEnemy::MoveType::RandomMove) {
		
		//unit_enemy->

		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < 10; ++j) {


			}
		}




		return;
	}

	if (unit_enemy->GetMoveType() == UnitEnemy::MoveType::ForcusMove) {




	}




}
