#include "gm_ui_card_hand.h"

#include <algorithm>

void UICardHand::Update(float delta_time) {

	tnl::Vector3 msv = tnl::Input::GetMousePosition();


	for (int i = 0; i < debug_count_; ++i) {
		ui_hand_[i]->SetIsEnable(true);
	}
	for (int i = debug_count_; i < ui_hand_.size(); ++i) {
		ui_hand_[i]->SetIsEnable(false);
	}

	
	for (auto uc : ui_hand_) {

		if (GetMouseInsideTopCard(msv.x, msv.y) == uc) {
			continue;
		}
		uc->SetIsCardUp(false);
	}


	select_card_ = GetMouseInsideTopCard(msv.x, msv.y);
	
	if (select_card_) {

		select_card_->SetIsCardUp(true);
	}

	//AdjustCardPos(hand_cards_.size());
	AdjustCardPos(debug_count_);



	for (auto uh : ui_hand_) {


		uh->Update(delta_time);
	}

	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_R)) {
		debug_count_ += 1;
	}

}

void UICardHand::Render() {

	for (int i = 0; i < debug_count_; ++i) {

		ui_hand_[i]->Render();

	}

	if (select_card_) {
		select_card_->Render();
	}


}

void UICardHand::AdjustCardPos(int card_num) {

	if (card_num <= 5) {

		for (int i = 0; i < card_num; ++i) {

			ui_hand_[i]->SetPos(pos_x_ + (card_w * i), pos_y_);

		}

	}
	else if (6 <= card_num) {
		
		overlap_ = card_w * (card_num - 5) / card_num -1;

		ui_hand_[0]->SetPos(pos_x_, pos_y_);

		for (int i = 1; i <= card_num; ++i) {

			ui_hand_[i]->SetPos(ui_hand_[i-1]->GetEndPosX() - overlap_, pos_y_);



		}

	}
	else if (10< card_num) {
		return;
	}

}

UICard* UICardHand::GetMouseInsideTopCard(int mx, int my)
{
	for (auto it = ui_hand_.rbegin(); it != ui_hand_.rend(); ++it) {
		
		if ((*it)->IsMouseInside(mx,my)) {
			if ((*it)->GetIsEnable() == true) {
				return *it;

			}		
		}
	}

	return nullptr;
}
