#pragma once
#include <vector>
#include "gm_data_enemy.h"
#include "gm_object_manager.h"



class EnemyDataManager {
public:

	static EnemyDataManager* GetInstance();
	static void Destroy();



	void DebugLoadEnemyData();
	void DebugLoadenemyTexture();


	EnemyData* GetEnemyDataAtID(int id) {
		for (auto ed : all_enemy_data_) {
			if (id == ed->GetEnemyDataID()) { return ed; }
		}
	}

private:

	EnemyDataManager(){}
	~EnemyDataManager(){}

	static EnemyDataManager* instance_;

	ObjectManager& obj_mgr_ = ObjectManager::GetInstance();


	std::vector<EnemyData*> all_enemy_data_;


};