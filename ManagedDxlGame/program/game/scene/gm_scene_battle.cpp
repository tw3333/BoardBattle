#include "gm_scene_battle.h"

void SceneBattle::Initialzie() {

	camera_ = new SceneBattleCamera();
	camera_->pos_ = { 0,680,-605 };

	




}

void SceneBattle::Update(float delta_time) {

	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_U)) {

		if (!is_draw_debug_layout_) {
			is_draw_debug_layout_ = true;
		}
		else if (is_draw_debug_layout_) {
			is_draw_debug_layout_ = false;
		}

	}





}

void SceneBattle::Render() {

	camera_->update();
	
	DrawStringEx(0,0,-1,"SceneBattle");

	DrawDebugLayOut(is_draw_debug_layout_);
	

	DrawBox(0,0,1280,720,0,true);

}


//=====ƒƒ“ƒoŠÖ”ŒQ====================================================================

void SceneBattle::DrawDebugLayOut(bool is_draw) {

	if (is_draw) {
		for (int i = 0; i < 10; ++i) {
			DrawLine(0, h1 + h1 * i, DXE_WINDOW_WIDTH, h1 + h1 * i, -1);
			DrawLine(w1 + w1 * i, 0, w1 + w1 * i, DXE_WINDOW_HEIGHT, -1);
		}
	}

	DrawGridGround(camera_, 50, 20);

}