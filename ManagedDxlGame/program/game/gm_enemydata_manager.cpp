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

	all_enemy_data_.emplace_back(new EnemyData(1,"�X���C��",30,30,1,1));
	all_enemy_data_.emplace_back(new EnemyData(2, "�~�C��", 30, 30, 1,1));
	all_enemy_data_.emplace_back(new EnemyData(3, "�y��", 30, 30, 1,1));
	all_enemy_data_.emplace_back(new EnemyData(4, "�}�W�|��", 30, 30, 1,1));
	all_enemy_data_.emplace_back(new EnemyData(5, "�L�����h��", 30, 30, 1,1));
	all_enemy_data_.emplace_back(new EnemyData(6, "�񕜃���", 30, 30, 1,1));
	all_enemy_data_.emplace_back(new EnemyData(7, "�U������", 30, 30, 1,1));
	all_enemy_data_.emplace_back(new EnemyData(8, "�S�[����", 30, 30, 1,1));
	all_enemy_data_.emplace_back(new EnemyData(9, "���U�[�h", 30, 30, 1,1));
	all_enemy_data_.emplace_back(new EnemyData(10, "�h���S��", 30, 30, 1, 1));


	//all_enemy_data_.emplace_back(new EnemyData(10, "�h���S��", 30, 30, 1, 1));
	//all_enemy_data_.emplace_back(new EnemyData(11, "�N���E", 30, 30, 1, 1));
	//all_enemy_data_.emplace_back(new EnemyData(12, "�L�����h��", 30, 30, 1, 1));
	//all_enemy_data_.emplace_back(new EnemyData(13, "�U������", 30, 30, 1, 1));
	//all_enemy_data_.emplace_back(new EnemyData(14, "�S�[����", 30, 30, 1, 1));
	//all_enemy_data_.emplace_back(new EnemyData(15, "�S�[����", 30, 30, 1, 1));
	//all_enemy_data_.emplace_back(new EnemyData(16, "�S�[����", 30, 30, 1, 1));


}

void EnemyDataManager::DebugLoadenemyTexture() {


	all_enemy_data_[0]->SetTextureBattle("graphics/unit/enemy/adoption/slime_battle.png");
	all_enemy_data_[1]->SetTextureBattle("graphics/unit/enemy/adoption/mummy_battle.png");
	all_enemy_data_[2]->SetTextureBattle("graphics/unit/enemy/adoption/pen_battle.png");
	all_enemy_data_[3]->SetTextureBattle("graphics/unit/enemy/adoption/magipon_battle.png");
	all_enemy_data_[4]->SetTextureBattle("graphics/unit/enemy/adoption/candle_battle.png");
	all_enemy_data_[5]->SetTextureBattle("graphics/unit/enemy/adoption/heallulu_battle.png");
	all_enemy_data_[6]->SetTextureBattle("graphics/unit/enemy/adoption/attacklulu_battle.png");
	all_enemy_data_[7]->SetTextureBattle("graphics/unit/enemy/adoption/golem_battle.png");
	all_enemy_data_[8]->SetTextureBattle("graphics/unit/enemy/adoption/lizard_battle.png");
	all_enemy_data_[9]->SetTextureBattle("graphics/unit/enemy/adoption/doragon_battle.png");


}