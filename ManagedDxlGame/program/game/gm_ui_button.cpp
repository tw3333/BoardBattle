#include "gm_ui_button.h"

void UIButton::Update(float delta_time) {

	tnl::Vector3 mouse_pos = tnl::Input::GetMousePosition();

	if (!is_moving_) {

		//クリック判定
		if (IsClicked(mouse_pos.x, mouse_pos.y)) {

			UIPanel::mediator_->Notify(this, "ButtonFunction");
		
		}



	}

	UIPanel::Update(delta_time);

}

//クリック判定関数
//arg1,2...mouseの各座標
bool UIButton::IsClicked(int mouse_x, int mouse_y) {

	if (x_ < mouse_x && mouse_x < x_ + width_ 
		&& y_ < mouse_y && mouse_y < y_ + height_) {

		if (tnl::Input::IsMouseTrigger(eMouseTrigger::IN_LEFT)) {
			return true;
		}

	}

}


