#pragma once
#include "gm_scene_base.h"

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


};