#include "gm_battle_phase_unit_speed_cal.h"

#include <iostream>
#include <algorithm>

void PhaseUnitSpeedCal::BeginPhase() {

	//条件から抽出
	for (auto au : all_units_) {
		if (!au->GetIsDead() && !au->GetIsActed()) {
			cal_units_.push_back(au);
		}
	}

	//std::sort(cal_units_.begin(),cal_units_.end(),CompareUnits);

	std::sort(cal_units_.begin(), cal_units_.end(),
		[](Unit* a, Unit* b) {
			return a->GetSpeed() > b->GetSpeed();
		});


	if (!cal_units_.empty()) {
		turn_unit_ = cal_units_.front();
	}

	//ToDo:関数化
	if (turn_unit_->GetUnitType() == UnitType::Ally) {
		turn_ally_ = static_cast<UnitAlly*>(turn_unit_);
		is_calculated_ = true;
	}
	else if (turn_unit_->GetUnitType() == UnitType::Enemy) {
		turn_enemy_ = static_cast<UnitEnemy*>(turn_unit_);
		is_calculated_ = true;
	}

	
}

void PhaseUnitSpeedCal::EndPhase() {


	is_calculated_ = false;


}

bool PhaseUnitSpeedCal::UpdateExecute(float delta_time) {

	DrawStringEx(500,0,-1,"PhaseSpeedCal");

	//計算終了後AllyorEnemyTurnへ移行
	if (is_calculated_) {

		//条件から抽出
		for (auto au : all_units_) {
			if (!au->GetIsDead() && !au->GetIsActed()) {
				cal_units_.push_back(au);
			}
		}

		//std::sort(cal_units_.begin(),cal_units_.end(),CompareUnits);

		std::sort(cal_units_.begin(), cal_units_.end(),
			[](Unit* a, Unit* b) {
				return a->GetSpeed() > b->GetSpeed();
			});


		if (!cal_units_.empty()) {
			turn_unit_ = cal_units_.front();
		}

		//ToDo:関数化
		if (turn_unit_->GetUnitType() == UnitType::Ally) {
			turn_ally_ = static_cast<UnitAlly*>(turn_unit_);
			is_calculated_ = true;
		
		}
		else if (turn_unit_->GetUnitType() == UnitType::Enemy) {
			turn_enemy_ = static_cast<UnitEnemy*>(turn_unit_);
			is_calculated_ = true;
		}

	}



	return true;
}

bool PhaseUnitSpeedCal::RenderExecute(dxe::Camera* camera) {
	
	
	
	
	
	return true;
}
