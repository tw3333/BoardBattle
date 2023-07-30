#include "gm_ui_card.h"

#include "DxLib.h"
#include "../dxlib_ext/dxlib_ext.h"
#include "gm_card.h"
#include <vector>

void UICard::Update(float delta_time) {

	tnl::Vector3 msv = tnl::Input::GetMousePosition();

	//if (pos_x_ < msv.x && msv.x < pos_x_ + width_ && pos_y_ < msv.y && msv.y < pos_y_ + height_) {

	//	card_up_ = true;

	//}
	//else {
	//	card_up_ = false;
	//}

	if (card_up_) {
		
		pos_y_ = card_up_pos_y_;
		
	}
	else {
		pos_y_ = pre_pos_y_;
	}



	SetPos(pos_x_, pos_y_);

}

void UICard::Render() {

	DrawStringEx(500,40,-1,"Render:UICard");


	if (is_render_) {

		if (card_ptr_) {

			DrawStringEx(500, 60 + debug_txt_y_, -1, "RenderUICard[%d]", debug_cnt_);

			//�S�̉��n
			DrawBox(pos_x_, pos_y_, pos_x_ + width_, pos_y_ + height_, color_black_, true);
			DrawBox(pos_x_ + 4, pos_y_ + 4, pos_x_ + width_ - 4, pos_y_ + height_ - 4, color_ground_work_, true);

			//�摜���n
			//DrawBox(pos_x_ + 5, pos_y_ + 5, pos_x_ + width_ -5, pos_y_ + h1_*6 -5, color_black_, false);
			//DrawExtendGraph(pos_x_ + 5, pos_y_ + 5, pos_x_ + width_ - 5, pos_y_ + h1_ * 6 - 5, debug_graph_, true);
			DrawExtendGraph(pos_x_ + 5, pos_y_ + 5, pos_x_ + width_ - 5, pos_y_ + h1_ * 6 - 5, card_ptr_->GetCardData()->GetCardTexture()->getDxLibGraphHandle(), true);

			//���ʕ�Box
			DrawBox(pos_x_ + 5, pos_y_ + h1_ * 6, pos_x_ + w1_ * 10 - 5, pos_y_ + h1_ * 10 - 1, color_black_, true);
			DrawBox(pos_x_ + 7, pos_y_ + h1_ * 6 + 2, pos_x_ + w1_ * 10 - 7, pos_y_ + h1_ * 10 - 3, color_effect_back_, true);

			split_explanation_ = SplitCardExplanation(card_ptr_->GetCardData()->GetCardExplanation(), 10);

			for (int i = 0; i < split_explanation_.size(); ++i) {
				int n = i * 15;
				DrawFormatStringToHandle(pos_x_ + 7 + 3, pos_y_ + h1_ * 6 + 5 + n, -1, font_mgr_.GetCardExplanationFont(), "%s", split_explanation_[i].c_str());
			}

			//for (int i = 0; i < split_explanation_.size(); ++i) {
			//	DrawFormatStringToHandle(pos_x_ + 7, pos_y_ + h1_ * 6 + 2, -1, font_mgr_.GetCardExplanationFont(),"%s", split_explanation_[i]);
			//}

			//Cost��\������Box
			DrawBox(pos_x_ + 4, pos_y_ + 4, pos_x_ + 34, pos_y_ + 34, color_orange_, true);
			DrawFormatStringToHandle(pos_x_ + 4, pos_y_ + 4, -1, font_mgr_.GetCardCostFont(), "a%d");


			//�J�[�h�����n
			DrawBox(pos_x_ + w1_ * 0.5, pos_y_ + h1_ * 5, pos_x_ + w1_ * 9.5, pos_y_ + h1_ * 6, color_cardname_back_, true);
			//DrawFormatStringToHandle(pos_x_ + w1_ * 2, pos_y_ + h1_ * 5, -1, font_mgr_.GetCardNameFont(), "�f�o�b�N�J�[�h");
			DrawFormatStringToHandle(pos_x_ + w1_ * 2, pos_y_ + h1_ * 5, -1, font_mgr_.GetCardNameFont(), "%s",card_ptr_->GetCardData()->GetCardName().c_str());

		}


	}

}

bool UICard::IsMouseInside(int mx, int my) {

	if (pos_x_ < mx && mx < pos_x_ + width_ && pos_y_ < my && my < pos_y_ + height_) {

		return true;
	}

	return false;
}

std::vector<std::string> UICard::SplitCardExplanation(std::string explanation, size_t n)
{

	std::vector<std::string> split;
	
	for (size_t i = 0; i < explanation.length(); i += n) {

		split.push_back(explanation.substr(i,n));

	}

	return split;
}
