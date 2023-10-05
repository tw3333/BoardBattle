#include "gm_texture_manager.h"



bool TextureManager::LoadUINoticeGraph() {

	//ui_notice_graph_list_.resize(UINoticeGraph::GraphNum);

	ui_notice_no_target_panel_->CreateFromFile("graphics/ui/notice/no_target_panel.png");

	ui_notice_graph_handle_[UINoticeGraph::NoTarget] = LoadGraph("graphics/ui/notice/no_target_panel.png");

	ui_notice_graph_[UINoticeGraph::NoTarget]->CreateFromFile("graphics/ui/move.png");
	ui_notice_graph_[UINoticeGraph::NotEnoughCost]->CreateFromFile("graphics/ui/notice/not_enough_cost_panel.png");
	ui_notice_graph_[UINoticeGraph::RightClickToReturn]->CreateFromFile("graphics/ui/notice/right_click_to_return_panel.png");
	ui_notice_graph_[UINoticeGraph::RightClickToReturnSelect]->CreateFromFile("graphics/ui/notice/right_click_to_return_select.png");




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
