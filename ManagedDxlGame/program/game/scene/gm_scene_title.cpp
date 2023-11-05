#include "gm_scene_title.h"

#include "gm_scene_load.h"

void SceneTitle::Initialzie() {

	title_bgm_handle_ = LoadSoundMem("sound/bgm/scenetitle_back.mp3");
	ChangeVolumeSoundMem(70, title_bgm_handle_);
	PlaySoundMem(title_bgm_handle_, DX_PLAYTYPE_LOOP, true);

	title_bgm_handle_ = LoadSoundMem("sound/bgm/scene_title_back.mp3");
	ui_title_ = new UITitle();

}

void SceneTitle::Update(float delta_time) {

	SceneManager* scene_mgr_ = SceneManager::GetInstance();


	//if (start_) {

	//	start_ = false;
	//	quit_game_ = false;
	//	scene_mgr_->ChengeScene(new SceneLoad());
	//}
	//if (quit_game_) {

	//	start_ = false;
	//	quit_game_ = false;
	//	DxLib_End();
	//}

	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_D)) {
		DxLib_End();
	}
	ui_title_->Update(delta_time);


}

void SceneTitle::Render() {

	PlaySoundMem(title_bgm_handle_, DX_PLAYTYPE_LOOP, true);


	ui_title_->Render();

}
