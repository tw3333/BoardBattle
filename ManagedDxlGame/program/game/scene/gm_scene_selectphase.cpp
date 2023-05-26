#include "gm_scene_selectphase.h"
#include "../gm_easingfunctions.h"
#include <memory>


void SceneSelectPhase::Initialzie() {

	CreateUIComponents();




}

void SceneSelectPhase::Update(float delta_time) {

	//ui_window_->Update(delta_time);

	for (auto uc : ui_components_) { uc->Update(delta_time); }
	


	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_D)) {

		if (is_sen) {
			is_sen = false;
		}
		else if(!is_sen) {
			is_sen = true;
		}
	}

}

void SceneSelectPhase::Render() {

	DrawStringEx(0,0,-1,"SceneSelectPhase");
	
	for (auto uc : ui_components_) { uc->Render(); }

	
	if (is_sen) {

		for (int i = 0; i < 10; ++i) {
			DrawLine(0, h1 + h1 * i, DXE_WINDOW_WIDTH, h1 + h1 * i, -1);
			DrawLine(w1 + w1 * i, 0, w1 + w1 * i, DXE_WINDOW_HEIGHT, -1);
		}

	}
	
	


}

void SceneSelectPhase::CreateUIComponents() {

	auto ui_background = std::make_shared<UIPanel>(0, 0, DXE_WINDOW_WIDTH, DXE_WINDOW_HEIGHT);
	ui_background->setColor(GetColor(255,255,255));
	ui_components_.push_back(ui_background);


	auto ui_panel = std::make_shared<UIPanel>(10,10,90,90);
	ui_panel->setGraphHandle(tmgr_->icon_dungeon_gate_->getDxLibGraphHandle());
	ui_mediator_->SetShowIconDungeonWindow(ui_panel);
	ui_components_.push_back(ui_panel);

	auto ui_panel_1 = std::make_shared<UIPanel>(10, 10, 90, 90);
	ui_panel_1->setGraphHandle(tmgr_->icon_character_->getDxLibGraphHandle());
	ui_panel_1->SetIsEnabled(false);
	ui_mediator_->SetShowIconCharacterWindow(ui_panel_1);
	ui_components_.push_back(ui_panel_1);

//	
	auto ui_button_1 = std::make_shared<UIButton>(12, 125,85,85);
	ui_button_1->setGraphHandle(tmgr_->icon_dungeon_gate_->getDxLibGraphHandle());
	ui_button_1->SetNotifyTag("SwitchDungeonWindow");
	ui_mediator_->SetSwitchDungeonWindowButton(ui_button_1);
	ui_components_.push_back(ui_button_1);

	auto ui_button_2 = std::make_shared<UIButton>(12, 220, 85, 85);
	ui_button_2->setGraphHandle(tmgr_->icon_character_->getDxLibGraphHandle());
	ui_button_2->SetNotifyTag("SwitchCharacterWindow");
	ui_mediator_->SetSwitchCharacterWindowButton(ui_button_2);
	ui_components_.push_back(ui_button_2);

//
	auto dungeon_window = std::make_shared<UIPanel>(110,10,1600 - 120,880);
	dungeon_window->setColor(GetColor(128,128,128));
	dungeon_window_components_.push_back(dungeon_window);
	ui_components_.push_back(dungeon_window);

	auto dungeon_tab_button = std::make_shared<UIButton>(w1*1,h1*1,w1*2,h1*1);
	dungeon_tab_button->setColor(GetColor(211,211,211));
	dungeon_window_components_.push_back(dungeon_tab_button);
	ui_components_.push_back(dungeon_tab_button);

	auto dungeon_party_edit_button = std::make_shared<UIButton>(w1 * 1, h1 * 3, w1 * 2, h1 * 1);
	dungeon_party_edit_button->setColor(GetColor(211, 211, 211));
	dungeon_window_components_.push_back(dungeon_party_edit_button);
	ui_components_.push_back(dungeon_party_edit_button);

	ui_mediator_->SetDungeonWindow(dungeon_window_components_);


}