#pragma once
#include "gm_battle_phase.h"

//memo
//‰½‚às“®(PlayerAction)‚ğs‚í‚È‚¢Phase‚àŒ“‚Ë‚Ä‚¢‚é


class PhaseTurnAlly : public BattlePhase {
public:

	PhaseTurnAlly(){}
	~PhaseTurnAlly(){}


	void BeginPhase() override;
	void EndPhase() override;

	bool UpdateExecute(float delta_time) override;
	bool RenderExecute(dxe::Camera* camera) override;



private:






};

