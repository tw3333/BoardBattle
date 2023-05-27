#pragma once
#include "../dxlib_ext/dxlib_ext.h"

//memo
//シングルトン設計

class TextureManager {
public:

	static TextureManager* GetInstance();
	static void Destory();



	Shared<dxe::Texture> selectphase_back1_;
	Shared<dxe::Texture> icon_3d_stairs_;
	Shared<dxe::Texture> icon_character_;
	Shared<dxe::Texture> icon_dungeon_gate_;
	Shared<dxe::Texture> panel_dungeon_;


	
	void LoadTexture();

private:

	TextureManager() {};
	~TextureManager() {};

	static TextureManager* instance_;

	



};