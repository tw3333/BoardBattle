#include "gm_scene_deck_edit.h"

#include "../../dxlib_ext/dxlib_ext.h"
#include "../gm_data_card.h"
#include "../gm_card.h"


void SceneDeckEdit::Initialzie() {
	
	deck_edit_ally_data_ = ally_data_mgr_.GetDeckEditAllyData();

	ui_deck_edit_ = std::make_shared<UIDeckEdit>();
	ui_deck_edit_->SetDeckEditAlly(ally_data_mgr_.GetDeckEditAllyData());
	ui_deck_edit_->Init();




}

void SceneDeckEdit::Update(float delta_time) {

	ui_deck_edit_->Update(delta_time);


}

void SceneDeckEdit::Render() {

	ui_deck_edit_->Render();


}


//==============================================================================
//SceneDeckEditÇ≈égópÇ∑ÇÈä÷êî

void SceneDeckEdit::SetDeckEditAlly() {







}

