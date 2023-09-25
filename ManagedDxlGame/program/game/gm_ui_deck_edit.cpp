#include "gm_ui_deck_edit.h"

#include "gm_scene_manager.h"
#include "../game/scene/gm_scene_selectphase.h"

void UIDeckEdit::Init() {

	back_button_->SetSize(back_button_w_, back_button_h_);
	back_button_->SetPos(back_button_upper_left_x_, back_button_upper_left_y_);




}

void UIDeckEdit::Update(float delta_time) {

	tnl::Vector3 msv = tnl::Input::GetMousePosition();

	back_button_->Update(delta_time);
	

	BackSceneSelectPhase(back_button_->IsClicked(msv.x,msv.y));
}

void UIDeckEdit::Render() {

	//‰º’n
	//back
	DrawBox(0,0,DXE_WINDOW_WIDTH,DXE_WINDOW_WIDTH,back_color_,true);
	//leftbox
	DrawBox(leftbox_upper_left_x_, leftbox_upper_left_y_, leftbox_lower_right_x_, leftbox_lower_right_y_,leftbox_color,true);
	//middlebox
	DrawBox(middlebox_upper_left_x_,middlebox_upper_left_y_,middlebox_lower_right_x_,middlebox_lower_right_y_,middlebox_color,true);
	//rightbox
	DrawBox(rightbox_upper_left_x_, rightbox_upper_left_y_, rightbox_lower_right_x_, rightbox_lower_right_y_, rightbox_color, true);
	//allyfacebox
	RenderAllyFaceBox(deck_edit_ally_data_);
	
	back_button_->Render();


	RenderChoiceCardUI(choice_card_);


}

void UIDeckEdit::RenderChoiceCardUI(std::shared_ptr<Card> choice_card) {

	if (choice_card) {



	}

}

void UIDeckEdit::RenderAllyFaceBox(std::shared_ptr<AllyData> deck_edit_ally_data) {

	//‰º’n
	DrawBox(allyfacebox_upper_left_x_, allyfacebox_upper_left_y_, allyfacebox_lower_right_x_, allyfacebox_lower_right_y_, -1, true);


	if (deck_edit_ally_data) {

		//facegraph
		DrawExtendGraph(allyfacebox_upper_left_x_, allyfacebox_upper_left_y_, allyfacebox_lower_right_x_, allyfacebox_lower_right_y_,deck_edit_ally_data->GetTextureFace2()->getDxLibGraphHandle(), true);

	}


}

void UIDeckEdit::BackSceneSelectPhase(bool flag) {

	if (flag) {

		SceneManager* scene_mgr = SceneManager::GetInstance();
		scene_mgr->ChengeScene(new SceneSelectPhase());

	}

}
