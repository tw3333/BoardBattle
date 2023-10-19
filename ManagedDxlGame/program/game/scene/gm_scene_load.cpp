#include "gm_scene_load.h"

#include "../../dxlib_ext/dxlib_ext.h"
#include "gm_scene_battle.h"
#include "gm_scene_debug_card_room.h"
#include "gm_scene_deck_edit.h"

void SceneLoad::Initialzie() {

	load_slime_graph_ = LoadGraph("graphics/unit/enemy/adoption/slime_battle.png");

	//font_mgr_.CreateFontData();

	//texture_mgr_.DebugLoadTexture();
	//texture_mgr_.LoadUINoticeGraph();
	//texture_mgr_.LoadUIPlayerActionButtonsGraph();
	//texture_mgr_.LoadBackgroundGraph();
	//

	//obj_mgr_.CreateObjAllys();
	//obj_mgr_.CreateObjSquares();
	//obj_mgr_.CreateObjEnemies();
	//obj_mgr_.CreateObjBattleStateIcon(texture_mgr_.GetBattleStateIconList());

	//amgr_.DebugLoadAllyData();
	//amgr_.DebugLoadAllyTexture();

	//emgr_->DebugLoadEnemyData();
	//emgr_->DebugLoadenemyTexture();

	//
	//
	//card_mgr_.CreateDebugCardData();
	//card_mgr_.LoadCardDataFromCSV("csv/card/LoadCardData.csv");
	////card_mgr_.LoadCardTargetFromCSV("csv/card/LoadCardTarget.csv");
	//card_mgr_.LoadCardRangeFromCSV("csv/card/LoadCardRange.csv");
	//card_mgr_.LoadAllCardTargetFromCSV("csv/card/LoadCardTarget2.csv");
	//card_mgr_.LoadAllCardEffectFromCSV("csv/card/LoadCardEffect2.csv");
	//card_mgr_.CombineCardData();
	//card_mgr_.CreateAllInitCard();
	//card_mgr_.SeparetePossCards();

	//card_mgr_.LoadC1DeckFromCSV("csv/card/LoadC1Deck.csv");
	//card_mgr_.LoadC2DeckFromCSV("csv/card/LoadC2Deck.csv");
	//card_mgr_.LoadC3DeckFromCSV("csv/card/LoadC3Deck.csv");


	//anim_mgr_.CreateDebugAnim();
	//obj_mgr_.CreateDebugCardAnimSprites();

	//sound_mgr_.CreateBattleBGMList();
	////sound_mgr_.CreateCardSEList();
	//sound_mgr_.CreateAllyVoiveList();
	//sound_mgr_.CreateSystemSEList();
	//sound_mgr_.CreateEnemyActSEList();
	//sound_mgr_.CreateUISEList();

	//sound_mgr_.LoadCardSEFromCSV("csv/sound/LoadCardSE.csv");
	//sound_mgr_.LoadBattleStateSEFromCSV("csv/sound/LoadBattleStateSE.csv");



}

void SceneLoad::Update(float delta_time) {

	//DebugSceneChanger();
	SceneManager* scene_mgr_ = SceneManager::GetInstance();

	//1
	if (!is_font_loaded_) {
		font_mgr_.CreateFontData();
		is_font_loaded_ = true;
	}
	//2
	if (!is_texture_loaded_) {
		texture_mgr_.DebugLoadTexture();
		texture_mgr_.LoadUINoticeGraph();
		texture_mgr_.LoadUIPlayerActionButtonsGraph();
		texture_mgr_.LoadBackgroundGraph();
		is_texture_loaded_ = true;
	}
	//3
	if (!is_object_loaded_) {
		obj_mgr_.CreateObjAllys();
		obj_mgr_.CreateObjSquares();
		obj_mgr_.CreateObjEnemies();
		obj_mgr_.CreateObjBattleStateIcon(texture_mgr_.GetBattleStateIconList());
		obj_mgr_.CreateDebugCardAnimSprites();
		anim_mgr_.CreateDebugAnim();
		is_object_loaded_ = true;
	}
	//4
	if (!is_ally_loaded_) {
		amgr_.DebugLoadAllyData();
		amgr_.DebugLoadAllyTexture();
		is_ally_loaded_ = true;
	}
	//5
	if (!is_enemy_loaded_) {
		emgr_->DebugLoadEnemyData();
		emgr_->DebugLoadenemyTexture();
		is_enemy_loaded_ = true;
	}
	//6
	if (!is_card_loaded_) {
		card_mgr_.CreateDebugCardData();
		card_mgr_.LoadCardDataFromCSV("csv/card/LoadCardData.csv");
		//card_mgr_.LoadCardTargetFromCSV("csv/card/LoadCardTarget.csv");
		card_mgr_.LoadCardRangeFromCSV("csv/card/LoadCardRange.csv");
		card_mgr_.LoadAllCardTargetFromCSV("csv/card/LoadCardTarget2.csv");
		card_mgr_.LoadAllCardEffectFromCSV("csv/card/LoadCardEffect2.csv");
		card_mgr_.CombineCardData();
		card_mgr_.CreateAllInitCard();
		card_mgr_.SeparetePossCards();
		card_mgr_.LoadC1DeckFromCSV("csv/card/LoadC1Deck.csv");
		card_mgr_.LoadC2DeckFromCSV("csv/card/LoadC2Deck.csv");
		card_mgr_.LoadC3DeckFromCSV("csv/card/LoadC3Deck.csv");
		is_card_loaded_ = true;
	}
	//7
	if (!is_sound_loaded_) {
		sound_mgr_.CreateBattleBGMList();
		//sound_mgr_.CreateCardSEList();
		sound_mgr_.CreateAllyVoiveList();
		sound_mgr_.CreateSystemSEList();
		sound_mgr_.CreateEnemyActSEList();
		sound_mgr_.CreateUISEList();
		sound_mgr_.LoadCardSEFromCSV("csv/sound/LoadCardSE.csv");
		sound_mgr_.LoadBattleStateSEFromCSV("csv/sound/LoadBattleStateSE.csv");
		is_sound_loaded_ = true;
	}

	
	if (CheckIsAllLoaded()) {
		is_all_loaded_ = true;
	}
	else {
		is_all_loaded_ = false;
	}

	if (is_all_loaded_) {
		if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {
			scene_mgr_->ChengeScene(new SceneBattle());
		}
	}
	
}

