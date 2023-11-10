#include "gm_ui_title.h"
#include "../dxlib_ext/dxlib_ext.h"

//‰ŠúScene‚Åg‚¤‚½‚ßŠÖ”‚Åƒ[ƒh
void UITitle::UITitleLoadGraph() {

	start_button_graph = LoadGraph("graphics/ui/scene_title/start.png");	
	start_button_graph_on = LoadGraph("graphics/ui/scene_title/start_d.png");
	
	quit_game_button_graph = LoadGraph("graphics/ui/scene_title/quit_game.png");
	quit_game_button_graph_on = LoadGraph("graphics/ui/scene_title/quit_game_d.png");

	back_graph_ = LoadGraph("graphics/background/scene_title_back.png");

	
}

void UITitle::UITitleLoadSound()
{
	se_math_cursor_title_button_ = LoadSoundMem("sound/se/ui_se/se_math_cursor_title_button.mp3");
	se_push_title_button_ = LoadSoundMem("sound/se/ui_se/se_push_title_button.mp3");


}

void UITitle::Update(float delta_time) {


	for (auto &button : title_buttons_) {

		button->Update(delta_time);

		if (button == title_buttons_[TitleButton::START_BUTTON]) {
			
			if (button->GetIsOverMousePointer()) {
				
				button->setGraphHandle(start_button_graph_on);
				if (!button->GetIsMouseHited()) {
					PlaySoundMem(se_math_cursor_title_button_, DX_PLAYTYPE_BACK, true);
					button->SetIsMouseHited(true);
				}
				//Push
				if (tnl::Input::IsMouseTrigger(eMouseTrigger::IN_LEFT)) {
					is_push_start_button_ = true;
				}

			} else {
				button->setGraphHandle(start_button_graph);
				button->SetIsMouseHited(false);
			}


		}
		
		if (button == title_buttons_[TitleButton::QUIT_GAME_BUTTON]) {
			
			if (button->GetIsOverMousePointer()) {
				
				button->setGraphHandle(quit_game_button_graph_on);
				if (!button->GetIsMouseHited()) {
					PlaySoundMem(se_math_cursor_title_button_, DX_PLAYTYPE_BACK, true);
					button->SetIsMouseHited(true);
				}
				//Push
				if (tnl::Input::IsMouseTrigger(eMouseTrigger::IN_LEFT)) {
					is_push_quit_game_button_ = true;
				}

			}
			else  {
				button->setGraphHandle(quit_game_button_graph);
				button->SetIsMouseHited(false);

			}
		}

	}



	
}

void UITitle::Render() {

	DrawGraph(0, 0, back_graph_, false);

	for (auto button : title_buttons_) {
		button->Render();
	}


}
