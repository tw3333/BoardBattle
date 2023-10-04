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

			if (turn_ally_) {
				if (!turn_ally_->GetIsDrewInitCard()) {
					DrawExtendGraph(card_button_->GetLowerRightX(), card_button_->GetUpperLeftY()
						, card_button_->GetLowerRightX(), card_button_->GetLowerRightY(), g_init_draw_f_, true);
				}
				else if (turn_ally_->GetIsDrewInitCard() && !turn_ally_->GetIsDrew()) {
					DrawExtendGraph(card_button_->GetLowerRightX(), card_button_->GetUpperLeftY()
						, card_button_->GetLowerRightX(), card_button_->GetLowerRightY(), g_draw_f_, true);
				}
				else if (turn_ally_->GetIsDrew()) {
					DrawExtendGraph(card_button_->GetLowerRightX(), card_button_->GetUpperLeftY()
						, card_button_->GetLowerRightX(), card_button_->GetLowerRightY(), g_card_f_, true);

				}
			}
		}

	}



	//if (!turn_ally_->GetIsDrewInitCard()) {
	////	
	////}


	DrawExtendGraph(action_button_pos_.x-5,action_button_pos_.y -5,
	action_button_pos_.x+action_button_pos_.w +5, action_button_pos_.y + action_button_pos_.h +5,g_select_flame_,true);

}