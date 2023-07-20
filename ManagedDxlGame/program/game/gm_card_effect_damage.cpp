#include "gm_card_effect_damage.h"

#include "gm_unit.h"
#include "gm_unit_ally.h"
#include "gm_unit_enemy.h"


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
