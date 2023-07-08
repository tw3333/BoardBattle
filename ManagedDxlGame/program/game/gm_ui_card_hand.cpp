#include "gm_ui_card_hand.h"

void UICardHand::Update(float delta_time) {

	tnl::Vector3 msv = tnl::Input::GetMousePosition();

	
	for (auto uc : ui_cards_) {

		if (GetMouseInsideTopCard(msv.x, msv.y) == uc) {
			continue;
		}
		uc->SetIsCardUp(false);
	}


	select_card_ = GetMouseInsideTopCard(msv.x, msv.y);
	
	if (select_card_) {

		select_card_->SetIsCardUp(true);
	}


	
	

	for (auto uc: ui_cards_) {


		uc->Update(delta_time);
	}


}

void UICardHand::Render() {


	for (auto uc : ui_cards_) {

		uc->Render();
	}

	if (select_card_) {
		select_card_->Render();
	}

}

UICard* UICardHand::GetMouseInsideTopCard(int mx, int my)
{
	for (auto it = ui_cards_.rbegin(); it != ui_cards_.rend(); ++it) {
		
		if ((*it)->IsMouseInside(mx,my)) {
			return *it; 
		
		}
	}

	return nullptr;
}
