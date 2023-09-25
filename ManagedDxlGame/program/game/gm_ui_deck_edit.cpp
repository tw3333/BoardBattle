#include "gm_ui_deck_edit.h"

void UIDeckEdit::Update(float delta_time) {



}

void UIDeckEdit::Render() {

	//‰º’n
	//leftbox
	DrawBox(leftbox_upper_left_x, leftbox_upper_left_y,	leftbox_lower_right_x, leftbox_lower_right_y,leftbox_color,true);
	//middlebox
	DrawBox(middlebox_upper_left_x,middlebox_upper_left_y,middlebox_lower_right_x,middlebox_lower_right_y,middlebox_color,true);
	//rightbox
	DrawBox(rightbox_upper_left_x, rightbox_upper_left_y, rightbox_lower_right_x, rightbox_lower_right_y, rightbox_color, true);

	





}

void UIDeckEdit::RenderChoiceCardUI(std::shared_ptr<Card> choice_card) {

	if (choice_card) {
		

	}

}
