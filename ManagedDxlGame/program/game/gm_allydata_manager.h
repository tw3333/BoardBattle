#pragma once
#include <memory>
#include <vector>

#include "gm_data_ally.h"
#include "gm_object_manager.h"

//memo
//AllyDataのインスタンスをロード、管理するクラス
//シングルトン

class AllyDataManager {
public:

	static AllyDataManager& GetInstane() {
		static AllyDataManager instance;
		return instance;
	}

	//コピーコンストラクタ削除
	AllyDataManager(const AllyDataManager&) = delete;
	AllyDataManager& operator=(const AllyDataManager&) = delete;
	//ムーブコンストラクタ削除
	AllyDataManager(AllyDataManager&&) = delete;
	AllyDataManager& operator = (AllyDataManager&&) = delete;


	void DebugLoadAllyData();
	void DebugLoadAllyTexture();
	std::shared_ptr<AllyData> GetDeckEditAllyData();
	


	bool is_loaded_ = false;

	std::shared_ptr<AllyData> GetAllyDataAtID(int id) {
		std::shared_ptr<AllyData> allydata = nullptr;

		for (auto ad : all_ally_data_) {
			if (ad->GetAllyDataID() == id) { allydata = ad; }

		}
		return allydata;
	}





private:

	AllyDataManager() = default;
	~AllyDataManager() = default;

	ObjectManager& obj_mgr_ = ObjectManager::GetInstance();
	std::vector<std::shared_ptr<AllyData>> all_ally_data_;

	
};