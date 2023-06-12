#pragma once
#include <memory>
#include "../dxlib_ext/dxlib_ext.h"


//memo
//State�p�^�[��


class SceneBattle;

class BattlePhase {
public:

    virtual ~BattlePhase() {}


    virtual void BeginPhase() {} //Phase�J�n���ɍs����
    virtual void EndPhase() {} //Phase�I�����ɍs����
    virtual bool UpdateExecute(float delta_time) = 0; //Scene��Update�Ŏ��s
    virtual bool RenderExecute(dxe::Camera* camera) = 0; //Scene��Render�Ŏ��s



protected:

    SceneBattle* scene_battle_;




};