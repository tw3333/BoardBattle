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

	all_ally_data_.emplace_back(new AllyData(1));
	all_ally_data_.emplace_back(new AllyData(2));
	all_ally_data_.emplace_back(new AllyData(3));
	all_ally_data_.emplace_back(new AllyData(4));

	all_ally_data_[0]->setImgBattlePath("graphics/unit/ally/c1_board_img.png");


	is_loaded_ = true;
}