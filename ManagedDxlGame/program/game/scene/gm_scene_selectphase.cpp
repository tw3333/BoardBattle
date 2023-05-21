#include "gm_scene_selectphase.h"

void SceneSelectPhase::Initialzie() {

	ui_window_ = new UIWindow();
	ui_window_->AddComponent(new UIPanel(50,50,100,100,0));
	ui_window_->Open();
	

}

void SceneSelectPhase::Update(float delta_time) {

	ui_window_->Update(delta_time);


}

void SceneSelectPhase::Render() {

	DrawStringEx(0,0,-1,"SceneSelectPhase");
	
	for (int i = 0; i < 10; ++i) {
		DrawLine(0, h1 + h1 * i, DXE_WINDOW_WIDTH, h1 + h1 * i, -1);
		DrawLine(w1 + w1 * i, 0, w1 + w1 * i, DXE_WINDOW_HEIGHT, -1);
	}

	ui_window_->Render();

}