#pragma once
#include "gm_ui_component.h"
#include "gm_ui_panel.h"

//memo
//UIPanelにクリックで何らかの処理を行える機能を追加したクラス
//処理の実装はMediatorクラスで行う


class UIButton : public UIPanel {
public:

	UIButton(int x, int y, int width, int height ) : UIPanel(x,y,width,height) {
	
	}
	~UIButton() {}

	void Update(float delta_time) override;

	//クリックの種類
	enum class ClickType {
		Trigger
	};

	//menber
	bool IsClicked(int mouse_x, int mouse_y);
	//void SetClickLeftOrRight();

private:


	//tnl::Input::eMouse input_click_ = tnl::Input::eMouseTrigger:;



};
