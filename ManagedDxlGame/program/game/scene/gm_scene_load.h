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


private:

	AllyDataManager* amgr_ = AllyDataManager::GetInstance();
	EnemyDataManager* emgr_ = EnemyDataManager::GetInstance();
	TextureManager* tmgr_ = TextureManager::GetInstance();


	ObjectManager& obj_mgr_ = ObjectManager::GetInstance();
	CardManager& card_mgr_ = CardManager::GetInstance();
	FontManager& font_mgr_ = FontManager::GetInstance();
	AnimManager& anim_mgr_ = AnimManager::GetInstance();
	SoundManager& sound_mgr_ = SoundManager::GetInstance();




	enum NextScene {
		//SceneBattle
		
	};

};