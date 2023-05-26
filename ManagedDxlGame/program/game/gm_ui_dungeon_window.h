#pragma once
#include "gm_ui_component.h"
#include "gm_ui_panel.h"
#include "gm_ui_button.h"
#include "gm_ui_mediator.h"



class DungeonWindow : public UIComponent {
public:

	//arg1,2...描写する左頂点座標
	//arg3,4...Window(Square)の大きさ(これを元に各Componentの基準になる)
	DungeonWindow(int x, int y,int width, int height) {
		window_posx_ = x;
		window_posy_ = y;
		window_w_ = width;
		window_h_ = height;
	}

	~DungeonWindow(){}


	void Update(float delta_time) override;
	void Render() override;

	void Create();

	//
	Shared<UIPanel>& GetWindow() { return window_; }


private:

	int window_posx_;
	int window_posy_;
	int window_w_;
	int window_h_;


	//Components
	Shared<UIPanel> window_;


};