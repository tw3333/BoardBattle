#include "gm_ui_enemy_act_panel.h"

void UIEnemyActPanel::Update(float delta_time)
{
}

void UIEnemyActPanel::Render() {

	//DrawGraph(0, 0, test_g_, true);
	int width = 250;
	int height = 50;

	int upper_left_x = 800 - 125;
	int	upper_left_y = 30;


	DrawExtendGraph(upper_left_x, upper_left_y, upper_left_x +  width,upper_left_y + height, test_g_, true);

}
