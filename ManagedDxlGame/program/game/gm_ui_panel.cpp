#include "gm_ui_panel.h"

void UIPanel::Update(float delta_time) {

	if (is_moving_) { 
		
		time_ += delta_time / duration_;

		if (time_ > 1) {

			time_ = 1;
			is_moving_ = false;
		}

		x_ = EasingFunctions::EaseOutExpo(time_) * (end_x_ - start_x_) + start_x_;
		AnimationRender();
	}





}

void UIPanel::Render() {

	if (!is_moving_) {

		if (graph_handle_) {

			DrawExtendGraph(x_, y_, x_ + width_, y_ + height_, graph_handle_, false);

		}
		else if (!graph_handle_) {

			DrawBox(x_, y_, x_ + (float)width_, y_ + height_, 255, true);

		}

	}

}

void UIPanel::AnimationRender() {

	if (graph_handle_) {

		DrawExtendGraph(x_, y_, x_ + width_, y_ + height_, graph_handle_, false);

	}
	else if (!graph_handle_) {

		DrawBox(x_, y_, x_ + (float)width_, y_ + height_, 255, true);

	}

}


//arg1...easingäJénéûÇÃç∂è„xç¿ïW
void UIPanel::SetStartEasing(int start_x) {

	start_x_ = start_x;
	end_x_ = x_;
	time_ = 0;
	is_moving_ = true;

}


