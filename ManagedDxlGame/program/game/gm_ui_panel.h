#pragma once
#include "gm_ui_component.h"
#include "gm_easingfunctions.h"

//memo
//�p�l����\��



class UIPanel : public UIComponent{
public:
	
	//arg1,2...�`�ʂ��������㒸�_���W
	//arg3,4...�w�肵�����W����̉����ƍ���
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

	//easing�p�̊֐�
	void SetStartEasing(int start_x);
	void AnimationRender();

private:

	int x_; 	
	int y_; 
	int width_;
	int height_;

	int graph_handle_ = 0;

	//easing�p�̕ϐ�
	int start_x_; //�A�j���[�V�������߂̍����_���W
	int end_x_;	//�A�j���[�V�����I���
	int current_x_ = 0; //�A�j���[�V������
	float time_ = 0; //�A�j���[�V�����p�^�C�}�[
	float duration_ = 0.5f;
	bool is_moving_ = false;
	
};