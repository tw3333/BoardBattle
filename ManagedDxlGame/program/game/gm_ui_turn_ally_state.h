#pragma once

#include "gm_ui_component.h"
#include "gm_ui_hp_bar.h"
#include "gm_ui_move_cost.h"
#include "gm_ui_card_cost.h"
#include "gm_unit_ally.h"


//memo
//turnが回ってきたAllyのステータス用UI


class UITurnAllyState : public UIComponent {
public:

	UITurnAllyState(int x, int y, int width, int height, UnitAlly* unit_){
		
		x_ = x;
		y_ = y;
		width_ = width;
		height_ = height;

		unit_ally_ = unit_;




	}
	~UITurnAllyState(){}

	void Update(float delta_time) override;
	void Render() override;

	//member
	void SetUnitAlly(UnitAlly* unit) { 
		unit_ally_ = unit;
		ui_card_cost_->SetUnitAlly(unit);
		ui_move_cost_->SetUnitAlly(unit);
		ui_hp_bar_->SetUnitAlly(unit);
	}



private:

	UnitAlly* unit_ally_;

	UICardCost* ui_card_cost_ = nullptr;
	UIMoveCost* ui_move_cost_ = nullptr;
	UIHpBar* ui_hp_bar_ = nullptr;

	int turn_ally_icon_ = 0;

	
	int x_;
	int y_;

	int width_;
	int height_;




};