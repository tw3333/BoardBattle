#include "gm_ui_selectphase_mediator.h"

void UISelectPhaseMediator::Notify(UIComponent* sender, std::string tag_) {

	if (tag_ == "SwitchDungeonWindow") {

		DrawStringEx(500, 500, -1, "Clicked!A");
	}
	
	if (tag_ == "SwitchCharacterWindow") {

		DrawStringEx(500,500,-1,"Clicked!B");

	}




}