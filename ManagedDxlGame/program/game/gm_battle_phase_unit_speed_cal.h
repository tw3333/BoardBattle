#pragma once
#include "gm_battle_phase.h"

#include <vector>

#include "gm_unit.h"
#include "gm_unit_ally.h"
#include "gm_unit_enemy.h"

//memo
//Unit�S�̂�Speed�l�̂Ń^�[�������߂�Phase



class PhaseUnitSpeedCal : public BattlePhase {
public:

	PhaseUnitSpeedCal(std::vector<Unit*> all_units, UnitAlly* turn_ally, UnitEnemy* turn_enemy)
	:all_units_(all_units), turn_ally_(turn_ally), turn_enemy_(turn_enemy)
	{}
	~PhaseUnitSpeedCal(){}



	void BeginPhase() override;
	void EndPhase() override;

	bool UpdateExecute(float delta_time) override;
	bool RenderExecute(dxe::Camera* camera) override;


	//�~���\�[�g�p
	bool CompareUnits(Unit* unit1,Unit* unit2) {
		return unit1->GetSpeed() > unit2->GetSpeed();
	}




private:

	std::vector<Unit*> all_units_; //Board��ɂ���Unit
	
	std::vector<Unit*> cal_units_; //�������o�p

	Unit* turn_unit_ = nullptr;
	UnitAlly* turn_ally_ = nullptr;
	UnitEnemy* turn_enemy_ = nullptr;

	bool is_calculated_ = true;



};