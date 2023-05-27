#pragma once
#include "gm_ui_component.h"
#include "gm_ui_panel.h"

//memo
//UIPanel�ɃN���b�N�ŉ��炩�̏������s����@�\��ǉ������N���X
//�����̎�����Mediator�N���X�ōs��


class UIButton : public UIPanel {
public:

	UIButton(int x, int y, int width, int height ) : UIPanel(x,y,width,height) {
	
	}
	~UIButton() {}

	void Update(float delta_time) override;

	//�N���b�N�̎��
	enum class ClickType {
		Trigger
	};

	//menber
	bool IsClicked(int mouse_x, int mouse_y);
	//void SetClickLeftOrRight();

private:


	//tnl::Input::eMouse input_click_ = tnl::Input::eMouseTrigger:;



};
