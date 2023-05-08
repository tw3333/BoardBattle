#include "gm_ui_handview.h"







void HandView::Render() {

	for (int i = 0; i < hand_card_data_.size(); ++i) {

		cards_view_.emplace_back(new CardView(hand_card_data_[i]));






	}






}