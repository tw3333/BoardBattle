#pragma once
#include "gm_scene_base.h"
#include "../../dxlib_ext/dxlib_ext.h"

class SceneSelectPhase : public SceneBase {
public:

	SceneSelectPhase(){}
	~SceneSelectPhase(){}

	void Initialzie() override;
	void Update(float delta_time) override;
	void Render() override;



private:


};
