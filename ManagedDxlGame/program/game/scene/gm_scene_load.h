#pragma once
#include "gm_scene_base.h"

#include "../gm_allydata_manager.h"
#include "../gm_texture_manager.h"
#include "../gm_scene_manager.h"
#include "../scene/gm_scene_battle.h"
#include "gm_scene_selectphase.h"
#include "../gm_object_manager.h"

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
	TextureManager* tmgr_ = TextureManager::GetInstance();
	ObjectManager& obj_mgr_ = ObjectManager::GetInstance();



	enum NextScene {
		//SceneBattle
		
	};

};