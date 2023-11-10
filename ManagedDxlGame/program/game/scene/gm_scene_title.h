#pragma once
#include "gm_scene_base.h"

#include "DxLib.h"
#include "../gm_scene_manager.h"
#include "../gm_ui_title.h"


class SceneTitle : public SceneBase {
public:

	SceneTitle(){

	}
	~SceneTitle(){}

	void Initialzie() override;
	void Update(float delta_time) override;
	void Render() override;


private:

	SceneManager* scene_mgr_ = nullptr;
	UITitle* ui_title_ = nullptr;

	bool push_start_ = false;
	bool push_quit_game_ = false;
	
	int bgm_title_handle_ = 0;
	int se_push_button_handle_ = 0;

	
};