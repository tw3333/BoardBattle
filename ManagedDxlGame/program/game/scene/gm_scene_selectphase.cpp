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

	auto ui_panel = std::make_shared<UIPanel>(10,10,90,90);
	ui_panel->setGraphHandle(tmgr_->icon_dungeon_gate_->getDxLibGraphHandle());
	ui_components_.push_back(ui_panel);

	auto ui_panel2 = std::make_shared<UIPanel>(10,120,90,700);
	ui_components_.push_back(ui_panel2);

	//auto ui_panel3 = std::make_shared<UIPanel>(110,10,w1*2, 90);
	//ui_components_.push_back(ui_panel3);
	
	auto ui_button_1 = std::make_shared<UIButton>(12, 125,85,85);
	ui_button_1->setGraphHandle(tmgr_->icon_dungeon_gate_->getDxLibGraphHandle());
	ui_components_.push_back(ui_button_1);



	UIButton* ui_button_2 = new UIButton(100, 100, w1 * 2, h1 * 1);
	ui_button_2->SetEasingFunction(std::make_unique<EaseOutExpo>());
	ui_button_2->SetStartEasing(-100, 0);



}