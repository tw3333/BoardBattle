#pragma once
#include "gm_scene_base.h"

#include "../gm_scene_manager.h"

class SceneBattle : public SceneBase {
public:

	SceneBattle() {}
	~SceneBattle(){}

	void Initialzie() override;
	void Update(float delta_time) override;
	void Render() override;


private:


};