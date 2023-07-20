#pragma once
#include <vector>
#include "gm_data_ally.h"
#include "gm_object_manager.h"

//memo
//AllyDataのインスタンスをロード、管理するクラス
//シングルトン

class AllyDataManager {
public:

	static AllyDataManager* GetInstance();
	static void Destory();

	void DebugLoadAllyData();
	void DebugLoadAllyTexture();

	bool is_loaded_ = false;

	AllyData* GetAllyDataAtID(int id) {
		AllyData* allydata = nullptr;

		for (auto ad : all_ally_data_) {
			if (ad->GetAllyDataID() == id) { allydata = ad; }

		}
		return allydata;
	}



private:

	AllyDataManager() {};
	~AllyDataManager() {};

	static AllyDataManager* instance_;

	ObjectManager& obj_mgr_ = ObjectManager::GetInstance();

	std::vector<AllyData*> all_ally_data_;


};