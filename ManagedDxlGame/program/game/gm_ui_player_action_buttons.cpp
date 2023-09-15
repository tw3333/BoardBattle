#include "gm_ui_player_action_buttons.h"

void UIPlayerActionButtons::Update(float delta_time) {

	if (this->is_enabled_ == true) {

		for(auto uc : ui_components_) {
			uc->Update(delta_time);
			

		}

	}


}

void UIPlayerActionButtons::Render() {

	if (this->is_enabled_ == true) {

		for (auto uc : ui_components_) {

			uc->Render();
		}

	}


	DrawExtendGraph(action_button_pos_.x-5,action_button_pos_.y -5,
	action_button_pos_.x+action_button_pos_.w +5, action_button_pos_.y + action_button_pos_.h +5,g_select_flame_,true);

}