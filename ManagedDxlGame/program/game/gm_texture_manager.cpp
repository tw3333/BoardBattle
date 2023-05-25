#include "gm_texture_manager.h"

TextureManager* TextureManager::instance_ = nullptr;

TextureManager* TextureManager::GetInstance() {

	if (!instance_) { instance_ = new TextureManager(); }
	return instance_;
}

void TextureManager::Destory() {

	if (instance_) {

		delete instance_;
		instance_ = nullptr;
	}

}

void TextureManager::LoadTexture() {

	selectphase_back1_ = dxe::Texture::CreateFromFile("graphics/selectphase_back1.jpg");
	icon_3d_stairs_ = dxe::Texture::CreateFromFile("graphics/3d-stairs.png");
	icon_character_ = dxe::Texture::CreateFromFile("graphics/icon_character.png");
	icon_dungeon_gate_ = dxe::Texture::CreateFromFile("graphics/dungeon-gateA.png");



}
