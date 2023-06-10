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

	all_enemy_data_.emplace_back(new EnemyData(1,"スライム",30,30,1,1));
	all_enemy_data_.emplace_back(new EnemyData(2, "ミイラ", 30, 30, 1,1));
	all_enemy_data_.emplace_back(new EnemyData(3, "ペン", 30, 30, 1,1));
	all_enemy_data_.emplace_back(new EnemyData(4, "マジポン", 30, 30, 1,1));
	all_enemy_data_.emplace_back(new EnemyData(5, "キャンドル", 30, 30, 1,1));
	all_enemy_data_.emplace_back(new EnemyData(6, "回復ルル", 30, 30, 1,1));
	all_enemy_data_.emplace_back(new EnemyData(7, "攻撃ルル", 30, 30, 1,1));
	all_enemy_data_.emplace_back(new EnemyData(8, "ゴーレム", 30, 30, 1,1));
	all_enemy_data_.emplace_back(new EnemyData(9, "リザード", 30, 30, 1,1));
	all_enemy_data_.emplace_back(new EnemyData(10, "ドラゴン", 30, 30, 1, 1));


	//all_enemy_data_.emplace_back(new EnemyData(10, "ドラゴン", 30, 30, 1, 1));
	//all_enemy_data_.emplace_back(new EnemyData(11, "クロウ", 30, 30, 1, 1));
	//all_enemy_data_.emplace_back(new EnemyData(12, "キャンドル", 30, 30, 1, 1));
	//all_enemy_data_.emplace_back(new EnemyData(13, "攻撃ルル", 30, 30, 1, 1));
	//all_enemy_data_.emplace_back(new EnemyData(14, "ゴーレム", 30, 30, 1, 1));
	//all_enemy_data_.emplace_back(new EnemyData(15, "ゴーレム", 30, 30, 1, 1));
	//all_enemy_data_.emplace_back(new EnemyData(16, "ゴーレム", 30, 30, 1, 1));


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
