#pragma once
#include "gm_ui_component.h"

//memo
//パネルを表示



class UIPanel : public UIComponent{
public:
	
	//arg1~4左下頂点座標x,yと右下頂点座標x2,y2を指定
	//arg5...Panelに貼り付ける画像のハンドル
	UIPanel(int x, int y, int x2, int y2,int img_handle){	
		x_ = x;
		y_ = y;
		x2_ = x2;
		y2_ = y2;
		img_handle_ = img_handle;
	}
	~UIPanel(){}


	void Update(float delta_time) override;
	void Render() override;


private:

	int x_;
	int y_;
	int x2_;
	int y2_;
	int img_handle_;


};