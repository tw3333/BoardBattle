#pragma once
#include "gm_ui_component.h"
#include "gm_unit_ally.h"

//memo
//座標とその大きさから四角形
//左詰めでカードコストを〇で表示


class UICardCost : public UIComponent {
public:

	UICardCost(int x, int y, int width, int height) {
	
		x_ = x;
		y_ = y;
		width_ = width;
		height_ = height;
		radius_ = height_ / 2;

	}
	~UICardCost() { delete unit_ally_; }


	void Update(float delta_time) override;
	void Render() override;

	void SetUnitAlly(UnitAlly* unit_ally) { unit_ally_ = unit_ally; }

private:

	UnitAlly* unit_ally_ = nullptr;

	int max_cost_ = 0;
	int current_cost_ = 0;

	int x_;
	int y_;

	int width_;
	int height_;
	int radius_;

	int graph_card_icon_ = LoadGraph("graphics/ui/card_icon.png");

	//ColorCode
	int color_black_ = GetColor(0,0,0);
	int color_yellow_ = GetColor(255,255,0);
	int color_orange_ = GetColor(255,170,0);
	int color_red_ = GetColor(255,85,0);


};