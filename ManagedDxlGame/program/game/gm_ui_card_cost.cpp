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
			
			int pos_index = i % 5;
			int current_color;

			if (i < 5) {
				current_color = color_yellow_;
			}
			else if (5 <= i && i < 10) {
				current_color = color_orange_;
			}
			else {
				current_color = color_red_;
			}
			
			DrawCircle(x_ + radius_ + (height_ * pos_index) + height_, y_ + radius_, radius_, current_color, true);

			//if (i < 5) {
			//	DrawCircle(x_ + radius_ + (height_ * pos_index) + height_, y_ + radius_, radius_, color_yellow_, true);
			//}
			//else if (5 <= i  && i < 10) {
			//	
			//	DrawCircle(x_ + radius_ + (height_ * pos_index) + height_, y_ + radius_, radius_, color_orange_, true);
			//}
			//else if (10 <= i) {
			//	DrawCircle(x_ + radius_ + (height_ * pos_index) + height_, y_ + radius_, radius_, color_red_, true);
			//}


		}


		for (int i = 0; i < max_cost_; ++i) {

			if (i < 5) {
				DrawCircle(x_ + radius_ + (height_ * i) + height_, y_ + radius_, radius_, color_black_, false);
			}
			

			//DrawCircle(x_ + radius_ + (height_ * i) + height_, y_ + radius_, radius_, color_black_, false);

		}

	}


}