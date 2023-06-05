#include "gm_allydata_manager.h"

AllyDataManager* AllyDataManager::instance_ = nullptr;

AllyDataManager* AllyDataManager::GetInstance() {

	if (!instance_) { instance_ = new AllyDataManager(); }
	return instance_;

}

void AllyDataManager::Destory() {

	if (instance_) {
		delete instance_;
		instance_ = nullptr;
	}

}

void AllyDataManager::DebugLoadAllyData() {

	all_ally_data_.emplace_back(new AllyData(1,"�~�A",30,3,3,30));
	all_ally_data_.emplace_back(new AllyData(2,"���[�Z���g",30,3,3,30));
	all_ally_data_.emplace_back(new AllyData(3,"�Y�Y",30,3,3,30));
	all_ally_data_.emplace_back(new AllyData(4,"���C��",40,3,3,25));

	is_loaded_ = true;
}

void AllyDataManager::DebugLoadAllyTexture() {

	all_ally_data_[0]->SetTextureFace1("graphics/unit/ally/c1_face1.png");
	all_ally_data_[0]->SetTextureFace2("graphics/unit/ally/c1_face2.png");
	all_ally_data_[0]->SetTextureBattle("graphics/unit/ally/c1_battle.png");
	all_ally_data_[0]->SetTextureStand("graphics/unit/ally/c1_stand.png");

	all_ally_data_[1]->SetTextureFace1("graphics/unit/ally/c2_face1.png");
	all_ally_data_[1]->SetTextureFace2("graphics/unit/ally/c2_face2.png");
	all_ally_data_[1]->SetTextureBattle("graphics/unit/ally/c2_battle.png");
	all_ally_data_[1]->SetTextureStand("graphics/unit/ally/c2_stand.png");

	all_ally_data_[2]->SetTextureFace1("graphics/unit/ally/c3_face1.png");
	all_ally_data_[2]->SetTextureFace2("graphics/unit/ally/c3_face2.png");
	all_ally_data_[2]->SetTextureBattle("graphics/unit/ally/c3_battle.png");
	all_ally_data_[2]->SetTextureStand("graphics/unit/ally/c3_stand.png");

	all_ally_data_[3]->SetTextureFace1("graphics/unit/ally/c4_face1.png");
	all_ally_data_[3]->SetTextureFace2("graphics/unit/ally/c4_face2.png");
	all_ally_data_[3]->SetTextureBattle("graphics/unit/ally/c4_battle.png");
	all_ally_data_[3]->SetTextureStand("graphics/unit/ally/c4_stand.png");

}



