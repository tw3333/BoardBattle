#include "gm_scene_battle_result.h"

#include "../../dxlib_ext/dxlib_ext.h"

void SceneBattleResult::Initialzie()
{



}

void SceneBattleResult::Update(float delta_time)
{
}

void SceneBattleResult::Render()
{

	DrawStringEx(0,500,-1,"プレイありがとうございました！");
	DrawStringEx(0, 520, -1, "Press:[Enter]でもう一度プレイ(敵・味方の配置は毎回ランダムです！)");


}
