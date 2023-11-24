#include "gm_ui_card.h"

#include "DxLib.h"
#include "../dxlib_ext/dxlib_ext.h"
#include "gm_card.h"

#include <vector>
#include <locale>
#include <clocale>
#include <cwchar>

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

	//DrawStringEx(500,40,-1,"Render:UICard");


	if (is_render_) {

		if (card_ptr_) {

			//DrawStringEx(500, 60 + debug_txt_y_, -1, "RenderUICard[%d]", debug_cnt_);

			//全体下地
			DrawBox(pos_x_, pos_y_, pos_x_ + width_, pos_y_ + height_, color_black_, true);
			DrawBox(pos_x_ + 4, pos_y_ + 4, pos_x_ + width_ - 4, pos_y_ + height_ - 4, color_ground_work_, true);

			//画像下地
			//DrawBox(pos_x_ + 5, pos_y_ + 5, pos_x_ + width_ -5, pos_y_ + h1_*6 -5, color_black_, false);
			//DrawExtendGraph(pos_x_ + 5, pos_y_ + 5, pos_x_ + width_ - 5, pos_y_ + h1_ * 6 - 5, debug_graph_, true);
			DrawExtendGraph(pos_x_ + 5, pos_y_ + 5, pos_x_ + width_ - 5, pos_y_ + h1_ * 6 - 5, card_ptr_->GetCardData()->GetCardTexture()->getDxLibGraphHandle(), true);

			//効果文Box
			DrawBox(pos_x_ + 5, pos_y_ + h1_ * 6, pos_x_ + w1_ * 10 - 5, pos_y_ + h1_ * 10 - 1, color_black_, true);
			DrawBox(pos_x_ + 7, pos_y_ + h1_ * 6 + 2, pos_x_ + w1_ * 10 - 7, pos_y_ + h1_ * 10 - 3, color_effect_back_, true);

			//split_explanation_ = SplitStringConsideringWidth(card_ptr_->GetCardData()->GetCardExplanation(), 10);
			split_explanation_ = SplitStringConsideringWidth(card_ptr_->GetCardData()->GetCardExplanation(), 18);


			for (int i = 0; i < split_explanation_.size(); ++i) {
				int n = i * 15;
				DrawFormatStringToHandle(pos_x_ + 7 + 3, pos_y_ + h1_ * 6 + 5 + n, -1, font_mgr_.GetCardExplanationFont(), "%s", split_explanation_[i].c_str());
			}

			int cnt = 0;
			for (auto& e : split_explanation_) {

				DrawFormatStringToHandle(pos_x_ + 7 + 3, pos_y_ + h1_ * 6 + 5 + (cnt * 15), -1, font_mgr_.GetCardExplanationFont(), "%s", e.c_str());
				cnt++;
			}

			//for (int i = 0; i < split_explanation_.size(); ++i) {
			//	DrawFormatStringToHandle(pos_x_ + 7, pos_y_ + h1_ * 6 + 2, -1, font_mgr_.GetCardExplanationFont(),"%s", split_explanation_[i]);
			//}

			//Costを表示するBox
			DrawBox(pos_x_ + 4, pos_y_ + 4, pos_x_ + 36, pos_y_ + 30, color_orange_, true);
			DrawBox(pos_x_ + 4, pos_y_ + 4, pos_x_ + 36, pos_y_ + 30, color_black_, false);

			if (card_ptr_->GetCardData()->GetCardCost() < 10) {
				DrawFormatStringToHandle(pos_x_ + 4 + 7, pos_y_ + 5, color_black_, font_mgr_.GetCardCostFont(), "%d", card_ptr_->GetCardData()->GetCardCost());
			}
			else if (10 <= card_ptr_->GetCardData()->GetCardCost()) {
				DrawFormatStringToHandle(pos_x_ + 4 + 2, pos_y_ + 5, color_black_, font_mgr_.GetCardCostFont(), "%d", card_ptr_->GetCardData()->GetCardCost());
			}




			//カード名下地
			DrawBox(pos_x_ + w1_ * 0.5, pos_y_ + h1_ * 5, pos_x_ + w1_ * 9.5, pos_y_ + h1_ * 6, color_cardname_back_, true);
			//DrawFormatStringToHandle(pos_x_ + w1_ * 2, pos_y_ + h1_ * 5, -1, font_mgr_.GetCardNameFont(), "デバックカード");
			DrawFormatStringToHandle(pos_x_ + w1_ * 0.5 + 10, pos_y_ + h1_ * 5 + 2, -1, font_mgr_.GetCardNameFont(), "%s",card_ptr_->GetCardData()->GetCardName().c_str());

		}


	}

}

bool UICard::IsMouseInside(int mx, int my) {

	if (pos_x_ < mx && mx < pos_x_ + width_ && pos_y_ < my && my < pos_y_ + height_) {

		return true;
	}

	return false;
}

std::vector<std::string> UICard::SplitCardExplanation(const std::string &explanation, int n) {

	std::vector<std::string> split;
	
	for (int i = 0; i < explanation.size(); i += n) {

		split.push_back(explanation.substr(i,n));

	}

	return split;
}



//gpt
int UICard::GetCharW(const std::string& s, size_t& i) {
	wchar_t wc;
	mbstate_t state = {};
	const char* ptr = s.data() + i;
	int len = std::mbtowc(&wc, ptr, s.size() - i);
	if (len == -1) {
		// エラーが発生。通常は適切に処理すべきですが、ここではエラーとして扱います。
		throw std::runtime_error("Invalid multibyte character.");
	}
	i += len;
	return (wc >= 0x0100) ? 2 : 1;
}



std::vector<std::string> UICard::SplitStringConsideringWidth(const std::string& s, int interval) {
	
	std::vector<std::string> result;
	int width_counter = 0;
	size_t start_index = 0;

	for (size_t i = 0; i < s.size(); ) {
		int char_width = GetCharWidthAndAdvance(s, i);

		if (width_counter + char_width > interval) {
			result.push_back(s.substr(start_index, i - start_index));
			start_index = i;
			width_counter = 0;
		}
		else {
			width_counter += char_width;
		}
	}

	if (start_index != s.size()) {
		result.push_back(s.substr(start_index));
	}

	return result;
}

int UICard::GetCharWidthAndAdvance(const std::string& s, size_t& i) {

	unsigned char c = static_cast<unsigned char>(s[i]);
	// ASCIIや半角カタカナの場合
	if (c <= 0x7F || (c >= 0xA1 && c <= 0xDF)) {
		i++;
		return 1;
	}
	
	// 全角文字の場合（Shift-JIS の先頭バイトとして有効な範囲）
	else if ((c >= 0x81 && c <= 0x9F) || (c >= 0xE0 && c <= 0xFC)) {
		if (i + 1 >= s.size()) {
			throw std::runtime_error("Invalid Shift-JIS sequence.");
		}
		i += 2;
		return 2;
	}
	else {
		throw std::runtime_error("Invalid Shift-JIS character.");
	}
}

