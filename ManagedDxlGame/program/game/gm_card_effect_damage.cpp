#include "gm_card_effect_damage.h"

#include "gm_unit.h"
#include "gm_unit_ally.h"
#include "gm_unit_enemy.h"
#include "gm_board.h"


void CardEffectDamage::Effect(std::vector<Unit*> units) {

	for (auto u : units) {


		if (u->GetUnitType() == UnitType::Ally) {
			
			UnitAlly* unit = static_cast<UnitAlly*>(u);
			unit->DecreaseCurrentHp(damage_);


		}
		else if (u->GetUnitType() == UnitType::Enemy) {
		
			UnitEnemy* unit = static_cast<UnitEnemy*>(u);
			unit->DecreaseCurrentHp(damage_);	
			
		}

	}



}

void CardEffectDamage::EffectExcute(std::vector<SquarePos> target_square_pos, Board* board) {

	bool ally_attack = false;

	for (auto pos : target_square_pos) {

		if (board->getBoardSquare(pos.row,pos.col)->GetAllyPtrInSquare()) {

			board->getBoardSquare(pos.row, pos.col)->GetAllyPtrInSquare()->DecreaseCurrentHp(damage_);


		}
		else if(board->getBoardSquare(pos.row, pos.col)->GetEnemyPtrInSquare()) {

			board->getBoardSquare(pos.row, pos.col)->GetEnemyPtrInSquare()->DecreaseCurrentHp(damage_);
			ally_attack = true;
		}
	}

	if (ally_attack) {

		for (auto ally : board->GetPartyUnitsInBoard()) {

			if (ally->GetIsTurn()) {
				ally->AddTaundValue(3);
			}

		}

	}

}

bool CardEffectDamage::CanEffectExcute(std::vector<SquarePos> target_square_pos, Board* board)
{

	for (auto pos : target_square_pos) {

		if (!board->getBoardSquare(pos.row, pos.col)->GetAllyPtrInSquare() && 
			!board->getBoardSquare(pos.row, pos.col)->GetEnemyPtrInSquare()) {
			
			return false;
		}

	}

	return true;
}
