#pragma once
#include "gm_battle_phase.h"

class PhaseTurnEnemy : public BattlePhase {
public:

	PhaseTurnEnemy(){}
	~PhaseTurnEnemy(){}


	void BeginPhase() override;
	void EndPhase() override;

	bool UpdateExecute(float delta_time) override;
	bool RenderExecute(dxe::Camera* camera) override;



private:







};