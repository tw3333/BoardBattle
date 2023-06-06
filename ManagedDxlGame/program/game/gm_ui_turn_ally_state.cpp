#include "gm_ui_turn_ally_state.h"


void UITurnAllyState::Update(float delta_time) {

	turn_ally_icon_ = unit_ally_->GetAllyData()->GetTextureFace1()->getDxLibGraphHandle();


	ui_card_cost_->Update(delta_time);
	ui_move_cost_->Update(delta_time);
	ui_hp_bar_->Update(delta_time);

}

void UITurnAllyState::Render() {

	DrawExtendGraph(x_,y_,width_/2, height_/2, turn_ally_icon_,true);


	ui_card_cost_->Render();
	ui_move_cost_->Render();
	ui_hp_bar_->Render();

}