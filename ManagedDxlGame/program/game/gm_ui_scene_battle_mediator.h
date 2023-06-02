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


private:


	std::vector<UIComponent> ui_components_;

	tnl::Sequence<SceneBattle>* seq_;




};