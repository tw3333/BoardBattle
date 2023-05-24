#pragma once
#include "gm_ui_component.h"
#include "gm_ui_mediator.h"
#include "gm_ui_panel.h"
#include "gm_ui_button.h"
#include <vector>
#include <memory>

//memo
//SceneSelectPhase‚É‘Î‰ž‚µ‚½AConcreteMediatorƒNƒ‰ƒX


class UISelectPhaseMediator : public UIMediator {
public:

	UISelectPhaseMediator() {}
	~UISelectPhaseMediator(){}



	void SetMediators() { 
		for (auto uc : ui_components_) { uc->SetMediator(this); } 
	}

	void Notify(UIComponent* sender, std::string event) override;

	void SetShowWhichWindowPanel(Shared<UIPanel> ui_component) {
		this->panel_show_which_window_->SetMediator(this);
	};

private:

	std::vector<UIComponent*> ui_components_;


	Shared<UIPanel> panel_show_which_window_ = nullptr;
	Shared<UIButton> button_switch_dungeon_window_ = nullptr;
	Shared<UIButton> button_switch_character_window_ = nullptr;





};
