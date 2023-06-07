#pragma once
#include "gm_ui_component.h"
#include "gm_ui_mediator.h"

class SceneBattle;

class UISceneBattleMediator : public UIMediator {
public:

	UISceneBattleMediator(){}
	~UISceneBattleMediator(){}


	//void SetMediator() {


	//}

	void Notify(UIComponent* sender, std::string tag) override;
	void SetSequence(tnl::Sequence<SceneBattle>* seq) {	seq_ = seq; }

	//UIPlayerActionButtons
	void NotifyPlayerActionButton(bool is_enable, std::string tag);
	void SetIsPlayerActionButtonEnabled(bool flag) { is_player_action_button_enabled_ = flag; }



private:

	bool is_player_action_button_enabled_ = false;

	std::vector<UIComponent> ui_components_;

	tnl::Sequence<SceneBattle>* seq_;




};