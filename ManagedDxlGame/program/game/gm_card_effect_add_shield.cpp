#include "gm_card_effect_add_shield.h"

#include "gm_unit.h"
#include "gm_unit_ally.h"
#include "gm_board.h"

void CardEffectAddShield::Effect(std::vector<Unit*> units) {

	
	for (auto u : units) {

		if (u->GetUnitType() == UnitType::Ally) {

			UnitAlly* unit = static_cast<UnitAlly*>(u);
			unit->SetShieldValue(unit->GetShieldValue() + add_shield_value_);

		}

	}

}

bool CardEffectAddShield::CanEffectExcute(std::vector<SquarePos> target_square_pos, Board* board)
{

	for (auto pos : target_square_pos) {

		if (!board->getBoardSquare(pos.row, pos.col)->GetAllyPtrInSquare() && 
			!board->getBoardSquare(pos.row, pos.col)->GetEnemyPtrInSquare()) {

			return false;
		}

	}

	return true;
}

void CardEffectAddShield::EffectExcute(std::vector<SquarePos> target_square_pos, Board* board)
{

	for (auto square : target_square_pos) {

		board->getBoardSquare(square.row, square.col)->GetUnitPtrInSquare()->AddShieldValue(add_shield_value_);

	}

	anim_mgr_.AnimPlay("anim_shield", target_square_pos);

}
