#pragma once
#include "gm_ui_component.h"
#include "gm_ui_panel.h"

//memo
//UIPanel�ɃN���b�N�ŉ��炩�̏������s����@�\��ǉ������N���X
//�����̎�����Mediator�N���X�ōs��


class UIButton : public UIPanel {
public:

	UIButton() {}

	//�������R���X�g���N�^
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
	bool IsOverMousePointer(int mouse_x , int mouse_y);
	//void SetClickLeftOrRight();

	bool GetIsOverMousePointer() { return is_over_mouse_p; }
	bool GetIsMouseHited() { return is_mouse_hited_; }
	void SetIsMouseHited(bool is_mouse_hited) { is_mouse_hited_ = is_mouse_hited; }
	void SetIsClicked(bool is_clicked) { is_clicked_ = is_clicked; }
	bool GetIsClicked() { return is_clicked_; }
	


private:

	bool is_over_mouse_p = false;
	bool is_mouse_hited_ = false;

	bool is_clicked_ = false;
	//tnl::Input::eMouse input_click_ = tnl::Input::eMouseTrigger:;



};
