#pragma once
#include "gm_battle_phase.h"

class PhaseTurnEnd : public BattlePhase {
public:

	PhaseTurnEnd(){}
	~PhaseTurnEnd(){}

	void BeginPhase()override;
	void EndPhase() override;
	bool UpdateExecute(float delta_time) override;
	bool RenderExecute(dxe::Camera* camera) override;





private:







};