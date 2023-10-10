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

	UITurnAllyState(int x, int y, int width, int height){
		
		x_ = x;
		y_ = y;
		width_ = width;
		height_ = height;

		layer_ = height_ / 5;

		ui_hp_bar_ = new UIHpBar(x_,y_ + layer_ * 2, x_ + width_,layer_);
		ui_card_cost_ = new UICardCost(x_ , y_ + layer_ * 3, x_ + width_ ,layer_);
		ui_move_cost_ = new UIMoveCost(x_, y_ + layer_ * 4, x_ + width_,layer_ );


	}
	~UITurnAllyState() { 
		delete unit_ally_;
		delete ui_card_cost_;
		delete ui_move_cost_;
		delete ui_hp_bar_;
	}

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

	UnitAlly* unit_ally_ = nullptr;

	UICardCost* ui_card_cost_ = nullptr;
	UIMoveCost* ui_move_cost_ = nullptr;
	UIHpBar* ui_hp_bar_ = nullptr;

	int turn_ally_icon_ = 0;
	int x_;
	int y_;

	int width_;
	int height_;

	int layer_;

	//ColorCode
	int sitaji_ = GetColor(208,201,193);


};