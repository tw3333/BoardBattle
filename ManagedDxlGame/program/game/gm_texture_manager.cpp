#include "gm_texture_manager.h"



bool TextureManager::LoadUINoticeGraph() {

	//ui_notice_graph_list_.resize(UINoticeGraph::GraphNum);

	ui_notice_no_target_panel_->CreateFromFile("graphics/ui/notice/no_target_panel.png");

	ui_notice_graph_[UINoticeGraph::RightClickToReturn]->CreateFromFile("graphics/ui/notice/right_click_to_return_panel.png");
	ui_notice_graph_[UINoticeGraph::RightClickToReturnSelect]->CreateFromFile("graphics/ui/notice/right_click_to_return_select.png");
	ui_notice_graph_handle_[UINoticeGraph::NoTarget] = LoadGraph("graphics/ui/notice/no_target_panel.png");
	ui_notice_graph_handle_[UINoticeGraph::NotEnoughCost] = LoadGraph("graphics/ui/notice/not_enough_cost_panel.png");




	return true;
}

bool TextureManager::LoadUIPlayerActionButtonsGraph() {

	ui_player_action_buttons_graph_handle_[UIPlayerActionButtonsGraph::MoveButton] = LoadGraph("graphics/ui/player_action_buttons/move_button.png");
	ui_player_action_buttons_graph_handle_[UIPlayerActionButtonsGraph::CardButton] = LoadGraph("graphics/ui/player_action_buttons/card_button.png");
	ui_player_action_buttons_graph_handle_[UIPlayerActionButtonsGraph::TurnEndButton] = LoadGraph("graphics/ui/player_action_buttons/turn_end_button.png");
	ui_player_action_buttons_graph_handle_[UIPlayerActionButtonsGraph::InitDrawFont] = LoadGraph("graphics/ui/player_action_buttons/init_card_draw_flame.png");
	ui_player_action_buttons_graph_handle_[UIPlayerActionButtonsGraph::DrawFont] = LoadGraph("graphics/ui/player_action_buttons/card_draw_flame.png");
	ui_player_action_buttons_graph_handle_[UIPlayerActionButtonsGraph::CardFont] = LoadGraph("graphics/ui/player_action_buttons/card_flame.png");
	ui_player_action_buttons_graph_handle_[UIPlayerActionButtonsGraph::SelectFrame] = LoadGraph("graphics/ui/player_action_buttons/select_frame.png");
	ui_player_action_buttons_graph_handle_[UIPlayerActionButtonsGraph::DecisionFrame] = LoadGraph("graphics/ui/player_action_buttons/decision_frame.png");

	return true;
}

void TextureManager::LoadTexture() {

	selectphase_back1_ = dxe::Texture::CreateFromFile("graphics/selectphase_back1.jpg");
	icon_3d_stairs_ = dxe::Texture::CreateFromFile("graphics/3d-stairs.png");
	icon_character_ = dxe::Texture::CreateFromFile("graphics/icon_character.png");
	icon_dungeon_gate_ = dxe::Texture::CreateFromFile("graphics/dungeon-gateA.png");
	panel_dungeon_ = dxe::Texture::CreateFromFile("graphics/ui/panel_dungeon.png");



}

void TextureManager::DebugLoadTexture() {

	//battle_state_icon_list_.push_back(std::make_shared<dxe::Texture>(dxe::Texture::CreateFromFile("graphics/ui/battlestate_icon/icon_blood.png")));
	//battle_state_icon_list_.push_back(std::make_shared <dxe::Texture>(dxe::Texture::CreateFromFile("graphics/ui/battlestate_icon/icon_poison.png")));
	//battle_state_icon_list_.push_back(std::make_shared <dxe::Texture>(dxe::Texture::CreateFromFile("graphics/ui/battlestate_icon/icon_snare.png")));
	//battle_state_icon_list_.push_back(std::make_shared<dxe::Texture>(dxe::Texture::CreateFromFile("graphics/ui/battlestate_icon/icon_stun.png")));

}
