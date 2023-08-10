#include "gm_ui_notice_target_box.h"

#include "DxLib.h"


void UINoticeTargetBox::Update(float delat_time) {





}




void UINoticeTargetBox::Render() {

	if (target_num_ != 0) {

		//â∫ín
		DrawBox(pos_x_, pos_y_, pos_x_ + width_, pos_y_ + height_, box_color_, true);
		DrawBox(pos_x_, pos_y_, pos_x_ + width_, pos_y_ + height_, flame_color_, false);

	
		//DrawFormatStringToHandle(pos_x_ + 10, pos_y_ + 5, flame_color_, font_mgr_.GetNoticeTargetNumFont(), "%d",target_num_);
		DrawFormatStringToHandle(pos_x_ + 10, pos_y_ + 5, flame_color_, font_mgr_.GetNoticeTargetNumFont(), "ëŒè€éwíËÅF%d",target_num_);






	}






}
