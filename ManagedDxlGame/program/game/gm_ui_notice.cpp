#include "gm_ui_notice.h"

void UINotice::Update(float delta_time) {

	if (timer_ > 1.0f) {
		is_not_enough_cost_panel_render_ = false;
		is_no_target_panel_render_ = false;
		play_no_target_ = false;
		play_not_enough_cost_ = false;

		timer_ = 0;
	}

	if (play_no_target_) {
		is_not_enough_cost_panel_render_ = false;
		is_no_target_panel_render_ = true;
		
		timer_ += delta_time;

	}
	
	if (play_not_enough_cost_) {
		is_no_target_panel_render_ = false;
		is_not_enough_cost_panel_render_ = true;
		
		timer_ += delta_time / not_enough_cost_panel_timer_;
	}



}

void UINotice::Render() {

	NoTargetPanelRender(is_no_target_panel_render_);
	NotEnoughCostPanelRender(is_not_enough_cost_panel_render_);


	if (is_no_target_panel_render_ && timer_ < 1.5f) {
		DrawBox(500, 500, 600, 600, -1, true);
	}

	if (is_not_enough_cost_panel_render_ && timer_ < 1.5f) {

	}
	else if (!is_no_target_panel_render_) {
		DrawStringEx(0,700,-1,"notargetpanel‚ªfalse‚Å‚·");
	}

	DrawStringEx(0,400,-1,"timer:%f",timer_);
}

void UINotice::NoTargetPanelRender(bool flag) {

	if (flag == true) {
		DrawExtendGraph(500, 500,600,600,no_target_, false);

		//DrawBox(500,500,600,600,-1,true);
	}

}

void UINotice::NotEnoughCostPanelRender(bool flag) {

	if (flag == true) {
		//DrawExtendGraph(500,500,600,600,texture_mgr_.GetUINoticeGraphList()[UINoticeGraph::NotEnoughCost]->getDxLibGraphHandle(), false);
		DrawBox(700, 700, 900, 900, -1, true);
	}

}

void UINotice::PlayNoTarget() {
	play_no_target_ = true;
	timer_ = 0;
}

void UINotice::PlayNotEnoughCost() {
	play_not_enough_cost_ = true;
	timer_ = 0;
}
