#pragma once
#include "gm_ui_component.h"

class UICard : public UIComponent {
public:

	UICard(int x, int y, int width, int height)
	: pos_x_(x), pos_y_(y), width_(width), height_(height)
	{}
	~UICard(){}

	void Update(float delta_time) override;
	void Render() override;


private:

	int pos_x_;
	int pos_y_;

	int width_;
	int height_;

	int w1_ = width_ / 10;
	int h1_ = height_ / 10;

	//ColorCode
	int	color_ground_work_ = GetColor(211,204,196);
	int color_black_ = GetColor(0,0,0);
	int color_effect_back_ = GetColor(83,61,49);
	int color_cardname_back_ = GetColor(129,58,57);
	int color_cardname_flame_ = GetColor(67,45,37);
	int color_orange_ = GetColor(255, 165, 0);

};