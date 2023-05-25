#pragma once
#include "gm_ui_component.h"
#include "gm_ui_mediator.h"
#include "gm_ui_panel.h"
#include "gm_ui_button.h"
#include <vector>
#include <memory>

//memo
//SceneSelectPhaseÇ…ëŒâûÇµÇΩÅAConcreteMediatorÉNÉâÉX


class UISelectPhaseMediator : public UIMediator {
public:

	UISelectPhaseMediator() {}
	~UISelectPhaseMediator(){}


	void Notify(UIComponent* sender, std::string tag) override;

	void SetShowWhichWindowPanel(Shared<UIButton> ui_component) {
		button_switch_character_window_ = ui_component;
		this->button_switch_character_window_->SetMediator(this);
	};

	void SetSwitchDungeonWindowButton(Shared<UIButton> ui_button) {
		button_switch_dungeon_window_ = ui_button;
		this->button_switch_dungeon_window_->SetMediator(this);
	}

	void SetSwitchCharacterWindowButton(Shared<UIButton> ui_button) {
		button_switch_character_window_ = ui_button;
		this->button_switch_character_window_->SetMediator(this);
	}




private:

	std::vector<UIComponent*> ui_components_;


	Shared<UIPanel> panel_show_which_window_ = nullptr;
	Shared<UIButton> button_switch_dungeon_window_ = nullptr;
	Shared<UIButton> button_switch_character_window_ = nullptr;





};
