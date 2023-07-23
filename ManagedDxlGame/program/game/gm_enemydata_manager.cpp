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

	all_enemy_data_.emplace_back(new EnemyData(1,"スライム",30,1,1,1));
	all_enemy_data_.emplace_back(new EnemyData(2, "ミイラ", 30, 1, 1,1));
	all_enemy_data_.emplace_back(new EnemyData(3, "ペン", 30, 1, 1,1));
	all_enemy_data_.emplace_back(new EnemyData(4, "クロウ", 30, 1, 1, 1));
	all_enemy_data_.emplace_back(new EnemyData(5, "マジポン", 30, 1, 1,1));
	all_enemy_data_.emplace_back(new EnemyData(6, "キャンドル", 30, 1, 1,1));
	all_enemy_data_.emplace_back(new EnemyData(7, "回復ルル", 30, 1, 1,1));
	all_enemy_data_.emplace_back(new EnemyData(8, "攻撃ルル", 30, 1, 1,1));
	all_enemy_data_.emplace_back(new EnemyData(9, "ゴーレム", 30, 1, 1,1));
	all_enemy_data_.emplace_back(new EnemyData(10, "リザード", 30, 1, 1,1));
	all_enemy_data_.emplace_back(new EnemyData(11, "ドラゴン", 30, 1, 1, 1));

	for (auto aed : all_enemy_data_) {

		aed->SetObj(obj_mgr_.GetObjEnemyAtID(aed->GetEnemyDataID()));


	}


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

	all_enemy_data_[0]->SetTextureFace("graphics/unit/enemy/adoption/slime_face.png");
	all_enemy_data_[1]->SetTextureFace("graphics/unit/enemy/adoption/mummy_face.png");
	all_enemy_data_[2]->SetTextureFace("graphics/unit/enemy/adoption/pen_face.png");
	all_enemy_data_[3]->SetTextureFace("graphics/unit/enemy/adoption/magipon_face.png");
	all_enemy_data_[4]->SetTextureFace("graphics/unit/enemy/adoption/candle_face.png");
	all_enemy_data_[5]->SetTextureFace("graphics/unit/enemy/adoption/heallulu_face.png");
	all_enemy_data_[6]->SetTextureFace("graphics/unit/enemy/adoption/attacklulu_face.png");
	all_enemy_data_[7]->SetTextureFace("graphics/unit/enemy/adoption/golem_face.png");
	all_enemy_data_[8]->SetTextureFace("graphics/unit/enemy/adoption/lizard_face.png");
	all_enemy_data_[9]->SetTextureFace("graphics/unit/enemy/adoption/doragon_face.png");

}
