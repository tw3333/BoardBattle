#pragma once
#include "gm_ui_component.h"

#include "gm_select_square.h"

class Square;

class UIUnitStateView : public UIComponent {
public:
	
	//arg1,2...éläpå`ÇÃïùÇ∆çÇÇ≥
	UIUnitStateView(int w, int h,SelectSquare* select_square) 
	: width_(w), height_(h), select_square_(select_square) {
	
	
	
	}
	~UIUnitStateView(){}



	void Update(float delta_time)override;
	void Render() override;

	void SetIsRender(bool is_render) { is_render_ = is_render; }
	void SetAllyBoxUpperLeftPos(int x, int y) {
		ally_box_upper_left_x_ = x;
		ally_box_upper_left_y_ = y;
	};
	void SetEnemyBoxUpperLeftPos(int x, int y){
		enemy_box_upper_left_x_ = x;
		enemy_box_upper_left_y_ = y;
	}


	

private:
	
	bool is_render_ = true;
	SelectSquare* select_square_ = nullptr;
	
	int ally_box_upper_left_x_ = 0;
	int ally_box_upper_left_y_ = 0;
	int enemy_box_upper_left_x_ = 0;
	int enemy_box_upper_left_y_ = 0;
	int width_ = 0;
	int height_ = 0;

	//color
	int box_color_ = GetColor(211,211,211);



};

