#pragma once
#include "gm_ui_component.h"
#include "gm_unit_ally.h"

//memo
//UnitAllyのポインタを渡してHPバーを表示できるUI


class UIHpBar : public UIComponent{
public:

	UIHpBar(int x, int y, int width, int height, UnitAlly* unit_ally) {
		
		x_ = x;
		y_ = y;
		width_ = width;
		height_ = height;
		
		unit_ally_ = unit_ally;
		current_hp_ = unit_ally_->GetCurrentHp();
		max_hp_ = unit_ally_->GetMaxHp();

	}

	~UIHpBar() { delete unit_ally_; }

	void Update(float delta_time) override;
	void Render() override;

	//member


private:

	UnitAlly* unit_ally_ = nullptr;

	int current_hp_;
	int max_hp_;
	float hp_ratio_ = 0;
	
	int x_;
	int y_;

	int width_;
	int height_;

	//ColorCode
	int color_red_ = GetColor(255,0,0);
	int color_black_ = GetColor(0, 0, 0);


};
