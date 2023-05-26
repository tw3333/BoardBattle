#pragma once
#include "gm_scene_base.h"
#include "../../dxlib_ext/dxlib_ext.h"
#include  "../gm_ui_window.h"
#include "../gm_ui_panel.h"
#include "../gm_ui_button.h"
#include "../gm_ui_selectphase_mediator.h"
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
	UIButton* ui_button_ = nullptr;

	
	void CreateUIComponents();

	bool is_sen;

private:

	int h1 = DXE_WINDOW_HEIGHT / 10;
	int w1 = DXE_WINDOW_WIDTH / 10;

	TextureManager* tmgr_ = TextureManager::GetInstance();

	//UIçÏê¨ópïœêî(âº)
	UISelectPhaseMediator* ui_mediator_ = new UISelectPhaseMediator();


	std::vector<UIComponent*> all_ui_;

	std::vector<std::shared_ptr<UIComponent>> ui_components_;

	std::vector<std::shared_ptr<UIButton>> ui_buttons_;



};
