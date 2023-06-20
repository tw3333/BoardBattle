#include "gm_ui_turn_view.h"

void UITurnView::Update(float delt_time) {

	if (reset_) {

		if (!all_units_.empty()) {

			for (auto au : all_units_) {

				if (au->GetUnitType() == UnitType::Ally) {
					ally_ = static_cast<UnitAlly*>(au);
					unit_graph_handles_.push_back(ally_->GetAllyData()->GetTextureFace1()->getDxLibGraphHandle());
					ally_ = nullptr;
				}
				else if (au->GetUnitType() == UnitType::Enemy) {
					enemy_ = static_cast<UnitEnemy*>(au);
					unit_graph_handles_.push_back(enemy_->GetEnemyData()->GetTextureFace()->getDxLibGraphHandle());
				}

			}

		}

		reset_ = false;
	}


}

void UITurnView::Render() {

	//‰º’n
	DrawBox(x_ - 10,y_ -10 ,x_ + width_ + 10, y_ + height_ + 10, color_ground_work_,true);

	int w1 = width_ / all_units_.size();

	for (int i = 0; i < unit_graph_handles_.size(); ++i) {

		DrawExtendGraph(x_ + (w1*i), y_, x_ + w1 + (w1 * i), y_ + height_, unit_graph_handles_[i], false);

	}



}
