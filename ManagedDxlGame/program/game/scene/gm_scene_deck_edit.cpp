#include "gm_scene_deck_edit.h"

#include "../../dxlib_ext/dxlib_ext.h"
#include "../gm_data_card.h"
#include "../gm_card.h"


void SceneDeckEdit::Initialzie() {





}

void SceneDeckEdit::Update(float delta_time) {



}

void SceneDeckEdit::Render() {

	for (int i = 0; i < cmgr_.GetC1Deck().size(); ++i) {

		DrawStringEx(0, 0 + i * 20, -1, "%s", cmgr_.GetC1Deck()[i]->GetCardData()->GetCardName());

	}

}
