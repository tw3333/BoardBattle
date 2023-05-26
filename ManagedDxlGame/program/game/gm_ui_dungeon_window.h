#pragma once
#include "gm_ui_component.h"
#include "gm_ui_panel.h"
#include "gm_ui_button.h"
#include "gm_ui_mediator.h"

#include "gm_texture_manager.h"
#include <vector>

class DungeonWindow : public UIComponent {
public:

	//arg1,2...ï`é Ç∑ÇÈç∂í∏ì_ç¿ïW
	//arg3,4...Window(Square)ÇÃëÂÇ´Ç≥(Ç±ÇÍÇå≥Ç…äeComponentÇÃäÓèÄÇ…Ç»ÇÈ)
	DungeonWindow(int x, int y,int width, int height) {
		window_posx_ = x;
		window_posy_ = y;
		window_w_ = width;
		window_h_ = height;
	}

	~DungeonWindow(){}


	void Update(float delta_time) override;
	void Render() override;

	void Create();

	//
	Shared<UIPanel>& GetWindow() { return window_; }
	std::vector<Shared<UIComponent>> GetComponents() { return dungeon_window_components_; }

private:

	int window_posx_;
	int window_posy_;
	int window_w_;
	int window_h_;


	int button_w_ = (DXE_WINDOW_WIDTH / 10) + (DXE_WINDOW_WIDTH) /10 *0.5;
	int button_h_ = DXE_WINDOW_HEIGHT / 10;


	//Components
	Shared<UIPanel> window_;
	Shared<UIPanel> window_dungeon_tab_;

	Shared<UIButton> switch_dungeon_tab_;
	Shared<UIButton> switch_partyedit_tab_;

	std::vector<Shared<UIComponent>> dungeon_window_components_;

	TextureManager* tmgr_ = TextureManager::GetInstance();

};