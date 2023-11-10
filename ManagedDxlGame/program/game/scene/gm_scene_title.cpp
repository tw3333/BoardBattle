#include "gm_scene_title.h"

#include "gm_scene_load.h"

void SceneTitle::Initialzie() {

	bgm_title_handle_ = LoadSoundMem("sound/bgm/scenetitle_back.mp3");
	se_push_button_handle_ = LoadSoundMem("sound/se/ui_se/se_push_title_button.mp3");
	ChangeVolumeSoundMem(70, bgm_title_handle_);
	PlaySoundMem(bgm_title_handle_, DX_PLAYTYPE_LOOP, true);

	ui_title_ = new UITitle();

}

void SceneTitle::Update(float delta_time) {

	SceneManager* scene_mgr_ = SceneManager::GetInstance();

	ui_title_->Update(delta_time);

	if (ui_title_->GetIsPushStartButton()) {
		PlaySoundMem(se_push_button_handle_,DX_PLAYTYPE_BACK,true);
		StopSoundMem(bgm_title_handle_);
		scene_mgr_->ChengeScene(new SceneLoad());
	}
	if (ui_title_->GetIsPushQuitGameButton()) {
		PlaySoundMem(se_push_button_handle_, DX_PLAYTYPE_BACK, true);
		StopSoundMem(bgm_title_handle_);
		DxLib_End();
	}

	//Debug
	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_D)) {
		StopSoundMem(bgm_title_handle_);
	}


}

void SceneTitle::Render() {




	ui_title_->Render();

}
