#include "gm_ui_player_action_buttons.h"

void UIPlayerActionButtons::Update(float delta_time) {

	if (this->is_enabled_ == true) {

		for (auto uc : ui_components_) {
			uc->Update(delta_time);


		}

	}

	if (move_button_->GetIsOverMousePointer()) {
		is_render_select_flame_ = true;
		s_f_upper_left_x_ = move_button_->GetUpperLeftX();
		s_f_upper_left_y_ = move_button_->GetUpperLeftY();
		s_f_lower_right_x_ = move_button_->GetLowerRightX();
		s_f_lower_right_y_ = move_button_->GetLowerRightY();
	}
	else if (card_button_->GetIsOverMousePointer()) {
		is_render_select_flame_ = true;

		s_f_lower_right_x_ = card_button_->GetLowerRightX();
		s_f_lower_right_y_ = card_button_->GetLowerRightY();
		s_f_upper_left_x_ = card_button_->GetUpperLeftX();
		s_f_upper_left_y_ = card_button_->GetUpperLeftY();

	}
	else if (turn_end_button_->GetIsOverMousePointer()) {
		is_render_select_flame_ = true;

		s_f_lower_right_x_ = turn_end_button_->GetLowerRightX();
		s_f_lower_right_y_ = turn_end_button_->GetLowerRightY();
		s_f_upper_left_x_ = turn_end_button_->GetUpperLeftX();
		s_f_upper_left_y_ = turn_end_button_->GetUpperLeftY();

	}
	else {
		is_render_select_flame_ = false;
	}



}

void UIPlayerActionButtons::Render() {

	if (this->is_enabled_ == true) {

		for (auto uc : ui_components_) {

			uc->Render();


			if (turn_ally_) {
				if (!turn_ally_->GetIsDrewInitCard()) {
					DrawExtendGraph(c_b_upper_left_x_, c_b_upper_left_y_
						, c_b_lower_right_x_,c_b_lower_right_y_,g_init_draw_f_,true);
				}
				else if (turn_ally_->GetIsDrewInitCard() && !turn_ally_->GetIsDrew()) {
					DrawExtendGraph(c_b_upper_left_x_, c_b_upper_left_y_
						, c_b_lower_right_x_, c_b_lower_right_y_, g_draw_f_, true);
				}
				else if (turn_ally_->GetIsDrew()) {
					DrawExtendGraph(c_b_upper_left_x_, c_b_upper_left_y_
						, c_b_lower_right_x_, c_b_lower_right_y_, g_card_f_, true);

				}
			}

		}

	}

	if (is_render_select_flame_) {
		DrawExtendGraph(s_f_upper_left_x_, s_f_upper_left_y_,
			s_f_lower_right_x_, s_f_lower_right_y_, g_select_flame_, true);
	}


}