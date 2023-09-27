#pragma once
#include "gm_enemy_act.h"

#include "gm_sound_manager.h"

class SlimeAct : public EnemyAct {
public:

	SlimeAct() {}
	~SlimeAct() {}

	void Act(UnitEnemy* turn_enemy, Board* board) override;

private:
	
	SoundManager& mgr = SoundManager::GetInstance();

};