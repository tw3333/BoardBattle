#pragma once
#include "gm_ui_component.h"

#include "DxLib.h"


class UIEnemyActPanel : public UIComponent {
public:

	UIEnemyActPanel() {}
	~UIEnemyActPanel() {}

	void Update(float delta_time) override;
	void Render() override;




private:

	int test_g_ = LoadGraph("graphics/ui/ui_enemy_act_panel/act_panel_slime_1.png");


};