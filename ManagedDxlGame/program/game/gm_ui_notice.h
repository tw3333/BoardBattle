#pragma once
#include "gm_ui_component.h"
#include "gm_texture_manager.h"

class UINotice : public UIComponent {
public:

	UINotice(){}
	~UINotice(){}

	void Update(float delta_time) override;
	void Render() override;


	void NoTargetPanelRender(bool flag);
	void NotEnoughCostPanelRender(bool flag);

	bool NoticeRenderTimer();

	bool GetIsNoTargetPanelRender() { return is_no_target_panel_render_; }
	void SetIsNoTargetPanelRender(bool flag) { is_no_target_panel_render_ = flag; }
	bool GetIsNotEnoughCostPanelRender() { return is_not_enough_cost_panel_render_; }
	void SetIsNotEnoughCostPanelRender(bool flag) { is_not_enough_cost_panel_render_ = flag; }
	bool GetIsRenderRightClickReturnPanel() { return is_render_right_click_return_panel_; }
	void SetIsRenderRightClickReturnPanel(bool flag) { is_render_right_click_return_panel_ = flag; }
	bool GetIsRenderRightClickReturnSelectPanel() { return is_render_right_click_return_select_panel_; }
	void SetIsRenderRightClickReturnSelectPanel(bool flag) { is_render_right_click_return_select_panel_ = flag; }


	void PlayNoTarget();
	void PlayNotEnoughCost();

	bool IsRenderPhaseMovePanel();

private:

	bool is_no_target_panel_render_ = false;
	bool is_not_enough_cost_panel_render_ = false;
	bool play_no_target_ = false;
	bool play_not_enough_cost_ = false;

	bool is_render_right_click_return_panel_ = false;
	bool is_render_right_click_return_select_panel_ = false;


	float no_target_panel_timer_ = 1.0f;
	float not_enough_cost_panel_timer_ = 1.0f;

	float timer_ = 0.0f;


	TextureManager& texture_mgr_ = TextureManager::GetInstance();


	//debug
	int w1 = DXE_WINDOW_WIDTH / 10;
	int h1 = DXE_WINDOW_HEIGHT / 10;

};