#pragma once
#include <memory>
#include "../dxlib_ext/dxlib_ext.h"
#include "gm_square.h"



//memo
//Stateパターン
//ToDo::スマートポインタを使用しての循環参照を解決する方法を詳しく調べる


class SceneBattle;

class BattlePhase {
public:


    virtual ~BattlePhase() {}


    virtual void BeginPhase() {} //Phase開始時に行われる
    virtual void EndPhase() {} //Phase終了時に行われる
    virtual bool UpdateExecute(float delta_time) = 0; //SceneのUpdateで実行
    virtual bool RenderExecute(dxe::Camera* camera) = 0; //SceneのRenderで実行



protected:

    SceneBattle* scene_battle_;



};