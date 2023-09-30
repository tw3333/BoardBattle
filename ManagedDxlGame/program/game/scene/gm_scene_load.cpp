#include "gm_scene_load.h"

#include "../../dxlib_ext/dxlib_ext.h"
#include "gm_scene_battle.h"
#include "gm_scene_debug_card_room.h"
#include "gm_scene_deck_edit.h"

void SceneLoad::Initialzie() {

	std::setlocale(LC_ALL, "ja_JP.shiftjis"); 

	
	font_mgr_.CreateFontData();

	texture_mgr_.DebugLoadTexture();
	

	obj_mgr_.CreateObjAllys();
	obj_mgr_.CreateObjSquares();
	obj_mgr_.CreateObjEnemies();
	obj_mgr_.CreateObjBattleStateIcon(texture_mgr_.GetBattleStateIconList());

	amgr_.DebugLoadAllyData();
	amgr_.DebugLoadAllyTexture();

	emgr_->DebugLoadEnemyData();
	emgr_->DebugLoadenemyTexture();

	
	
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


	anim_mgr_.CreateDebugAnim();
	obj_mgr_.CreateDebugCardAnimSprites();

	sound_mgr_.CreateBattleBGMList();
	sound_mgr_.CreateCardSEList();
	sound_mgr_.CreateAllyVoiveList();
	sound_mgr_.CreateSystemSEList();
	sound_mgr_.CreateEnemyActSEList();



}

void SceneLoad::Update(float delta_time) {

	SceneManager* smgr = SceneManager::GetInstance();

	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_1)) {
		
		if (amgr_.is_loaded_) {

			smgr->ChengeScene(new SceneBattle());

		}

	}

	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_2)) {

		if (amgr_.is_loaded_) {

			smgr->ChengeScene(new SceneSelectPhase());

		}

	}
	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_3)) {

		if (amgr_.is_loaded_) {

			smgr->ChengeScene(new SceneDebugCardRoom());

		}

	}
	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_4)) {

		if (amgr_.is_loaded_) {

			smgr->ChengeScene(new SceneDeckEdit());

		}

	}




}

void SceneLoad::Render() {


	if (!amgr_.is_loaded_) {
		DrawStringEx(DXE_WINDOW_WIDTH / 2, DXE_WINDOW_HEIGHT / 2, -1, "Loading...");
	
	}else if (amgr_.is_loaded_) {

		DrawStringEx(DXE_WINDOW_WIDTH / 2, DXE_WINDOW_HEIGHT / 2, -1, "Load Finish!");
		DrawStringEx(DXE_WINDOW_WIDTH / 2, DXE_WINDOW_HEIGHT / 2 + 20, -1, "Push:[1]->Scenebattle");
		DrawStringEx(DXE_WINDOW_WIDTH / 2, DXE_WINDOW_HEIGHT / 2 + 40, -1, "Push:[2]->SceneSelectPhase");
		DrawStringEx(DXE_WINDOW_WIDTH / 2, DXE_WINDOW_HEIGHT / 2 + 60, -1, "Push:[3]->SceneDebugCardRoom");
		DrawStringEx(DXE_WINDOW_WIDTH / 2, DXE_WINDOW_HEIGHT / 2 + 80, -1, "Push:[4]->SceneDeckEdit");

	}


	DrawStringToHandle(0,0,"CardCostFont",-1,font_mgr_.GetCardCostFont());
	DrawStringToHandle(0, 100, "CardNameFont", -1, font_mgr_.GetCardNameFont());
	DrawStringToHandle(0, 200, "CardTextFont", -1, font_mgr_.GetCardExplanationFont());

	if (card_mgr_.GetAllCardTarget().empty()) {

		DrawStringEx(DXE_WINDOW_WIDTH / 2, DXE_WINDOW_HEIGHT / 2 + 60, -1, "AllCardTarget�͋�ł�");

	}


}