#pragma once
#include <vector>
#include "gm_data_ally.h"

//memo
//AllyData�̃C���X�^���X�����[�h�A�Ǘ�����N���X
//�V���O���g��

class AllyDataManager {
public:

	static AllyDataManager* GetInstance();
	static void Destory();

	void DebugLoadAllyData();

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