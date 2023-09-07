#include "gm_ui_unit_state_view.h"

#include "DxLib.h"
#include "gm_square.h"
#include "gm_unit_ally.h"
#include "gm_unit_enemy.h"


void UIUnitStateView::Update(float delta_time) {

	


}

void UIUnitStateView::Render() {

	if (is_render_) {
		
		if (select_square_->GetSelectSquare()) {

			if (select_square_->GetSelectSquare()->GetAllyPtrInSquare()) {

				//DrawStringEx(0,700,-1,"‚±‚Ì–¡•û‚ÌHP‚Í%d", select_square_->GetAllyPtrInSquare()->GetCurrentHp());
				DrawBox(ally_box_upper_left_x_,ally_box_upper_left_y_, ally_box_upper_left_x_ + width_, ally_box_upper_left_y_ + height_,box_color_,true);

				int face_box_upper_left_x = ally_box_upper_left_x_ + 5;
				int face_box_upper_left_y = ally_box_upper_left_y_ + 5;
				int face_box_w = ally_box_upper_left_x_ + width_  * 1 / 3;
				int face_box_h = ally_box_upper_left_y_ + height_ / 2;
				DrawBox(face_box_upper_left_x, face_box_upper_left_y, face_box_upper_left_x + face_box_w, face_box_upper_left_y + face_box_h,255,true);



			}
			else if (select_square_->GetSelectSquare()->GetEnemyInSquare()) {

				DrawBox(enemy_box_upper_left_x_, enemy_box_upper_left_y_, enemy_box_upper_left_x_ + width_, enemy_box_upper_left_y_ + height_, box_color_, true);


			}

		}


		//‰º’n
		//DrawBox(pos_x_, pos_y_, pos_x_ + width_, pos_y_ + height_, -1, false);


	}

}
