#pragma once
#include "scene_base.h"

class SceneSelectPhase : public SceneBase {
public:

	SceneSelectPhase(){}
	~SceneSelectPhase(){}

	void Initialzie() override;
	void Update(float delta_time) override;
	void Render() override;



private:


};
