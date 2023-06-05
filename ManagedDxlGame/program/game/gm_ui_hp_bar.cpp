#include "gm_ui_hp_bar.h"

void UIHpBar::Update(float delta_time) {

	//HP�̍X�V
	current_hp_ = unit_ally_->GetCurrentHp();
	max_hp_ = unit_ally_->GetMaxHp();

	//HP�̔䗦���v�Z
	hp_ratio_ = static_cast<float>(current_hp_) / static_cast<float>(max_hp_);

}

void UIHpBar::Render() {

	DrawStringEx(x_,y_,-1,"HP:%d/%d",current_hp_,max_hp_);

	//Hp�̔䗦�ŕό`����HP�o�[
	DrawBox(x_ , y_ + 25, x_ + (width_ * hp_ratio_) , y_ + height_ ,color_red_,true);

	//HP�o�[�̉��n
	DrawBox(x_, y_ + 25, x_ + width_, y_ + height_, color_black_, false);


}