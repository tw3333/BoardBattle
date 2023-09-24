#pragma once
#include "gm_scene_base.h"

#include "../gm_card_manager.h"
#include "../gm_allydata_manager.h"
#include "../gm_unit_ally.h"
#include "../gm_ui_card.h"


class SceneDeckEdit : public SceneBase {
public:

	SceneDeckEdit(){}
	~SceneDeckEdit(){}

	void Initialzie() override;
	void Update(float delta_time) override;
	void Render() override;

	//SceneDeckEdit‚Åg—p‚·‚éŠÖ”
	void SetDeckEditAlly();


private:

	std::shared_ptr<AllyData> deck_edit_ally_data_ = nullptr;	

	CardManager& card_mgr_ = CardManager::GetInstance();
	AllyDataManager& ally_data_mgr_ = AllyDataManager::GetInstane();


	std::vector<std::shared_ptr<UICard>> use_all_card_ui;
	std::vector<std::shared_ptr<UICard>> use_deck_card_ui;

};