void SceneLoad::Render() {

	if (!is_all_loaded_) {
		DrawStringEx(DXE_WINDOW_WIDTH / 2 - 70, DXE_WINDOW_HEIGHT / 2 + 120, -1, "Loading...");
	}
	else if (is_all_loaded_) {
		DrawStringEx(DXE_WINDOW_WIDTH / 2 - 70, DXE_WINDOW_HEIGHT / 2 + 120, -1, "LoadFinish!");
		DrawStringEx(DXE_WINDOW_WIDTH / 2 - 70, DXE_WINDOW_HEIGHT / 2 + 140, -1, "Push:[Enter]でゲーム開始！");
	}

	DrawGraph(DXE_WINDOW_WIDTH / 2 - 87, DXE_WINDOW_HEIGHT / 2, load_slime_graph_, true);
}

void SceneLoad::DebugSceneChanger() {

	//if (tnl::Input::IsKeyDownTrigger(eKeys::KB_1)) {

	//	if (amgr_.is_loaded_) {

	//		scene_mgr_->ChengeScene(new SceneBattle());

	//	}

	//}

	//if (tnl::Input::IsKeyDownTrigger(eKeys::KB_2)) {

	//	if (amgr_.is_loaded_) {

	//		scene_mgr_->ChengeScene(new SceneSelectPhase());

	//	}

	//}
	//if (tnl::Input::IsKeyDownTrigger(eKeys::KB_3)) {

	//	if (amgr_.is_loaded_) {

	//		scene_mgr_->ChengeScene(new SceneDebugCardRoom());

	//	}

	//}
	//if (tnl::Input::IsKeyDownTrigger(eKeys::KB_4)) {

	//	if (amgr_.is_loaded_) {

	//		scene_mgr_->ChengeScene(new SceneDeckEdit());

	//	}

	//}

}

void SceneLoad::DebugRender() {

	if (!amgr_.is_loaded_) {
		DrawStringEx(DXE_WINDOW_WIDTH / 2, DXE_WINDOW_HEIGHT / 2, -1, "Loading...");

	}
	else if (amgr_.is_loaded_) {

		DrawStringEx(DXE_WINDOW_WIDTH / 2, DXE_WINDOW_HEIGHT / 2, -1, "Load Finish!");
		DrawStringEx(DXE_WINDOW_WIDTH / 2, DXE_WINDOW_HEIGHT / 2 + 20, -1, "Push:[1]->Scenebattle");
		DrawStringEx(DXE_WINDOW_WIDTH / 2, DXE_WINDOW_HEIGHT / 2 + 40, -1, "Push:[2]->SceneSelectPhase");
		DrawStringEx(DXE_WINDOW_WIDTH / 2, DXE_WINDOW_HEIGHT / 2 + 60, -1, "Push:[3]->SceneDebugCardRoom");
		DrawStringEx(DXE_WINDOW_WIDTH / 2, DXE_WINDOW_HEIGHT / 2 + 80, -1, "Push:[4]->SceneDeckEdit");

	}


	DrawStringToHandle(0, 0, "CardCostFont", -1, font_mgr_.GetCardCostFont());
	DrawStringToHandle(0, 100, "CardNameFont", -1, font_mgr_.GetCardNameFont());
	DrawStringToHandle(0, 200, "CardTextFont", -1, font_mgr_.GetCardExplanationFont());

	if (card_mgr_.GetAllCardTarget().empty()) {

		DrawStringEx(DXE_WINDOW_WIDTH / 2, DXE_WINDOW_HEIGHT / 2 + 60, -1, "AllCardTargetは空です");

	}

}

bool SceneLoad::CheckIsAllLoaded() {

	if (is_font_loaded_ 
		&& is_texture_loaded_ 
		&& is_object_loaded_ 
		&& is_ally_loaded_
		&& is_enemy_loaded_
		&& is_card_loaded_
		&& is_sound_loaded_ ) 
	{
		return true;
	}
	else {
		return false;
	}

}
