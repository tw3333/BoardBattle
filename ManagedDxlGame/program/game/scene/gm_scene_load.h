#pragma once
#include "gm_scene_base.h"

#include "../gm_allydata_manager.h"
#include "../gm_enemydata_manager.h"
#include "../gm_texture_manager.h"
#include "../gm_scene_manager.h"
#include "../scene/gm_scene_battle.h"
#include "gm_scene_selectphase.h"

#include "../gm_object_manager.h"
#include "../gm_card_manager.h"
#include "../gm_font_manager.h"
#include "../gm_anim_manager.h"
#include "../gm_sound_manager.h"


//memo
//データのロードを行うシーン

class SceneLoad : public SceneBase {
public:

	SceneLoad() {}
	~SceneLoad() {}

	void Initialzie() override;
	void Update(float delta_time) override;
	void Render() override;

	void DebugSceneChanger();
	void DebugRender();


	bool CheckIsAllLoaded();

private:


	EnemyDataManager* emgr_ = EnemyDataManager::GetInstance();
	
	AllyDataManager& amgr_ = AllyDataManager::GetInstane();
	ObjectManager& obj_mgr_ = ObjectManager::GetInstance();
	CardManager& card_mgr_ = CardManager::GetInstance();
	FontManager& font_mgr_ = FontManager::GetInstance();
	AnimManager& anim_mgr_ = AnimManager::GetInstance();
	SoundManager& sound_mgr_ = SoundManager::GetInstance();
	TextureManager& texture_mgr_ = TextureManager::GetInstance();



	//ロード用フラグ
	bool is_all_loaded_ = false;
	bool is_font_loaded_ = false;
	bool is_texture_loaded_ = false;
	bool is_object_loaded_ = false;
	bool is_ally_loaded_ = false;
	bool is_enemy_loaded_ = false;
	bool is_card_loaded_ = false;
	bool is_sound_loaded_ = false;



	int load_slime_graph_ = 0; //load画面スライム用
};