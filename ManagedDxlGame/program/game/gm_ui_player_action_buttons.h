#pragma once
#include "gm_ui_button.h"
#include "gm_ui_component.h"
#include "gm_unit_ally.h"


//memo
//UI全体を四角にし、そこからレイアウトが設定される

//座標格納用
struct UIButtonPos {
	int x;
	int y;
	int w;
	int h;
};



class UIPlayerActionButtons : public UIComponent{
public:

	//arg1,2...UI全体を四角とし、左上頂点座標x,y
	//arg3,4...UI全体を四角としたときの、width,height
	UIPlayerActionButtons(int x, int y, int width, int height) {

		pos_x_ = x;
		width_ = width;

		//ui_components_[MoveButton] = new UIButton(x,y,width/2 -5,height/2 -5);
		//ui_components_[MoveButton]->SetMediator(this->mediator_);
		//ui_components_[MoveButton]->SetNotifyTag("MoveButton");

		//ui_components_[CardButton] = new UIButton(x + width / 2 +5, y, width/2 -5, height/2 -5);
		//ui_components_[CardButton]->SetMediator(this->mediator_);
		//ui_components_[CardButton]->SetNotifyTag("CardButton");

		//ui_components_[ToolButton] = new UIButton(x, y + height/2 +5, width/2 -5, height/2 -5);
		//ui_components_[ToolButton]->SetMediator(this->mediator_);
		//ui_components_[ToolButton]->SetNotifyTag("ToolButton");

		//ui_components_[TurnEndButton] = new UIButton(x + width/2 +5 ,y + height/2 +5, width/2 -5, height/2 -5);
		//ui_components_[TurnEndButton]->SetMediator(this->mediator_);
		//ui_components_[TurnEndButton]->SetNotifyTag("TurnEndButton");

		int w1 = width / 3;
		int y1 = height / 3;

		auto ui_move_button = new UIButton(x, y, width, y1 * 1);
		move_button_ = ui_move_button;
		ui_move_button->setGraphHandle(g_move_);
		action_button_pos_ = {x,y,width, y1*1};

		auto ui_card_button = new UIButton(x, y + y1*1, width, y1 * 1);
		c_b_upper_left_x_ = x;
		c_b_upper_left_y_ = y + y1 * 1;
		c_b_lower_right_x_ = x + width;
		c_b_lower_right_y_ = y + y1 * 1 + y1 * 1;

		card_button_ = ui_card_button;
		ui_card_button->setGraphHandle(g_card_);

		auto ui_turnend_button = new UIButton(x, y + y1*2, width, y1*1);
		turn_end_button_ = ui_turnend_button;
		ui_turnend_button->setGraphHandle(g_turn_end_);
		
		ui_components_[MoveButton] = ui_move_button;
		ui_components_[MoveButton]->SetMediator(this->mediator_);
		ui_components_[MoveButton]->SetNotifyTag("MoveButton");

		ui_components_[CardButton] = ui_card_button;
		ui_components_[CardButton]->SetMediator(this->mediator_);
		ui_components_[CardButton]->SetNotifyTag("CardButton");
		
		ui_components_[TurnEndButton] = ui_turnend_button;
		ui_components_[TurnEndButton]->SetMediator(this->mediator_);
		ui_components_[TurnEndButton]->SetNotifyTag("TurnEndButton");



	}
	~UIPlayerActionButtons() { delete turn_ally_; }

	enum {
		MoveButton,
		CardButton,
		TurnEndButton,
		PartsMax
	};


	void Update(float delta_time) override;
	void Render() override;

	//member
	void SetMediators() {
		for (int i = 0; i < PartsMax; ++i) {

			ui_components_[i]->SetMediator(this->mediator_);
		}
	}

	UIComponent* GetUIComponentAtIndex(int index) {
		if (0 <= index && index <= PartsMax) {
			return ui_components_[index];
		}
		return nullptr;
	}

	int GetEndPosX() { return pos_x_ + width_; }
	void SetTurnAlly(UnitAlly* turn_ally) { turn_ally_ = turn_ally; }

private:

	UIComponent* ui_components_[PartsMax];
	UnitAlly* turn_ally_ = nullptr;

	UIButton *move_button_ = nullptr;
	UIButton *card_button_ = nullptr;
	UIButton *turn_end_button_ = nullptr;

	int c_b_upper_left_x_ = 0;
	int c_b_upper_left_y_ = 0;
	int	c_b_lower_right_x_ = 0;
	int c_b_lower_right_y_ = 0;

	//selectflamepos
	int s_f_upper_left_x_ = 0;
	int s_f_upper_left_y_ = 0;
	int s_f_lower_right_x_ = 0;
	int s_f_lower_right_y_ = 0;
	bool is_render_select_flame_ = false;

	int pos_x_ = 0;
	int width_ = 0;

	UIButtonPos action_button_pos_;
	UIButtonPos card_button_pos_;
	UIButtonPos turn_end_button_pos_;

	bool is_button_pushrd_ = false;

	int g_move_ = LoadGraph("graphics/ui/move.png");
	int g_card_ = LoadGraph("graphics/ui/card_button_flame.png");
	int g_init_draw_f_ = LoadGraph("graphics/ui/init_card_draw_flame.png");
	int g_draw_f_ = LoadGraph("graphics/ui/card_draw_flame.png");
	int g_card_f_ = LoadGraph("graphics/ui/card_flame.png");

	int g_turn_end_ = LoadGraph("graphics/ui/turnend.png");
	int g_select_flame_ = LoadGraph("graphics/ui/select.png");


};