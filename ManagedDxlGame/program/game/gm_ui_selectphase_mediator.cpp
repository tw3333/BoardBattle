#include "gm_ui_selectphase_mediator.h"

void UISelectPhaseMediator::Notify(UIComponent* sender, std::string tag_) {

	if (tag_ == "SwitchDungeonWindow") {

		
		panel_icon_dungeon_window_->SetIsEnabled(true);
		panel_icon_character_window_->SetIsEnabled(false);
		//dungeon_window_->SetIsEnabled(true);

		DrawStringEx(500, 500, -1, "Clicked!A");


	}
	
	if (tag_ == "SwitchCharacterWindow") {

		panel_icon_character_window_->SetIsEnabled(true);
		panel_icon_dungeon_window_->SetIsEnabled(false);

		dungeon_window_->SetIsEnabled(false);



		DrawStringEx(500,500,-1,"Clicked!B");

	}

	if (tag_ == "SwitchDungeonTab") {

		//DrawStringEx(500, 500, -1, "Clicked!");

		dungeon_window_->SetIsEnabled(false);


	}




}