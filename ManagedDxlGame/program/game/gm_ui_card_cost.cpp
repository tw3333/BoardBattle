#include "gm_ui_card_cost.h"

void  UICardCost::Update(float delta_time) {

	max_cost_ = unit_ally_->GetMaxCardCost();
	current_cost_ = unit_ally_->GetCurrentCardCost();

}

void UICardCost::Render() {

	

	DrawBox(x_,y_,x_ + width_, y_ + height_, color_black_, false);

	for (int i = 0; i < current_cost_; ++i) {

		DrawCircle(x_ + radius_ + (height_ * i), y_ + radius_, radius_, color_orange_, true);

	}


	for (int i = 0; i < max_cost_; ++i) {

		DrawCircle(x_ + radius_ + (height_ * i), y_ + radius_, radius_, color_black_, false);

	}



}