#include "gm_enemy_action_move.h"


void EnemyActionMove::Execute(UnitEnemy* unit_enemy) {

	if (unit_enemy->GetMoveType() == UnitEnemy::MoveType::NotMove) {
		return;
	}

	if (unit_enemy->GetMoveType() == UnitEnemy::MoveType::RandomMove) {
		
		int remaining_cost = unit_enemy->GetCurrentMoveCost();

		while (remaining_cost > 0)
		{
			Direction direction = static_cast<Direction>(distribution_(engine_));  // ƒ‰ƒ“ƒ_ƒ€‚É•ûŒü‚ð‘I‘ð

			int next_row = unit_enemy->GetBoardPos().row;
			int next_col = unit_enemy->GetBoardPos().col;

			switch (direction) {
			case Direction::Up:
				next_row -= 1;
				break;
			case Direction::Down:
				next_row += 1;
				break;
			case Direction::Left:
				next_col -= 1;
				break;
			case Direction::Right:
				next_col += 1;
				break;
			}
			
			if (IsValidPosition(next_row, next_col)) {
				unit_enemy->SetBoardPos(next_row, next_col);
				remaining_cost--;
			}

		}

		unit_enemy->SetCurrentMoveCost(0);
		
		return;
	}

	if (unit_enemy->GetMoveType() == UnitEnemy::MoveType::ForcusMove) {





		return;
	}




}
