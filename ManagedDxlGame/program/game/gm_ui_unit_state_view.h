#pragma once
#include "gm_ui_component.h"

#include "gm_select_square.h"
#include "gm_data_battle_state.h"

class Square;

class UIUnitStateView : public UIComponent {
public:
	
	//arg1,2...四角形の幅と高さ
	UIUnitStateView(int w, int h,SelectSquare* select_square) 
	: width_(w), height_(h), select_square_(select_square) {
	
	}
	~UIUnitStateView() { delete select_square_; }



	void Update(float delta_time)override;
	void Render() override;
	
	
	void RenderAllyBox();
	void RenderEnemyBox();
	void RenderBattleState(std::vector<BattleState>& battle_state);

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

	//grahp(debug)
	//TODO:csvから変更。ここで定義しないように
	int icon_shield_ = LoadGraph("graphics/ui/battlestate_icon/icon_shield.png");
	int icon_blood_ = LoadGraph("graphics/ui/battlestate_icon/icon_blood.png");
	int icon_poison_ = LoadGraph("graphics/ui/battlestate_icon/icon_poison.png");
	int icon_snare_ = LoadGraph("graphics/ui/battlestate_icon/icon_snare.png");
	int icon_stun_ = LoadGraph("graphics/ui/battlestate_icon/icon_stun.png");


	//color
	int box_color_ = GetColor(211,211,211);
	int hp_bar_color_ = GetColor(255,0,0);
	int hp_bar_back_color_ = GetColor(52,53,65);
	int hp_bar_flame_color_ = GetColor(0,0,0);
	int shield_font_color = GetColor(34,121,228);
	int blood_font_color = GetColor(228, 73, 59);
	int poison_font_color = GetColor(228, 73, 59);
	int snare_font_color = GetColor(228, 73, 59);
	int stun_font_color = GetColor(228, 73, 59);
};

