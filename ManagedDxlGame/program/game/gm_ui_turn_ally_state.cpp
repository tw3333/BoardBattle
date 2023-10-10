#include "gm_ui_turn_ally_state.h"


void UITurnAllyState::Update(float delta_time) {

	if (unit_ally_) {
		turn_ally_icon_ = unit_ally_->GetAllyData()->GetTextureFace2()->getDxLibGraphHandle();
	}


	ui_card_cost_->Update(delta_time);
	ui_move_cost_->Update(delta_time);
	ui_hp_bar_->Update(delta_time);




}

void UITurnAllyState::Render() {

	//‰º’n
	DrawBox(x_, y_, x_ + width_, y_ + height_, sitaji_, true);
	DrawExtendGraph(x_, y_, x_ + width_, y_ + (layer_ * 2), turn_ally_icon_, true);
	
	ui_card_cost_->Render();
	ui_move_cost_->Render();
	ui_hp_bar_->Render();

	if (unit_ally_) {
		
		//Deck–‡”•\Ž¦
		DrawStringEx(x_ + (width_ / 2) + 70, y_ + (layer_ * 2) - 85, 255, "Deck:%d/%d", unit_ally_->GetUseDeck().size(), unit_ally_->GetBaseDeck().size());
		
		//Hand–‡”•\Ž¦
		//if (unit_ally_->GetHand().size() < 9) {//0~9 + 35
		//	DrawStringEx(x_ + (width_ / 2) + 35, y_ + (layer_ * 2) - 65, 255, "Hand:%d/Max[10]", unit_ally_->GetHand().size());
		//}
		//else if (unit_ally_->GetHand().size() == 10) {//10–‡ + 25
		//	DrawStringEx(x_ + (width_ / 2) + 25, y_ + (layer_ * 2) - 65, 255, "Hand:%d/Max[10]", unit_ally_->GetHand().size());
		//}

		if (unit_ally_->GetHand().size() == 10) {
			DrawStringEx(x_ + (width_ / 2) + 25, y_ + (layer_ * 2) - 65, 255, "Hand:%d/Max[10]", unit_ally_->GetHand().size());
		}
		else {
			DrawStringEx(x_ + (width_ / 2) + 35, y_ + (layer_ * 2) - 65, 255, "Hand:%d/Max[10]", unit_ally_->GetHand().size());
		}


	}

}