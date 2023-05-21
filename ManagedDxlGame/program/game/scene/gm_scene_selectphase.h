#pragma once
#include "gm_scene_base.h"
#include "../../dxlib_ext/dxlib_ext.h"
#include  "../gm_ui_window.h"
#include "../gm_ui_panel.h"
#include <vector>

#include "../gm_texture_manager.h"
class SceneSelectPhase : public SceneBase {
public:

	SceneSelectPhase(){}
	~SceneSelectPhase(){}

	void Initialzie() override;
	void Update(float delta_time) override;
	void Render() override;

	UIWindow* ui_window_ = nullptr;
	UIPanel* ui_panel_ = nullptr;

	std::vector<UIComponent*> all_ui_;
	std::vector<std::shared_ptr<UIComponent>> all_ui_component_;



private:

	int h1 = DXE_WINDOW_HEIGHT / 10;
	int w1 = DXE_WINDOW_WIDTH / 10;

	TextureManager* tmgr_ = TextureManager::GetInstance();

};
