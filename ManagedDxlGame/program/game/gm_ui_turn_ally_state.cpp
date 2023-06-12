#include "gm_ui_turn_ally_state.h"


void UITurnAllyState::Update(float delta_time) {

	if (unit_ally_) {

		turn_ally_icon_ = unit_ally_->GetAllyData()->GetTextureFace2()->getDxLibGraphHandle();

		ui_card_cost_->Update(delta_time);
		ui_move_cost_->Update(delta_time);
		ui_hp_bar_->Update(delta_time);

	}


}

void UITurnAllyState::Render() {

	if (unit_ally_) {

		//‰º’n
		DrawBox(x_, y_, x_ + width_, y_ + height_, sitaji_, true);

		DrawExtendGraph(x_, y_, x_ + width_, y_ + (layer_ * 2), turn_ally_icon_, true);


		ui_card_cost_->Render();
		ui_move_cost_->Render();
		ui_hp_bar_->Render();

	}


}