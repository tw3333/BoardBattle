#pragma once
#include "gm_ui_component.h"

//memo
//�p�l����\��



class UIPanel : public UIComponent{
public:
	
	//arg1~4�������_���Wx,y�ƉE�����_���Wx2,y2���w��
	//arg5...Panel�ɓ\��t����摜�̃n���h��
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