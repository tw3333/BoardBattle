#pragma once
#include "gm_ui_button.h"
#include "gm_ui_component.h"

//memo
//UI全体を四角にし、そこからレイアウトが設定される


class UIPlayerActionButtons : public UIComponent{
public:

	//arg1,2...UI全体を四角とし、左上頂点座標x,y
	//arg3,4...UI全体を四角としたときの、width,height
	UIPlayerActionButtons(int x, int y, int width, int height) {

		//ui_components_[MoveButton] = new UIButton(x,y,width/2 -5,height/2 -5);
		//ui_components_[MoveButton]->SetMediator(this->mediator_);
		//ui_components_[MoveButton]->SetNotifyTag("MoveButton");

		//ui_components_[CardButton] = new UIButton(x + width / 2 +5, y, width/2 -5, height/2 -5);
		//ui_components_[CardButton]->SetMediator(this->mediator_);
		//ui_components_[CardButton]->SetNotifyTag("CardButton");

		//ui_components_[ToolButton] = new UIButton(x, y + height/2 +5, width/2 -5, height/2 -5);
		//ui_components_[ToolButton]->SetMediator(this->mediator_);
		//ui_components_[ToolButton]->SetNotifyTag("ToolButton");

		//ui_components_[TurnEndButton] = new UIButton(x + width/2 +5 ,y + height/2 +5, width/2 -5, height/2 -5);
		//ui_components_[TurnEndButton]->SetMediator(this->mediator_);
		//ui_components_[TurnEndButton]->SetNotifyTag("TurnEndButton");

		int w1 = width / 3;
		int y1 = height / 3;

		ui_components_[MoveButton] = new UIButton(x + w1, y, w1, y1);
		ui_components_[MoveButton]->SetMediator(this->mediator_);
		ui_components_[MoveButton]->SetNotifyTag("MoveButton");

		ui_components_[CardButton] = new UIButton(x + w1*2, y + y1, w1, y1);
		ui_components_[CardButton]->SetMediator(this->mediator_);
		ui_components_[CardButton]->SetNotifyTag("CardButton");

		ui_components_[ToolButton] = new UIButton(x, y + y1, w1, y1);
		ui_components_[ToolButton]->SetMediator(this->mediator_);
		ui_components_[ToolButton]->SetNotifyTag("ToolButton");

		ui_components_[TurnEndButton] = new UIButton(x + w1,y + y1*2,w1,y1);
		ui_components_[TurnEndButton]->SetMediator(this->mediator_);
		ui_components_[TurnEndButton]->SetNotifyTag("TurnEndButton");





	}
	~UIPlayerActionButtons(){}

	enum {
		MoveButton,
		CardButton,
		ToolButton,
		TurnEndButton,
		PartsMax
	};


	void Update(float delta_time) override;
	void Render() override;

	//member
	void SetMediators() {
		for (int i = 0; i < PartsMax; ++i) {

			ui_components_[i]->SetMediator(this->mediator_);
		}
	}

	UIComponent* GetUIComponentAtIndex(int index) {
		if (0 <= index && index <= PartsMax) {
			return ui_components_[index];
		}
		return nullptr;
	}



private:

	UIComponent* ui_components_[PartsMax];



};