#pragma once
#include "gm_ui_component.h"

#include "../dxlib_ext/dxlib_ext.h"


class UIDeckEdit : public UIComponent {
public:

	UIDeckEdit() {}
	~UIDeckEdit() {}

	void Update(float delta_time) override;
	void Render() override;


private:

	int h1 = DXE_WINDOW_HEIGHT / 10;
	int w1 = DXE_WINDOW_WIDTH / 10;

	int box_space_ = 10;
	//leftboxpos
	int leftbox_upper_left_x = 0 + box_space_;
	int leftbox_upper_left_y = 0 + box_space_;
	int leftbox_lower_right_x = w1*2 - box_space_;
	int	leftbox_lower_right_y = h1*10 - box_space_;
	//middleboxpos
	int middlebox_upper_left_x = w1*2 + box_space_;
	int middlebox_upper_left_y = 0 + box_space_;
	int middlebox_lower_right_x = w1*7 - box_space_;
	int	middlebox_lower_right_y = h1*10 - box_space_;
	//rightboxpos
	int rightbox_upper_left_x = w1*7 + box_space_;
	int rightbox_upper_left_y = 0 + box_space_;
	int rightbox_lower_right_x = w1*10 - box_space_;
	int	rightbox_lower_right_y = h1*10 - box_space_;


	//color
	int leftbox_color = GetColor(52, 53, 65);
	int middlebox_color = GetColor(52, 53, 65);
	int rightbox_color = GetColor(52, 53, 65);


};