#pragma once
#include "gm_ui_component.h"

#include "DxLib.h"
#include "gm_ui_button.h"

//ボタンクラス用enum
enum TitleButton {
	START_BUTTON,
	QUIT_GAME_BUTTON,
	PartsNum
};


class UITitle : public UIComponent {
public:

	UITitle(){
		//初期Sceneで使うため関数でロード
		UITitleLoadGraph(); 
		UITitleLoadSound();
		
		auto b_start = new UIButton();
		b_start->setGraphHandle(start_button_graph);
		b_start->SetTransGraph(true);
		b_start->SetSize(300,50);
		b_start->SetPos(DXE_WINDOW_WIDTH/2 - 130, DXE_WINDOW_HEIGHT/ 2);
		title_buttons_[START_BUTTON] = b_start;

		auto b_quit_game = new UIButton();
		b_quit_game->setGraphHandle(quit_game_button_graph);
		b_quit_game->SetTransGraph(true);
		b_quit_game->SetSize(300, 50);
		b_quit_game->SetPos(DXE_WINDOW_WIDTH / 2 - 130, DXE_WINDOW_HEIGHT / 2 + 100);
		title_buttons_[QUIT_GAME_BUTTON] = b_quit_game;

	}
	~UITitle(){}

	void UITitleLoadGraph(); //初期Sceneで使うため関数でロード
	void UITitleLoadSound();
	void Update(float delta_time);
	void Render();


private:

	UIButton* title_buttons_[TitleButton::PartsNum];

	bool is_push_start_button_ = false;
	bool is_push_quit_game_button_ = false;

	bool play_se_math_cursor_title_button_ = false;
	bool is_mouse_hited_button_ = false;

	int back_graph_ = 0;

	int start_button_graph = 0;
	int start_button_graph_on = 0;
	int quit_game_button_graph = 0;
	int quit_game_button_graph_on = 0;

	int se_math_cursor_title_button_ = 0;
	int se_push_title_button_ = 0;

};