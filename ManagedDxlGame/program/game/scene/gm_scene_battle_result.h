#pragma once
#include "gm_scene_base.h"

//memo
//SceneBattleから推移する戦闘結果画面


class SceneBattleResult : public SceneBase{
public:

	SceneBattleResult(){}
	~SceneBattleResult(){}


	void Initialzie() override;
	void Update(float delta_time) override;
	void Render() override;


private:




};