#include "gm_scene_battle.h"

void SceneBattle::Initialzie() {

}

void SceneBattle::Update(float delta_time) {

}

void SceneBattle::Render() {

	
	DrawStringEx(0,0,-1,"SceneBattle");

	for (int i = 0; i < 10; ++i) {
		DrawLine(0, h1 + h1 * i, DXE_WINDOW_WIDTH, h1 + h1 * i, -1);
		DrawLine(w1 + w1 * i, 0, w1 + w1 * i, DXE_WINDOW_HEIGHT, -1);
	}

}

