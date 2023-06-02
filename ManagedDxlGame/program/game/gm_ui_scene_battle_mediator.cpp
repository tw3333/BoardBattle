#include "gm_ui_scene_battle_mediator.h"
#include "scene/gm_scene_battle.h"


void UISceneBattleMediator::Notify(UIComponent* sender, std::string tag) {

	if (tag == "MoveButton") {

		DrawStringEx(0,500,-1,"MoveButton");


	}
	if (tag == "CardButton") {

		DrawStringEx(0, 500, -1, "CardButton");
		seq_->change(&SceneBattle::PhaseCard);


	}
	if (tag == "ToolButton") {

		DrawStringEx(0, 500, -1, "ToolButton");

	}
	if (tag == "TurnEndButton") {

		DrawStringEx(0, 500, -1, "TurnButton");

	}



}