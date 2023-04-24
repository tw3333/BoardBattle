#pragma once
#include "gm_scene_base.h"

#include "../gm_scene_manager.h"
#include "../gm_scene_battle_camera.h"

//memo
//戦闘シーンのSceneクラス

class SceneBattle : public SceneBase {
public:

	SceneBattle() {}
	~SceneBattle(){}

	void Initialzie() override;
	void Update(float delta_time) override;
	void Render() override;

	//メンバ関数
	void DrawDebugLayOut(bool is_draw);


private:
	
	int w1 = DXE_WINDOW_WIDTH / 10;
	int h1 = DXE_WINDOW_HEIGHT / 10;

	//メンバ変数
	//pointer
	SceneBattleCamera* camera_ = nullptr;

	dxe::Mesh* kari_board_ = nullptr;

	//bool
	bool is_draw_debug_layout_ = false;


};