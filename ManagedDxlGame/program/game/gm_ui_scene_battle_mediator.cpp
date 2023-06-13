#include "gm_ui_scene_battle_mediator.h"
#include "scene/gm_scene_battle.h"


void UISceneBattleMediator::Notify(UIComponent* sender, std::string tag) {

	NotifyPlayerActionButton(is_player_action_button_enabled_,tag);



}

void UISceneBattleMediator::NotifyPlayerActionButton(bool is_enable, std::string tag) {

	if (is_enable) {

		if (tag == "MoveButton") {

			DrawStringEx(0, 500, -1, "MoveButton");
		

		}
		
		if (tag == "CardButton") {

			DrawStringEx(0, 500, -1, "CardButton");
		

		}
		
		if (tag == "ToolButton") {

			DrawStringEx(0, 500, -1, "ToolButton");
		}
		
		if (tag == "TurnEndButton") {

			DrawStringEx(0, 500, -1, "TurnButton");
	
		}

	}
	
}