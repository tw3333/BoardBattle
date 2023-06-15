#pragma once
#include "gm_ui_component.h"
#include "gm_ui_mediator.h"

#include "gm_battle_phase_player_action_move.h"

class SceneBattle;

class UISceneBattleMediator : public UIMediator {
public:

	UISceneBattleMediator(){}
	~UISceneBattleMediator(){}


	//void SetMediator() {


	//}
	void SetScene(SceneBattle* scene) { scene_battle_ = scene; }

	void Notify(UIComponent* sender, std::string tag) override;
	void SetSequence(tnl::Sequence<SceneBattle>* seq) {	phase_ = seq; }

	//UIPlayerActionButtons
	void NotifyPlayerActionButton(bool is_enable, std::string tag);
	void SetIsPlayerActionButtonEnabled(bool flag) { is_player_action_button_enabled_ = flag; }

	//BattlePhase
	void SetPhasePlayerActionMove(PhasePlayerActionMove* p) { phase_player_action_move_ = p; }



private:

	bool is_player_action_button_enabled_ = false;

	std::vector<UIComponent> ui_components_;

	tnl::Sequence<SceneBattle>* phase_;

	SceneBattle* scene_battle_ = nullptr;

	PhasePlayerActionMove* phase_player_action_move_ = nullptr;


};