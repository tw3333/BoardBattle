#include "gm_card_effect_add_taunt.h"

#include "gm_unit.h"
#include "gm_unit_ally.h"

void CardEffectAddTaunt::Effect(std::vector<Unit*> untis) {

	for (auto u : untis) {

		if (u->GetUnitType() == UnitType::Ally) {

			UnitAlly* unit = static_cast<UnitAlly*>(u);
			unit->SetTauntValue(unit->GetTauntValue() + add_taunt_value_);

		}

	}

}
