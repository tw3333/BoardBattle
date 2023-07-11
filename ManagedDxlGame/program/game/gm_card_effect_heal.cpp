#include "gm_card_effect.h"
#include "gm_card_effect_heal.h"

#include "gm_unit.h"
#include "gm_unit_ally.h"


void CardEffectHeal::Effect(std::vector<Unit*> units) {

	
	for (auto u : units) {

		if (u->GetUnitType() == UnitType::Ally) {

			UnitAlly* unit = static_cast<UnitAlly*>(u);
			unit->IncreareCurrentHp(heal_amount_);

		}

	}


}
     