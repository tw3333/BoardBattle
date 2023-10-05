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

enum UINoticeGraph{
	RightClickToReturn,
	RightClickToReturnSelect,
	NoTarget,
	NotEnoughCost,
	GraphNum
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

	bool LoadUINoticeGraph();
	
	void LoadTexture();
	void DebugLoadTexture();

	std::vector<std::shared_ptr<dxe::Texture>>& GetBattleStateIconList() { return battle_state_icon_list_; }
	//std::vector<std::shared_ptr<dxe::Texture>>& GetUINoticeGraphList() { return ui_notice_graph_list_; }
	std::shared_ptr<dxe::Texture> GetUINoticeGraph(UINoticeGraph graph) { return ui_notice_graph_[graph]; }
	std::shared_ptr<dxe::Texture>& GetUINoticeNoTargetPanel() { return ui_notice_no_target_panel_; }

	int GetUINoticeGraphHandle(UINoticeGraph graph)& { return ui_notice_graph_handle_[graph]; }

private:

	TextureManager() = default;
	~TextureManager() = default;

	std::vector<std::shared_ptr<dxe::Texture>> battle_state_icon_list_;

	//std::vector<std::shared_ptr<dxe::Texture>> ui_notice_graph_list_;
	std::shared_ptr<dxe::Texture> ui_notice_no_target_panel_ = nullptr;
	std::shared_ptr<dxe::Texture> ui_notice_graph_[UINoticeGraph::GraphNum];

	int ui_notice_graph_handle_[UINoticeGraph::GraphNum];


};