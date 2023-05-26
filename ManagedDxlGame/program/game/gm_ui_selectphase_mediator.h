#pragma once
#include "gm_ui_component.h"
#include "gm_ui_mediator.h"
#include "gm_ui_panel.h"
#include "gm_ui_button.h"
#include "gm_ui_dungeon_window.h"
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

	void SetShowIconDungeonWindow(Shared<UIPanel> ui_panel) {
		panel_icon_dungeon_window_ = ui_panel;
		this->panel_icon_dungeon_window_->SetMediator(this);
	}

	void SetShowIconCharacterWindow(Shared<UIPanel> ui_panel) {
		panel_icon_character_window_ = ui_panel;
		this->panel_icon_character_window_ ->SetMediator(this);
	}

	void SetSwitchDungeonWindowButton(Shared<UIButton> ui_button) {
		button_switch_dungeon_window_ = ui_button;
		this->button_switch_dungeon_window_->SetMediator(this);
	}

	void SetSwitchCharacterWindowButton(Shared<UIButton> ui_button) {
		button_switch_character_window_ = ui_button;
		this->button_switch_character_window_->SetMediator(this);
	}

	void SetDungeonWindow(Shared<DungeonWindow> window) {
		dungeon_window_ = window;
		this->dungeon_window_->SetMediator(this);
	}

	void SetCharacterWindow(std::vector<std::shared_ptr<UIComponent>> window) {
		character_window_ = window;
	}

	void SetTest(std::vector<std::shared_ptr<UIComponent>> window) {

		d_window_ = window;
		for (auto d : d_window_) {
			d->SetMediator(this);
		}

	}

private:

	std::vector<UIComponent*> ui_components_;
	Shared<UIPanel> panel_show_which_window_ = nullptr;
	
	Shared<UIPanel> panel_icon_dungeon_window_ = nullptr;
	Shared<UIPanel> panel_icon_character_window_ = nullptr;


	Shared<UIButton> button_switch_dungeon_window_ = nullptr;
	Shared<UIButton> button_switch_character_window_ = nullptr;

//dungeonwindow
	Shared<UIButton> button_switch_dungeon_tab_ = nullptr;
	Shared<UIButton> button_switch_partyedit_tab_ = nullptr;

	std::vector<std::shared_ptr<UIComponent>> character_window_;

	Shared<DungeonWindow> dungeon_window_;

	std::vector<Shared<UIComponent>> d_window_;

};
