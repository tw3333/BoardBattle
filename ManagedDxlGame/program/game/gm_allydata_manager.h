#pragma once
#include <vector>
#include "gm_data_ally.h"

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

	AllyData* getAllyDataAtID(int id) {
		AllyData* allydata = nullptr;

		for (auto ad : all_ally_data_) {
			if (ad->getAllyDataID() == id) { allydata = ad; }

		}
		return allydata;
	}

private:

	AllyDataManager() {};
	~AllyDataManager() {};

	static AllyDataManager* instance_;

	std::vector<AllyData*> all_ally_data_;


};