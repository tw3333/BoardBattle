#include "gm_ui_move_cost.h"

void UIMoveCost::Update(float delta_time) {

	max_cost_ = unit_ally_->GetMaxMoveCost();
	current_cost_ = unit_ally_->GetCurrentMoveCost();


}

void UIMoveCost::Render() {

	DrawBox(x_, y_, x_ + width_, y_ + height_, color_black_, false);

	DrawExtendGraph(x_, y_, x_ + height_, y_ + height_, graph_move_icon_, true);


	for (int i = 0; i < current_cost_; ++i) {

		DrawCircle(x_ + radius_ + (height_ * i) + height_, y_ + radius_, radius_, color_blue_, true);

	}


	for (int i = 0; i < max_cost_; ++i) {

		DrawCircle(x_ + radius_ + (height_ * i) + height_, y_ + radius_, radius_, color_black_, false);

	}


}