#pragma once
#include "gm_ui_component.h"

//memo
//パネルを表示



class UIPanel : public UIComponent{
public:
	
	//arg1~4左下頂点座標x,yと右下頂点座標x2,y2を指定
	//arg5...Panelに貼り付ける画像のハンドル
	UIPanel(int x, int y, int width, int height){	
		x_ = x;
		y_ = y;
		width_ = width;
		height_ = height;
		
	}
	~UIPanel(){}


	void Update(float delta_time) override;
	void Render() override;

	//setter
	void setGraphHandle(int graph_handle) { graph_handle_ = graph_handle; }

private:

	int x_;
	int y_;

	int graph_handle_;
	int width_;
	int height_;


};