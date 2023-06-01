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

}