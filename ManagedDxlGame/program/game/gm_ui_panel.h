#pragma once
#include "gm_ui_component.h"

//memo
//�p�l����\��



class UIPanel : public UIComponent{
public:
	
	//arg1~4�������_���Wx,y�ƉE�����_���Wx2,y2���w��
	//arg5...Panel�ɓ\��t����摜�̃n���h��
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