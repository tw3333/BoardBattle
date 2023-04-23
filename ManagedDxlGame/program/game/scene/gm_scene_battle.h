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
	
	int w1 = DXE_WINDOW_WIDTH / 10;
	int h1 = DXE_WINDOW_HEIGHT / 10;

};