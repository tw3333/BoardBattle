#include "gm_scene_load.h"
#include "../../dxlib_ext/dxlib_ext.h"
#include "gm_scene_battle.h"

void SceneLoad::Initialzie() {

	amgr_->DebugLoadAllyData();
	
}

void SceneLoad::Update(float delta_time) {

	SceneManager* smgr = SceneManager::GetInstance();

	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {
		
		if (amgr_->is_loaded_) {

			smgr->ChengeScene(new SceneBattle());

		}

	}

}

void SceneLoad::Render() {


	if (!amgr_->is_loaded_) {
		DrawStringEx(DXE_WINDOW_WIDTH / 2, DXE_WINDOW_HEIGHT / 2, -1, "Loading...");
	
	}else if (amgr_->is_loaded_) {

		DrawStringEx(DXE_WINDOW_WIDTH / 2, DXE_WINDOW_HEIGHT / 2, -1, "Load Finish!");
		DrawStringEx(DXE_WINDOW_WIDTH / 2, DXE_WINDOW_HEIGHT / 2 + 20, -1, "Push:[Enter]");
	}

}