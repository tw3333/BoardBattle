#pragma once
#include "gm_ui_component.h"

class UICard : public UIComponent {
public:

	UICard(int x, int y, int width, int height)
	: pos_x_(x), pos_y_(y), width_(width), height_(height)
	{}
	~UICard(){}


	void Render() override;


private:

	int pos_x_;
	int pos_y_;

	int width_;
	int height_;

	//ColorCode
	int	color_ground_work_ = GetColor(211,204,196);


};