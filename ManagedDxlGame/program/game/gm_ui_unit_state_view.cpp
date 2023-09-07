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
				//‰º’nBox
				DrawBox(ally_box_upper_left_x_,ally_box_upper_left_y_, ally_box_upper_left_x_ + width_, ally_box_upper_left_y_ + height_,box_color_,true);
				
				//faceBox
				int face_box_upper_left_x = ally_box_upper_left_x_ + 5;
				int face_box_upper_left_y = ally_box_upper_left_y_ + 5;
				int face_box_w = ally_box_upper_left_x_ + width_  * 1 / 3;
				int face_box_h = ally_box_upper_left_y_ + height_ / 2;
				int face_graph = select_square_->GetSelectSquare()->GetAllyPtrInSquare()->GetAllyData()->GetTextureFace1()->getDxLibGraphHandle();
				DrawBox(face_box_upper_left_x, face_box_upper_left_y, face_box_upper_left_x + face_box_w, face_box_upper_left_y + face_box_h,255,true);
				DrawExtendGraph(face_box_upper_left_x, face_box_upper_left_y, face_box_upper_left_x + face_box_w, face_box_upper_left_y + face_box_h,face_graph, false);

				//HpBar
				int hp_bar_upper_left_x = face_box_upper_left_x;
				int hp_bar_upper_left_y = ally_box_upper_left_y_ + (height_ / 2 ) + 25;
				int hp_bar_w = hp_bar_upper_left_x + ally_box_upper_left_x_ + width_ - 20;
				int hp_bar_h = hp_bar_upper_left_y + ally_box_upper_left_y_ + height_ / 4 - 20;
				float hp_ratio = static_cast<float>(select_square_->GetSelectSquare()->GetAllyPtrInSquare()->GetCurrentHp()) / static_cast<float>(select_square_->GetSelectSquare()->GetAllyPtrInSquare()->GetMaxHp());
				//flame
				DrawBox(face_box_upper_left_x, hp_bar_upper_left_y, hp_bar_w * hp_ratio, hp_bar_h, hp_bar_color_, true);
				//bar
				DrawBox(face_box_upper_left_x, hp_bar_upper_left_y, hp_bar_w, hp_bar_h, hp_bar_flame_color_, false);

				//State
				


			}
			else if (select_square_->GetSelectSquare()->GetEnemyInSquare()) {

				DrawBox(enemy_box_upper_left_x_, enemy_box_upper_left_y_, enemy_box_upper_left_x_ + width_, enemy_box_upper_left_y_ + height_, box_color_, true);


			}

		}


		//‰º’n
		//DrawBox(pos_x_, pos_y_, pos_x_ + width_, pos_y_ + height_, -1, false);


	}

}
