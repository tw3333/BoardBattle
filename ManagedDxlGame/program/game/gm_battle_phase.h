#pragma once
#include <memory>

class SceneBattle;

class BattlePhase {
public:

    virtual ~BattlePhase() {}
    virtual void BeginPhase() {}
    virtual void EndPhase() {}

    virtual bool UpdateExecute(float delta_time) = 0;
    virtual bool RenderExecute() = 0;

protected:

    std::weak_ptr<SceneBattle> scene_battle_;


};