#include "gm_enemydata_manager.h"

#include "gm_enemy_move.h"
#include "gm_enemy_act.h"
#include "gm_slime_move.h"
#include "gm_slime_act.h"

#include <vector>
#include <memory>
#include <fstream>
#include <sstream>


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

	//all_enemy_data_.emplace_back(new EnemyData(1,"�X���C��",30,1,1,1,1));
	//all_enemy_data_.emplace_back(new EnemyData(2, "�~�C��", 30, 1,1, 1,1));
	//all_enemy_data_.emplace_back(new EnemyData(3, "�y��", 30, 1, 1,1,1));
	//all_enemy_data_.emplace_back(new EnemyData(4, "�N���E", 30, 1, 1, 1,1));
	//all_enemy_data_.emplace_back(new EnemyData(5, "�}�W�|��", 30, 1, 1,1,1));
	//all_enemy_data_.emplace_back(new EnemyData(6, "�L�����h��", 30, 1, 1,1,1));
	//all_enemy_data_.emplace_back(new EnemyData(7, "�񕜃���", 30, 1, 1,1,1));
	//all_enemy_data_.emplace_back(new EnemyData(8, "�U������", 30, 1, 1,1,1));
	//all_enemy_data_.emplace_back(new EnemyData(9, "�S�[����", 30, 1, 1,1,1));
	//all_enemy_data_.emplace_back(new EnemyData(10, "���U�[�h", 30, 1, 1,1,1));
	//all_enemy_data_.emplace_back(new EnemyData(11, "�h���S��", 30, 1, 1, 1,1));
	//
	////
	//all_enemy_data_[0]->SetEnemyMove(std::make_shared<SlimeMove>());
	//all_enemy_data_[0]->SetEnemyAct(std::make_shared<SlimeAct>());

}

void EnemyDataManager::DebugLoadenemyTexture() {


	//all_enemy_data_[0]->SetTextureBattle("graphics/unit/enemy/adoption/test_slime_battle.png");
	//all_enemy_data_[1]->SetTextureBattle("graphics/unit/enemy/adoption/mummy_battle.png");
	//all_enemy_data_[2]->SetTextureBattle("graphics/unit/enemy/adoption/pen_battle.png");
	//all_enemy_data_[3]->SetTextureBattle("graphics/unit/enemy/adoption/magipon_battle.png");
	//all_enemy_data_[4]->SetTextureBattle("graphics/unit/enemy/adoption/candle_battle.png");
	//all_enemy_data_[5]->SetTextureBattle("graphics/unit/enemy/adoption/heallulu_battle.png");
	//all_enemy_data_[6]->SetTextureBattle("graphics/unit/enemy/adoption/attacklulu_battle.png");
	//all_enemy_data_[7]->SetTextureBattle("graphics/unit/enemy/adoption/golem_battle.png");
	//all_enemy_data_[8]->SetTextureBattle("graphics/unit/enemy/adoption/lizard_battle.png");
	//all_enemy_data_[9]->SetTextureBattle("graphics/unit/enemy/adoption/doragon_battle.png");

	//all_enemy_data_[0]->SetTextureFace("graphics/unit/enemy/adoption/test_slime_face.png");
	//all_enemy_data_[1]->SetTextureFace("graphics/unit/enemy/adoption/mummy_face.png");
	//all_enemy_data_[2]->SetTextureFace("graphics/unit/enemy/adoption/pen_face.png");
	//all_enemy_data_[3]->SetTextureFace("graphics/unit/enemy/adoption/magipon_face.png");
	//all_enemy_data_[4]->SetTextureFace("graphics/unit/enemy/adoption/candle_face.png");
	//all_enemy_data_[5]->SetTextureFace("graphics/unit/enemy/adoption/heallulu_face.png");
	//all_enemy_data_[6]->SetTextureFace("graphics/unit/enemy/adoption/attacklulu_face.png");
	//all_enemy_data_[7]->SetTextureFace("graphics/unit/enemy/adoption/golem_face.png");
	//all_enemy_data_[8]->SetTextureFace("graphics/unit/enemy/adoption/lizard_face.png");
	//all_enemy_data_[9]->SetTextureFace("graphics/unit/enemy/adoption/doragon_face.png");

}



bool EnemyDataManager::LoadEnemyDataFromCSV(const std::string& filepath) {

	if (!enemy_data_.empty()) {
			return false;
	}

	if (enemy_data_.empty()) {

		std::ifstream file(filepath);

		if (!file.is_open()) {
			return false; 
		}

		std::string line;
		getline(file, line);  //�w�b�_��΂�

		while (getline(file, line)) {
			std::stringstream ss(line);
			std::string item;

			int enemy_id;
			std::string name;
			int hp;
			int power;
			int speed;
			int move_cost;
			int action_cost;
			std::string face_texture_path;
			std::string battle_texture_path;

			getline(ss, item, ',');
			enemy_id = std::stoi(item);

			getline(ss, name, ',');

			getline(ss, item, ',');
			hp = std::stoi(item);

			getline(ss, item, ',');
			power = std::stoi(item);

			getline(ss, item, ',');
			speed = std::stoi(item);

			getline(ss, item, ',');
			move_cost = std::stoi(item);

			getline(ss, item, ',');
			action_cost = std::stoi(item);

			getline(ss, face_texture_path, ',');
			getline(ss, battle_texture_path, ',');

			//EnemyData�쐬
			auto enemy = std::make_shared<EnemyData>(enemy_id, name, hp, power, speed, move_cost, action_cost, face_texture_path, battle_texture_path);
			//EnemyAct��EnemyMove�����蓖��
			AssignEnemyMoveToEnemyData(enemy);
			AssignEnemyActToEnemyData(enemy);
			//�i�[
			enemy_data_.push_back(enemy);
		}

		return true;
	}

}

//�n����EnemyData�ɑΉ�����EnemyMove�����蓖�Ă�
void EnemyDataManager::AssignEnemyActToEnemyData(std::shared_ptr<EnemyData> enemy_data) {

	if (enemy_data->GetEnemyDataID() == 0) {
		enemy_data->SetEnemyAct(std::make_shared<SlimeAct>());
	}
	else if (enemy_data->GetEnemyDataID() == 1) {
		enemy_data->SetEnemyAct(std::make_shared<SlimeAct>());
	}

}

void EnemyDataManager::AssignEnemyMoveToEnemyData(std::shared_ptr<EnemyData> enemy_data) {

	if (enemy_data->GetEnemyDataID() == 0) {
		enemy_data->SetEnemyMove(std::make_shared<SlimeMove>());
	}
	else if (enemy_data->GetEnemyDataID() == 1) {
		enemy_data->SetEnemyMove(std::make_shared<SlimeMove>());
	}



}


//�����ɓn����ID��(Board��̍��W�����͂���Ă��Ȃ�)UnitEnemy���쐬����
UnitEnemy* EnemyDataManager::CreateUnitEnemy(int enemy_id) {

	UnitEnemy* ret = nullptr;

	for (auto &enemydata : enemy_data_) {
		if (enemydata->GetEnemyDataID() == enemy_id) {
			ret = new UnitEnemy(enemydata);

			if (ret) {
				ret->SetUnitObj(ObjEnemy::CreateObj(enemydata));
			}

		}
	}


	return ret;
}
