#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include "gm_ui_graph_enums.h"
#include "gm_enums_graph.h"
#include <memory>


//memo
//シングルトン設計


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
	bool LoadUIPlayerActionButtonsGraph();
	bool LoadBackgroundGraph();
	
	void LoadTexture();
	void DebugLoadTexture();

	std::vector<std::shared_ptr<dxe::Texture>>& GetBattleStateIconList() { return battle_state_icon_list_; }
	//std::vector<std::shared_ptr<dxe::Texture>>& GetUINoticeGraphList() { return ui_notice_graph_list_; }
	std::shared_ptr<dxe::Texture> GetUINoticeGraph(UINoticeGraph graph) { return ui_notice_graph_[graph]; }
	std::shared_ptr<dxe::Texture>& GetUINoticeNoTargetPanel() { return ui_notice_no_target_panel_; }

	int GetUINoticeGraphHandle(UINoticeGraph graph) { return ui_notice_graph_handle_[graph]; }
	int GetUIPlayerActionButtonsGraphHandle(UIPlayerActionButtonsGraph graph) { return ui_player_action_buttons_graph_handle_[graph]; }
	int GetBackgroundGraphHandle(BackGroundGraph graph) { return background_graph_handle_[graph]; }


private:

	TextureManager() = default;
	~TextureManager() = default;

	std::vector<std::shared_ptr<dxe::Texture>> battle_state_icon_list_;

	//std::vector<std::shared_ptr<dxe::Texture>> ui_notice_graph_list_;
	std::shared_ptr<dxe::Texture> ui_notice_no_target_panel_ = nullptr;
	std::shared_ptr<dxe::Texture> ui_notice_graph_[UINoticeGraph::UINoticeGraphNum];

	int ui_notice_graph_handle_[UINoticeGraph::UINoticeGraphNum] = {0};
	int ui_player_action_buttons_graph_handle_[UIPlayerActionButtonsGraph::UIPlayerActionButtonsGraphNum] = {0};
	int background_graph_handle_[BackGroundGraph::BackGroundGraphNum] = {0};

};