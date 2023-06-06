#pragma once
#include "gm_ui_component.h"
#include "gm_unit_ally.h"

//memo
//座標とその大きさから四角形
//左詰めでカードコストを〇で表示


class UICardCost : public UIComponent {
public:

	UICardCost(int x, int y, int width, int height, UnitAlly* ally) {
	
		x_ = x;
		y_ = y;
		width_ = width;
		height_ = height;
		radius_ = height_ / 2;

		unit_ally_ = ally;
		max_cost_ = unit_ally_->GetMaxCardCost();
		current_cost_ = unit_ally_->GetCurrentCardCost();

	}
	~UICardCost() { delete unit_ally_; }


	void Update(float delta_time) override;
	void Render() override;



private:

	UnitAlly* unit_ally_ = nullptr;

	int max_cost_;
	int current_cost_;

	int x_;
	int y_;

	int width_;
	int height_;
	int radius_;



	//ColorCode
	int color_black_ = GetColor(0,0,0);
	int color_orange_ = GetColor(255,165,0);



};