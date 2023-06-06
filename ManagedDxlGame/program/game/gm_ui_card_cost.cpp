#include "gm_ui_card_cost.h"

void  UICardCost::Update(float delta_time) {

	if (unit_ally_) {

		max_cost_ = unit_ally_->GetMaxCardCost();
		current_cost_ = unit_ally_->GetCurrentCardCost();

	}

}

void UICardCost::Render() {

	if (unit_ally_) {

		//DrawBox(x_,y_,x_ + width_, y_ + height_, color_black_, false);

		DrawExtendGraph(x_, y_, x_ + height_, y_ + height_, graph_card_icon_, true);


		for (int i = 0; i < current_cost_; ++i) {

			DrawCircle(x_ + radius_ + (height_ * i) + height_, y_ + radius_, radius_, color_orange_, true);

		}


		for (int i = 0; i < max_cost_; ++i) {

			DrawCircle(x_ + radius_ + (height_ * i) + height_, y_ + radius_, radius_, color_black_, false);

		}

	}


}