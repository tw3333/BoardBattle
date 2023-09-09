#include "gm_ui_unit_state_view.h"

#include "DxLib.h"
#include "gm_square.h"
#include "gm_unit_ally.h"
#include "gm_unit_enemy.h"


void UIUnitStateView::Update(float delta_time) {

	


}

//Todomemo
//ó‘ÔˆÙí‚Ì•\Œ»‚Íˆê‰ñUnit‚©‚ç’Šo‚µ‚Ä”z—ñ‚ÉŠi”[A‚»‚±‚Åstd::map‚Å—Dæ“x‚Æˆê‚ÉŠi”[‚µ‚Ä‚»‚ÌŒã•`ŽÊ
//‚Á‚Äˆ—‚ª‚æ‚³‚»‚¤

void UIUnitStateView::Render() {

	if (is_render_) {
		
		if (select_square_->GetSelectSquare()) {

			if (select_square_->GetSelectSquare()->GetAllyPtrInSquare()) {

				//DrawStringEx(0,700,-1,"‚±‚Ì–¡•û‚ÌHP‚Í%d", select_square_->GetAllyPtrInSquare()->GetCurrentHp());
				//‰º’nBox
				int ally_box_lower_right_x = ally_box_upper_left_x_ + width_;
				int ally_box_lower_right_y = ally_box_upper_left_y_ + height_;
				DrawBox(ally_box_upper_left_x_,ally_box_upper_left_y_, ally_box_lower_right_x, ally_box_lower_right_y, box_color_,true);
				
				//faceBox
				int face_box_upper_left_x = ally_box_upper_left_x_ + 5;
				int face_box_upper_left_y = ally_box_upper_left_y_ + 10;
				int face_box_w = width_ * 1 / 2;
				int face_box_h = height_ / 2;
				int face_box_lower_right_x = face_box_upper_left_x + face_box_w;
				int face_box_lower_right_y = face_box_upper_left_y + face_box_h;
				//int face_box_w = ally_box_upper_left_x_ + width_  * 1 / 3;
				//int face_box_h = ally_box_upper_left_y_ + height_ / 2;
				int face_graph = select_square_->GetSelectSquare()->GetAllyPtrInSquare()->GetAllyData()->GetTextureFace1()->getDxLibGraphHandle();
				DrawBox(face_box_upper_left_x, face_box_upper_left_y, face_box_lower_right_x, face_box_lower_right_y,255,true);
				//DrawExtendGraph(face_box_upper_left_x, face_box_upper_left_y, face_box_upper_left_x + face_box_w, face_box_upper_left_y + face_box_h,face_graph, false);

				//HpString
				DrawStringEx(face_box_upper_left_x,face_box_lower_right_y,256,"HP:%d/%d", select_square_->GetSelectSquare()->GetAllyPtrInSquare()->GetCurrentHp(), select_square_->GetSelectSquare()->GetAllyPtrInSquare()->GetMaxHp());

				//HpBar
				int hp_bar_upper_left_x = face_box_upper_left_x;
				int hp_bar_upper_left_y = ally_box_upper_left_y_ + (height_ / 2 ) + 25;
				int hp_bar_w = width_ - 10;
				int hp_bar_h = height_ / 6;
				
				int hp_bar_lower_right_x = hp_bar_upper_left_x + hp_bar_w;
				int hp_bar_lower_right_y = hp_bar_upper_left_y + hp_bar_h;


				float hp_ratio = static_cast<float>(select_square_->GetSelectSquare()->GetAllyPtrInSquare()->GetCurrentHp()) / static_cast<float>(select_square_->GetSelectSquare()->GetAllyPtrInSquare()->GetMaxHp());
				//bar_back
				DrawBox(face_box_upper_left_x, hp_bar_upper_left_y, hp_bar_lower_right_x, hp_bar_lower_right_y, hp_bar_back_color_, true);
				//bar
				DrawBox(face_box_upper_left_x, hp_bar_upper_left_y, hp_bar_lower_right_x * hp_ratio, hp_bar_lower_right_y, hp_bar_color_, true);
				//flame
				DrawBox(face_box_upper_left_x, hp_bar_upper_left_y, hp_bar_lower_right_x, hp_bar_lower_right_y, hp_bar_flame_color_, false);

				//State
				


			}
			else if (select_square_->GetSelectSquare()->GetEnemyInSquare()) {

				//‰º’nBox
				int enemy_box_lower_right_x = enemy_box_upper_left_x_ + width_;
				int enemy_box_lower_right_y = enemy_box_upper_left_y_ + height_;
				DrawBox(enemy_box_upper_left_x_, enemy_box_upper_left_y_, enemy_box_lower_right_x, enemy_box_lower_right_y, box_color_, true);

				//faceBox
		/*		int face_box_upper_left_x = enemy_box_upper_left_x_ + 5;
				int face_box_upper_left_y = enemy_box_upper_left_y_ + 5;
		*/		int face_box_w = width_ * 1 / 2;
				int face_box_h = height_ / 2;
				int face_box_lower_right_x = enemy_box_lower_right_x - 5;
				int face_box_lower_right_y = enemy_box_upper_left_y_ + face_box_h + 10;
				int face_box_upper_left_x = face_box_lower_right_x - face_box_w;
				int face_box_upper_left_y = face_box_lower_right_y - face_box_h;
				int face_graph = select_square_->GetSelectSquare()->GetEnemyPtrInSquare()->GetEnemyData()->GetTextureFace()->getDxLibGraphHandle();
				
				DrawBox(face_box_upper_left_x, face_box_upper_left_y, face_box_lower_right_x, face_box_lower_right_y, 255, true);
				//DrawExtendGraph(face_box_upper_left_x, face_box_upper_left_y, face_box_upper_left_x + face_box_w, face_box_upper_left_y + face_box_h, face_graph, false);

				//HPString
				DrawStringEx(face_box_upper_left_x, face_box_lower_right_y, 256, "HP:%d/%d", select_square_->GetSelectSquare()->GetEnemyPtrInSquare()->GetCurrentHp(), select_square_->GetSelectSquare()->GetEnemyPtrInSquare()->GetMaxHp());

				//HpBar
				int hp_bar_upper_left_x = enemy_box_upper_left_x_ + 5;
				int hp_bar_upper_left_y = enemy_box_upper_left_y_ + (height_ / 2) + 25;
				int hp_bar_w = width_ - 10;
				int hp_bar_h = height_ / 6;
				int hp_bar_lower_right_x = hp_bar_upper_left_x + hp_bar_w;
				int hp_bar_lower_right_y = hp_bar_upper_left_y + hp_bar_h;

				float hp_ratio = static_cast<float>(select_square_->GetSelectSquare()->GetEnemyPtrInSquare()->GetCurrentHp()) / static_cast<float>(select_square_->GetSelectSquare()->GetEnemyPtrInSquare()->GetMaxHp());
				int x = hp_bar_lower_right_x - (int)(hp_bar_w * hp_ratio);

				//bar_back
				DrawBox(hp_bar_upper_left_x, hp_bar_upper_left_y, hp_bar_lower_right_x, hp_bar_lower_right_y, hp_bar_back_color_, true);				
				//bar
				DrawBox(x, hp_bar_upper_left_y, hp_bar_lower_right_x, hp_bar_lower_right_y, hp_bar_color_, true);
				//flame
				DrawBox(hp_bar_upper_left_x, hp_bar_upper_left_y, hp_bar_lower_right_x, hp_bar_lower_right_y, hp_bar_flame_color_, false);



				

			}

		}


		//‰º’n
		//DrawBox(pos_x_, pos_y_, pos_x_ + width_, pos_y_ + height_, -1, false);


	}

}
