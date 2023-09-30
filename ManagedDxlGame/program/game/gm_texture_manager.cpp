#include "gm_texture_manager.h"



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
