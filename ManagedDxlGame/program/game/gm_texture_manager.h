#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include <memory>


//memo
//シングルトン設計

enum BattleStateIcon{
	Blood,
	Poison,
	Snare,
	Stun
};


class TextureManager {
public:

	static TextureManager& GetInstance() {
		static TextureManager instance;
		return instance;
	}

	//コピーコンストラクタ削除
	TextureManager(const TextureManager&) = delete;
	TextureManager& operator=(const TextureManager&) = delete;

	//ムーブコンストラクタ削除
	TextureManager(TextureManager&&) = delete;
	TextureManager& operator = (TextureManager&&) = delete;


	Shared<dxe::Texture> selectphase_back1_;
	Shared<dxe::Texture> icon_3d_stairs_;
	Shared<dxe::Texture> icon_character_;
	Shared<dxe::Texture> icon_dungeon_gate_;
	Shared<dxe::Texture> panel_dungeon_;


	
	void LoadTexture();
	void DebugLoadTexture();

	std::vector<std::shared_ptr<dxe::Texture>>& GetBattleStateIconList() { return battle_state_icon_list_; }


private:

	TextureManager() = default;
	~TextureManager() = default;

	std::vector<std::shared_ptr<dxe::Texture>> battle_state_icon_list_;



};