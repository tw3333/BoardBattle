#include "gm_ui_dungeon_window.h"


void DungeonWindow::Update(float delta_time) {

	if (is_enabled_) {
		//window_->Update(delta_time);
		//switch_dungeon_tab_->Update(delta_time);
		//switch_partyedit_tab_->Update(delta_time);
		//window_dungeon_tab_->Update(delta_time);

		for (auto dwc : dungeon_window_components_) {

			dwc->Update(delta_time);
		}
	}




}

void DungeonWindow::Render() {

	if (is_enabled_) {
		//window_->Render();
		//switch_dungeon_tab_->Render();
		//switch_partyedit_tab_->Render();
		//window_dungeon_tab_->Render();

		for (auto dwc : dungeon_window_components_) {

			dwc->Render();
		}


	}
		


}

void DungeonWindow::Create() {

	//Window
	window_ = std::make_shared<UIPanel>(window_posx_, window_posy_, window_w_, window_h_);
	window_->setColor(GetColor(128, 128, 128));

	window_dungeon_tab_ = std::make_shared<UIPanel>(window_posx_ + button_w_ + 70, window_posy_ + 30, 1160,790);
	window_dungeon_tab_->setColor(GetColor(50,50,50));
	
	switch_dungeon_tab_ = std::make_shared<UIButton>(window_posx_ + 40, window_posy_ + 30,button_w_,button_h_);
	//switch_dungeon_tab_->setGraphHandle(tmgr_->panel_dungeon_->getDxLibGraphHandle());
	switch_dungeon_tab_->SetNotifyTag("SwitchDungeonTab");



	switch_partyedit_tab_ = std::make_shared<UIButton>(window_posx_ + 40, window_posy_ + button_h_ + 80, button_w_,button_h_);

	dungeon_window_components_.push_back(window_);
	dungeon_window_components_.push_back(window_dungeon_tab_);
	dungeon_window_components_.push_back(switch_dungeon_tab_);
	dungeon_window_components_.push_back(switch_partyedit_tab_);

	//auto dungeon_tab_button = std::make_shared<UIButton>(w1 * 1, h1 * 1, w1 * 1 + w1 * 1 / 2, h1 * 1);
	//dungeon_tab_button->setColor(GetColor(211, 211, 211));
	//dungeon_tab_button->SetNotifyTag("SwitchDungeonTab");
	//dungeon_window_components_.push_back(dungeon_tab_button);
	//ui_components_.push_back(dungeon_tab_button);

	//auto dungeon_tab = std::make_shared<UIPanel>(w1 * 1 + w1 * 1 / 2 + 10, h1 * 1, w1 * 5, h1 * 5);
	//dungeon_tab->setColor(GetColor(50, 50, 50));
	//dungeon_tab->SetIsEnabled(false);
	//dungeon_window_components_.push_back(dungeon_tab);
	//ui_components_.push_back(dungeon_tab);

	//auto dungeon_party_edit_button = std::make_shared<UIButton>(w1 * 1, h1 * 3, w1 * 1 + w1 * 1 / 2, h1 * 1);
	//dungeon_party_edit_button->setColor(GetColor(211, 211, 211));

	//dungeon_window_components_.push_back(dungeon_party_edit_button);
	//ui_components_.push_back(dungeon_party_edit_button);

	//ui_mediator_->SetDungeonWindow(dungeon_window_components_);




}

