#include "gm_ui_unit_state_view.h"

#include "DxLib.h"
#include "gm_square.h"
#include "gm_unit_ally.h"
#include "gm_unit_enemy.h"



void UIUnitStateView::Update(float delta_time) {

	


}

//Todomemo
//状態異常の表現は一回Unitから抽出して配列に格納、そこでstd::mapで優先度と一緒に格納してその後描写
//って処理がよさそう

void UIUnitStateView::Render() {

	if (is_render_) {
		
		if (select_square_->GetSelectSquare()) {

			if (select_square_->GetSelectSquare()->GetAllyPtrInSquare()) {

				//DrawStringEx(0,700,-1,"この味方のHPは%d", select_square_->GetAllyPtrInSquare()->GetCurrentHp());
				//下地Box
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
				DrawExtendGraph(face_box_upper_left_x, face_box_upper_left_y, face_box_upper_left_x + face_box_w, face_box_upper_left_y + face_box_h,face_graph, false);

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
				//アタリ。この枠計算でBattleStateアイコンを表示
				int space = 10;
				int state_box_upper_left_x = face_box_lower_right_x + space;
				int state_box_upper_left_y = face_box_upper_left_y;
				int state_box_lower_right_x = ally_box_lower_right_x - space;
				int state_box_lower_right_y = face_box_lower_right_y;
				int state_box_w = state_box_lower_right_x - state_box_upper_left_x;
				int state_box_h = state_box_lower_right_y - state_box_upper_left_y;
				int state_box_w1 = state_box_w / 4;
				int state_box_h1 = state_box_h / 3;


				//DrawBox(face_box_lower_right_x + space, face_box_upper_left_y, ally_box_lower_right_x - space, face_box_lower_right_y, 255, false);

				DrawExtendGraph(state_box_upper_left_x, state_box_upper_left_y, state_box_upper_left_x + state_box_w1 * 1, state_box_upper_left_y + state_box_h1, icon_shield_, false);
				DrawExtendGraph(state_box_upper_left_x, state_box_upper_left_y + state_box_h1*1, state_box_upper_left_x + state_box_w1 * 1, state_box_upper_left_y + state_box_h1 * 2, icon_blood_, false);
				DrawExtendGraph(state_box_upper_left_x, state_box_upper_left_y + state_box_h1*2, state_box_upper_left_x + state_box_w1 * 1, state_box_upper_left_y + state_box_h1 * 3, icon_poison_, false);				
				DrawExtendGraph(state_box_upper_left_x + state_box_w1 * 2, state_box_upper_left_y, state_box_upper_left_x + state_box_w1 * 3, state_box_upper_left_y + state_box_h1 * 1, icon_snare_, false);
				DrawExtendGraph(state_box_upper_left_x + state_box_w1 * 2, state_box_upper_left_y + state_box_h1 * 1, state_box_upper_left_x + state_box_w1 * 3, state_box_upper_left_y + state_box_h1 * 2, icon_stun_, false);


				//シールドは別計算
				if (select_square_->GetSelectSquare()->GetAllyPtrInSquare()->GetShieldValue() > 0) {

					DrawStringEx(state_box_upper_left_x + state_box_w1 + 3, state_box_upper_left_y + 2,shield_font_color,"%d", select_square_->GetSelectSquare()->GetAllyPtrInSquare()->GetShieldValue());

				}

				//ターンの数値があった場合それを表示
				for (auto &state : select_square_->GetSelectSquare()->GetAllyPtrInSquare()->GetBattleState()) {

					if (state.GetState() == State::Blood && state.GetTurnCount() > 0) {
						DrawStringEx(state_box_upper_left_x + state_box_w1 + 3, state_box_upper_left_y + state_box_h1 * 1 + 2, blood_font_color, "%d",state.GetTurnCount());
					}
					else if (state.GetState() == State::Poison && state.GetTurnCount() > 0) {
						DrawStringEx(state_box_upper_left_x + state_box_w1 + 3, state_box_upper_left_y + state_box_h1 * 1 + 2,  poison_font_color, "%d", state.GetTurnCount());
					}
					else if (state.GetState() == State::Snare && state.GetTurnCount() > 0) {
						DrawStringEx(state_box_upper_left_x + state_box_w1 * 2 + state_box_w1 + 3, state_box_upper_left_y + 2, snare_font_color, "%d", state.GetTurnCount());
					}
					else if (state.GetState() == State::Stun && state.GetTurnCount() > 0) {
						DrawStringEx(state_box_upper_left_x + state_box_w1 * 2 + state_box_w1 + 3, state_box_upper_left_y + state_box_h1 * 1 + 2, stun_font_color, "%d",state.GetTurnCount());
					}

				}

			}
			else if (select_square_->GetSelectSquare()->GetEnemyInSquare()) {

				//下地Box
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
				DrawExtendGraph(face_box_upper_left_x, face_box_upper_left_y, face_box_upper_left_x + face_box_w, face_box_upper_left_y + face_box_h, face_graph, false);

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

				//State
				//アタリ。この枠計算でBattleStateアイコンを表示
				int space = 10;
				int state_box_upper_left_x = enemy_box_upper_left_x_ + space;
				int state_box_upper_left_y = enemy_box_upper_left_y_ + space;
				int state_box_lower_right_x = face_box_upper_left_x - space;
				int state_box_lower_right_y = face_box_lower_right_y;
				int state_box_w = state_box_lower_right_x - state_box_upper_left_x;
				int state_box_h = state_box_lower_right_y - state_box_upper_left_y;
				int state_box_w1 = state_box_w / 4;
				int state_box_h1 = state_box_h / 3;


				//DrawBox(state_box_upper_left_x, state_box_upper_left_y, state_box_lower_right_x, state_box_lower_right_y, 255, false);

				DrawExtendGraph(state_box_upper_left_x, state_box_upper_left_y, state_box_upper_left_x + state_box_w1 * 1, state_box_upper_left_y + state_box_h1, icon_shield_, false);

				DrawExtendGraph(state_box_upper_left_x, state_box_upper_left_y, state_box_upper_left_x + state_box_w1 * 1, state_box_upper_left_y + state_box_h1, icon_shield_, false);
				DrawExtendGraph(state_box_upper_left_x, state_box_upper_left_y + state_box_h1 * 1, state_box_upper_left_x + state_box_w1 * 1, state_box_upper_left_y + state_box_h1 * 2, icon_blood_, false);
				DrawExtendGraph(state_box_upper_left_x, state_box_upper_left_y + state_box_h1 * 2, state_box_upper_left_x + state_box_w1 * 1, state_box_upper_left_y + state_box_h1 * 3, icon_poison_, false);

				DrawExtendGraph(state_box_upper_left_x + state_box_w1 * 2, state_box_upper_left_y, state_box_upper_left_x + state_box_w1 * 3, state_box_upper_left_y + state_box_h1 * 1, icon_snare_, false);
				DrawExtendGraph(state_box_upper_left_x + state_box_w1 * 2, state_box_upper_left_y + state_box_h1 * 1, state_box_upper_left_x + state_box_w1 * 3, state_box_upper_left_y + state_box_h1 * 2, icon_stun_, false);


				//シールドは別計算
				if (select_square_->GetSelectSquare()->GetEnemyPtrInSquare()->GetShieldValue()) {

					DrawStringEx(state_box_upper_left_x + state_box_w1 + 3, state_box_upper_left_y + 2, shield_font_color, "%d", select_square_->GetSelectSquare()->GetEnemyPtrInSquare()->GetShieldValue());

				}

				//ターンの数値があった場合それを表示
				for (auto& state : select_square_->GetSelectSquare()->GetEnemyPtrInSquare()->GetBattleState()) {

					if (state.GetState() == State::Blood && state.GetTurnCount() > 0) {
						DrawStringEx(state_box_upper_left_x + state_box_w1 + 3, state_box_upper_left_y + state_box_h1 * 1 + 2, blood_font_color, "%d", state.GetTurnCount());
					}
					else if (state.GetState() == State::Poison && state.GetTurnCount() > 0) {
						DrawStringEx(state_box_upper_left_x + state_box_w1 + 3, state_box_upper_left_y + state_box_h1 * 1 + 2, poison_font_color, "%d", state.GetTurnCount());
					}
					else if (state.GetState() == State::Snare && state.GetTurnCount() > 0) {
						DrawStringEx(state_box_upper_left_x + state_box_w1 * 2 + state_box_w1 + 3, state_box_upper_left_y + 2, snare_font_color, "%d", state.GetTurnCount());
					}
					else if (state.GetState() == State::Stun && state.GetTurnCount() > 0) {
						DrawStringEx(state_box_upper_left_x + state_box_w1 * 2 + state_box_w1 + 3, state_box_upper_left_y + state_box_h1 * 1 + 2, stun_font_color, "%d", state.GetTurnCount());
					}

				}

			}

		}

		//下地
		//DrawBox(pos_x_, pos_y_, pos_x_ + width_, pos_y_ + height_, -1, false);
	}

}

void UIUnitStateView::RenderAllyBox()
{
}

void UIUnitStateView::RenderEnemyBox()
{
}

void UIUnitStateView::RenderBattleState(std::vector<BattleState>& battle_state) {








}
