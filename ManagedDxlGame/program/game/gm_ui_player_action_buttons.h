#pragma once
#include "gm_ui_button.h"
#include "gm_ui_component.h"

class UIPlayerActionButtons : public UIComponent{
public:

	UIPlayerActionButtons() {

		ui_components_[MoveButton] = new UIButton(0,0,0,0);
		ui_components_[MoveButton]->SetMediator(mediator_);
		ui_components_[MoveButton]->SetNotifyTag("MoveButton");

		ui_components_[CardButton] = new UIButton(0, 0, 0, 0);
		ui_components_[CardButton]->SetMediator(mediator_);
		ui_components_[CardButton]->SetNotifyTag("CardButton");

		ui_components_[ToolButton] = new UIButton(0, 0, 0, 0);
		ui_components_[ToolButton]->SetMediator(mediator_);
		ui_components_[ToolButton]->SetNotifyTag("ToolButton");

		ui_components_[TurnEndButton] = new UIButton(0, 0, 0, 0);
		ui_components_[TurnEndButton]->SetMediator(mediator_);
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