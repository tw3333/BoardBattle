#include "gm_ui_scene_battle_mediator.h"
#include "scene/gm_scene_battle.h"


void UISceneBattleMediator::Notify(UIComponent* sender, std::string tag) {

	NotifyPlayerActionButton(is_player_action_button_enabled_,tag);



}

void UISceneBattleMediator::NotifyPlayerActionButton(bool is_enable, std::string tag) {

	if (is_enable) {

		if (tag == "MoveButton") {

			DrawStringEx(0, 500, -1, "MoveButton");
			seq_->change(&SceneBattle::PhaseActionMove);

		}
		
		if (tag == "CardButton") {

			DrawStringEx(0, 500, -1, "CardButton");
			seq_->change(&SceneBattle::PhaseActionCard);


		}
		
		if (tag == "ToolButton") {

			DrawStringEx(0, 500, -1, "ToolButton");
			seq_->change(&SceneBattle::PhaseActionTool);
		}
		
		if (tag == "TurnEndButton") {

			DrawStringEx(0, 500, -1, "TurnButton");
			seq_->change(&SceneBattle::PhaseActionTurnEnd);

		}

	}
	
}