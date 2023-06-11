#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include "gm_battle_phase.h"

class PhasePlayerActionCard : public BattlePhase {
public:

	PhasePlayerActionCard(){}
	~PhasePlayerActionCard(){}


	void BeginPhase()override;
	void EndPhase() override;
	bool UpdateExecute(float delta_time) override;
	bool RenderExecute(dxe::Camera* camera) override;




private:








};
