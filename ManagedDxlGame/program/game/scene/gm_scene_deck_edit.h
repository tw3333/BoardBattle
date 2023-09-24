#pragma once
#include "gm_scene_base.h"

#include "../gm_card_manager.h"

class SceneDeckEdit : public SceneBase {
public:

	SceneDeckEdit(){}
	~SceneDeckEdit(){}

	void Initialzie() override;
	void Update(float delta_time) override;
	void Render() override;




private:

	

	CardManager& cmgr_ = CardManager::GetInstance();




};