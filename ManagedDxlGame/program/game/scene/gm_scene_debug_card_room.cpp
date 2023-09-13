#include "gm_scene_debug_card_room.h"

#include "../../dxlib_ext/dxlib_ext.h"
#include "../gm_data_card.h"

void SceneDebugCardRoom::Initialzie() {




}

void SceneDebugCardRoom::Update(float delta_time) {






}

void SceneDebugCardRoom::Render() {

	if (cmgr_.GetAllCardData().empty()) {

		DrawStringEx(0,0,-1,"CardData‚ª‹ó‚Å‚·");

	}


	for (int i = 0; i < cmgr_.GetAllCardData().size(); ++i) {

		DrawStringEx(0,0 + i* 20,-1,"CardID:%d PossAllyID:%d CardCost:%d Name:%s,Explanation:%s"
		,cmgr_.GetAllCardData()[i]->GetCardID(), cmgr_.GetAllCardData()[i]->GetPossAllyID(), cmgr_.GetAllCardData()[i]->GetCardCost()
		, cmgr_.GetAllCardData()[i]->GetCardName().c_str(), cmgr_.GetAllCardData()[i]->GetCardExplanation().c_str());

	}

	
	for (auto target : cmgr_.GetAllCardData()) {

		if (!target->GetCardTargetList().empty()) {

			DrawStringEx(1000, 0 + cnt * 20, -1, "Target‚ ‚èI");

			cnt++;
		}
		else
		{
			DrawStringEx(1000, 0 + cnt * 20, -1, "Target‚È‚µI");
			cnt++;
		}

	}

	cnt = 0;



}


