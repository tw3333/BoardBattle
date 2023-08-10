#pragma once
#include "gm_ui_component.h"
#include "gm_font_manager.h"


class UINoticeTargetBox : public UIComponent{
public:

	UINoticeTargetBox(int pos_x, int pos_y, int width, int height){
	
		pos_x_ = pos_x;
		pos_y_ = pos_y;
		width_ = width;
		height_ = height;
	
	}
	~UINoticeTargetBox(){}

	void Update(float delat_time) override;
	void Render() override;

	void SetTargetNum(int num) { target_num_ = num; }




private:

	bool is_render = false;

	int pos_x_ = 0;
	int pos_y_ = 0;
	int width_ = 0;
	int height_ = 0;

	int target_num_ = 1;

	//ColorCode
	int box_color_ = GetColor(229,229,229);
	int flame_color_ = GetColor(15,15,15);

	FontManager& font_mgr_ = FontManager::GetInstance();

};