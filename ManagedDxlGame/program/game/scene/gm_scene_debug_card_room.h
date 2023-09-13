#pragma once
#include "gm_scene_base.h"

#include "../gm_card_manager.h"

class SceneDebugCardRoom : public SceneBase {
public:

	SceneDebugCardRoom() {}
	~SceneDebugCardRoom() {}

	void Initialzie() override;
	void Update(float delta_time) override;
	void Render() override;




private:

	CardManager& cmgr_ = CardManager::GetInstance();

	int cnt = 0;

};