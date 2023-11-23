#include "gm_card_effect.h"
#include "gm_card_effect_heal.h"

#include "gm_unit.h"
#include "gm_unit_ally.h"
#include "gm_unit_enemy.h"
#include "gm_board.h"


void CardEffectHeal::Effect(std::vector<Unit*> units) 
{
	for (auto u : units) {

		if (u->GetUnitType() == UnitType::Ally) {

			UnitAlly* unit = static_cast<UnitAlly*>(u);
			unit->IncreareCurrentHp(heal_amount_);

		}

	}
}

void CardEffectHeal::EffectExcute(std::vector<SquarePos> target_square_pos, Board* board)
{
	bool ally_heal = false;


	for (auto &pos : target_square_pos) {

		if (board->getBoardSquare(pos.row, pos.col)->GetAllyPtrInSquare()) {

			board->getBoardSquare(pos.row, pos.col)->GetAllyPtrInSquare()->IncreareCurrentHp(heal_amount_);
			ally_heal = true;

		}
		else if (board->getBoardSquare(pos.row, pos.col)->GetEnemyPtrInSquare()) {

			board->getBoardSquare(pos.row, pos.col)->GetEnemyPtrInSquare()->IncreareCurrentHp(heal_amount_);
		}

	}

	if (ally_heal) {

		for (auto ally : board->GetPartyUnitsInBoard()) {

			if (ally->GetIsTurn()) {
				ally->AddTaundValue(3);
			}

		}

	}

	
}

bool CardEffectHeal::CanEffectExcute(std::vector<SquarePos> target_square_pos, Board* board)
{
	for (auto pos : target_square_pos) {

		if (!board->getBoardSquare(pos.row, pos.col)->GetAllyPtrInSquare() &&
			!board->getBoardSquare(pos.row, pos.col)->GetEnemyPtrInSquare()) {

			return false;
		}

	}
}
     