#pragma once
#include "gm_ui_component.h"



class UIUnitStateView : public UIComponent
{
public:
	
	//arg1,2...éläpå`ÇÃïùÇ∆çÇÇ≥
	UIUnitStateView(int w, int h) : width_(w), height_(h){}
	~UIUnitStateView(){}



	void Update(float delta_time)override;
	void Render() override;


	void SetUpperLeftPos(int x, int y) { pos_x_ = x; pos_y_ = y; }
	void SetIsRender(bool is_render) { is_render_ = is_render; }
	void SetSelectSquare();

	

private:

	bool is_render_ = false;


	int pos_x_ = 0;
	int pos_y_ = 0;
	int width_ = 0;
	int height_ = 0;




};

