#pragma once
#include "gm_ui_component.h"
#include "gm_unit_ally.h"

//memo

class UIMoveCost : public UIComponent {
public:
	
	UIMoveCost(int x, int y, int width, int height, UnitAlly* ally){
		
		x_ = x;
		y_ = y;
		width_ = width;
		height_ = height;
		radius_ = height_ / 2;

		unit_ally_ = ally;
		max_cost_ = unit_ally_->GetMaxMoveCost();
		current_cost_ = unit_ally_->GetCurrentMoveCost();

	}

	~UIMoveCost(){}

	void Update(float delta_time) override;
	void Render() override;

	void SetUnitAlly(UnitAlly* unit_ally) { unit_ally_ = unit_ally; }

private:

	UnitAlly* unit_ally_ = nullptr;

	int max_cost_;
	int current_cost_;

	int x_;
	int y_;

	int width_;
	int height_;
	int radius_;

	int graph_move_icon_ = LoadGraph("graphics/ui/move_icon.png");


	//ColorCode
	int color_black_ = GetColor(0, 0, 0);
	int color_orange_ = GetColor(255, 165, 0);
	int color_blue_ = GetColor(100,149,237);

};