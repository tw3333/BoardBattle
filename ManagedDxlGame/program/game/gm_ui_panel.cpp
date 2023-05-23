#include "gm_ui_panel.h"

void UIPanel::Update(float delta_time) {

	if (is_moving_) { 
		
		if (delay_ > 0.0f) {
			delay_ -= delta_time;
			return;  // �f�B���C���Ԃ��o�߂��Ă��Ȃ��ꍇ�͏������X�L�b�v
		}


		time_ += delta_time / duration_;

		if (time_ > 1) {

			time_ = 1;
			is_moving_ = false;
		}

		float eased_time = easing_function_->Ease(time_);
		x_ = eased_time * (end_x_ - start_x_) + start_x_;
		DuringAnimationRender();
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

void UIPanel::DuringAnimationRender() {

	if (graph_handle_) {

		DrawExtendGraph(x_, y_, x_ + width_, y_ + height_, graph_handle_, false);

	}
	else if (!graph_handle_) {

		DrawBox(x_, y_, x_ + (float)width_, y_ + height_, 255, true);

	}

}


//arg1...easing�J�n���̍���x���W
//arg2...�A�j���[�V�����J�n�܂ł�delay
void UIPanel::SetStartEasing(int start_x,float delay) {

	start_x_ = start_x;
	end_x_ = x_;
	time_ = 0;
	is_moving_ = true;

}


