#include "gm_scene_load.h"
#include "../../dxlib_ext/dxlib_ext.h"
#include "gm_scene_battle.h"

void SceneLoad::Initialzie() {

	
	font_mgr_.CreateFontData();

	obj_mgr_.CreateObjAllys();
	obj_mgr_.CreateObjSquares();
	obj_mgr_.CreateObjEnemies();

	amgr_->DebugLoadAllyData();
	amgr_->DebugLoadAllyTexture();

	emgr_->DebugLoadEnemyData();
	emgr_->DebugLoadenemyTexture();

	tmgr_->LoadTexture();
	
	card_mgr_.CreateDebugCardData();

	anim_mgr_.CreateDebugAnim();

	sound_mgr_.CreateBattleBGMList();
	sound_mgr_.CreateCardSEList();



}

void SceneLoad::Update(float delta_time) {

	SceneManager* smgr = SceneManager::GetInstance();

	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_1)) {
		
		if (amgr_->is_loaded_) {

			smgr->ChengeScene(new SceneBattle());

		}

	}

	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_2)) {

		if (amgr_->is_loaded_) {

			smgr->ChengeScene(new SceneSelectPhase());

		}

	}

}

void SceneLoad::Render() {


	if (!amgr_->is_loaded_) {
		DrawStringEx(DXE_WINDOW_WIDTH / 2, DXE_WINDOW_HEIGHT / 2, -1, "Loading...");
	
	}else if (amgr_->is_loaded_) {

		DrawStringEx(DXE_WINDOW_WIDTH / 2, DXE_WINDOW_HEIGHT / 2, -1, "Load Finish!");
		DrawStringEx(DXE_WINDOW_WIDTH / 2, DXE_WINDOW_HEIGHT / 2 + 20, -1, "Push:[1]->Scenebattle");
		DrawStringEx(DXE_WINDOW_WIDTH / 2, DXE_WINDOW_HEIGHT / 2 + 40, -1, "Push:[2]->SceneSelectPhase");

	}


	DrawStringToHandle(0,0,"CardCostFont",-1,font_mgr_.GetCardCostFont());
	DrawStringToHandle(0, 100, "CardNameFont", -1, font_mgr_.GetCardNameFont());
	DrawStringToHandle(0, 200, "CardTextFont", -1, font_mgr_.GetCardExplanationFont());

}