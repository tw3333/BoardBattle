#include "gm_ui_card.h"

#include "../dxlib_ext/dxlib_ext.h"

void UICard::Update(float delta_time) {

	tnl::Vector3 msv = tnl::Input::GetMousePosition();

	if (pos_x_ < msv.x && msv.x < pos_x_ + width_ && pos_y_ < msv.y && msv.y < pos_y_ + height_) {

		card_up_ = true;

	}
	else {
		card_up_ = false;
	}

	if (card_up_) {
		
		pos_y_ = card_up_pos_y_;
		
	}
	else {
		pos_y_ = pre_pos_y_;
	}


}

void UICard::Render() {

	if (is_render_) {

		//全体下地
		DrawBox(pos_x_, pos_y_, pos_x_ + width_, pos_y_ + height_, color_black_, true);

		DrawBox(pos_x_ + 4, pos_y_ + 4, pos_x_ + width_ - 4, pos_y_ + height_ - 4, color_ground_work_, true);

		//画像下地
		//DrawBox(pos_x_ + 5, pos_y_ + 5, pos_x_ + width_ -5, pos_y_ + h1_*6 -5, color_black_, false);
		DrawExtendGraph(pos_x_ + 5, pos_y_ + 5, pos_x_ + width_ - 5, pos_y_ + h1_ * 6 - 5, debug_graph_, true);

		//効果文Box
		DrawBox(pos_x_ + 5, pos_y_ + h1_ * 6, pos_x_ + w1_ * 10 - 5, pos_y_ + h1_ * 10 - 1, color_black_, true);
		DrawBox(pos_x_ + 7, pos_y_ + h1_ * 6 + 2, pos_x_ + w1_ * 10 - 7, pos_y_ + h1_ * 10 - 3, color_effect_back_, true);
		DrawFormatStringToHandle(pos_x_ + 7, pos_y_ + h1_ * 6 + 2, -1, font_mgr_.GetCardExplanationFont(), "debugようカードです");




		//Costを表示するBox
		DrawBox(pos_x_ + 4, pos_y_ + 4, pos_x_ + 34, pos_y_ + 34, color_orange_, true);
		DrawFormatStringToHandle(pos_x_ + 4, pos_y_ + 4, -1, font_mgr_.GetCardCostFont(), "a%d");


		//カード名下地
		DrawBox(pos_x_ + w1_ * 0.5, pos_y_ + h1_ * 5, pos_x_ + w1_ * 9.5, pos_y_ + h1_ * 6, color_cardname_back_, true);
		DrawFormatStringToHandle(pos_x_ + w1_ * 2, pos_y_ + h1_ * 5, -1, font_mgr_.GetCardNameFont(), "デバックカード");

	}

}
