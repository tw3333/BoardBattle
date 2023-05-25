#include "gm_ui_button.h"

void UIButton::Update(float delta_time) {

	tnl::Vector3 mouse_pos = tnl::Input::GetMousePosition();

	if (is_enabled_) {

		if (!is_moving_) {

			//�N���b�N����
			if (IsClicked(mouse_pos.x, mouse_pos.y)) {


				if (mediator_) {

					mediator_->Notify(this, notify_tag_);

				}
				
			}

		}

		UIPanel::Update(delta_time);
	}

}

//�N���b�N����֐�
//arg1,2...mouse�̊e���W
bool UIButton::IsClicked(int mouse_x, int mouse_y) {

	if (tnl::Input::IsMouseTrigger(eMouseTrigger::IN_LEFT)) {
		if (x_ < mouse_x && mouse_x < x_ + width_
			&& y_ < mouse_y && mouse_y < y_ + height_) {

			return true;
		}
	}

	return false;
}


