#pragma once
#include <vector>
#include "gm_data_enemy.h"
#include "gm_object_manager.h"
#include "gm_unit_enemy.h"
#include "gm_enums_enemy.h"
#include "gm_object_enemy.h"


class EnemyDataManager {
public:

	static EnemyDataManager* GetInstance();
	static void Destroy();



	void DebugLoadEnemyData();
	void DebugLoadenemyTexture();

	bool LoadEnemyDataFromCSV(const std::string& filepath);

	void AssignEnemyActToEnemyData(std::shared_ptr<EnemyData> enemy_data);
	void AssignEnemyMoveToEnemyData(std::shared_ptr<EnemyData> enemy_data);


	UnitEnemy* CreateUnitEnemy(int enemy_id);


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

	std::vector<std::shared_ptr<EnemyData>> enemy_data_;

};