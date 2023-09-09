#include "gm_ui_hp_bar.h"

void UIHpBar::Update(float delta_time) {

	if (unit_ally_) {
		
		//HPの更新
		current_hp_ = unit_ally_->GetCurrentHp();
		max_hp_ = unit_ally_->GetMaxHp();

		//HPの比率を計算
		hp_ratio_ = static_cast<float>(current_hp_) / static_cast<float>(max_hp_);

	}

}

void UIHpBar::Render() {

	if (unit_ally_) {

		
		DrawStringEx(x_, y_, color_black_, "HP:%d/%d", current_hp_, max_hp_);

		//HpBarBack
		DrawBox(x_, y_ + 25, x_ + width_, y_ + height_, hp_bar_back_color_, true);

		//Hpの比率で変形するHPバー
		DrawBox(x_, y_ + 25, x_ + (width_ * hp_ratio_), y_ + height_, color_red_, true);

		//HPバーの下地
		DrawBox(x_, y_ + 25, x_ + width_, y_ + height_, color_black_, false);

	}
}

