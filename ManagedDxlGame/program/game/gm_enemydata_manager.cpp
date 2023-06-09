#include "gm_enemydata_manager.h"

EnemyDataManager* EnemyDataManager::instance_ = nullptr;

EnemyDataManager* EnemyDataManager::GetInstance() {

	if (!instance_) { instance_ = new EnemyDataManager(); }
	return instance_;
}

void EnemyDataManager::Destroy() {

	if(instance_) {
		delete instance_;
		instance_ = nullptr;
		
	}

}

void EnemyDataManager::DebugLoadEnemyData() {

	all_enemy_data_.emplace_back(new EnemyData(1,"ƒXƒ‰ƒCƒ€",30,30,1));
	all_enemy_data_.emplace_back(new EnemyData(2, "a", 30, 30, 1));
	all_enemy_data_.emplace_back(new EnemyData(3, "a", 30, 30, 1));
	all_enemy_data_.emplace_back(new EnemyData(4, "a", 30, 30, 1));
	all_enemy_data_.emplace_back(new EnemyData(5, "a", 30, 30, 1));
	all_enemy_data_.emplace_back(new EnemyData(6, "a", 30, 30, 1));
	all_enemy_data_.emplace_back(new EnemyData(7, "a", 30, 30, 1));
	all_enemy_data_.emplace_back(new EnemyData(8, "a", 30, 30, 1));
	all_enemy_data_.emplace_back(new EnemyData(9, "a", 30, 30, 1));


}

void EnemyDataManager::DebugLoadenemyTexture() {








}
