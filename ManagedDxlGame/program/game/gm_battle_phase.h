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

    virtual bool UpdateExecute(float delta_time) = 0; //Scene�̍X�V
    virtual bool RenderExecute(dxe::Camera* camera) = 0; //Scene�̕`�ʗp


protected:

    SceneBattle* scene_battle_;



};