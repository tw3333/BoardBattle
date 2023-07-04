#include "gm_ui_card_hand.h"

void UICardHand::Update(float delta_time) {

	tnl::Vector3 msv = tnl::Input::GetMousePosition();

	if (hand_cards_.size() == 1) {

		

	}

	for (auto uc : ui_cards_) {

		if (GetMouseInsideTopCard(msv.x, msv.y) == uc) {
			continue;
		}
		uc->SetIsCardUp(false);
	}


	UICard* selected_card = GetMouseInsideTopCard(msv.x, msv.y);
	
	if (selected_card) {

		selected_card->SetIsCardUp(true);
	}


	
	

	for (auto uc: ui_cards_) {


		uc->Update(delta_time);
	}


}

void UICardHand::Render() {


	for (auto uc : ui_cards_) {

		uc->Render();
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
