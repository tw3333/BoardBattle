#include "gm_card_effect_add_shield.h"

#include "gm_unit.h"
#include "gm_unit_ally.h"

void CardEffectAddShield::Effect(std::vector<Unit*> units) {

	
	for (auto u : units) {

		if (u->GetUnitType() == UnitType::Ally) {

			UnitAlly* unit = static_cast<UnitAlly*>(u);
			unit->SetShieldValue(unit->GetShieldValue() + add_shield_value_);

		}

	}



}
