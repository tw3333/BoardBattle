#pragma once
#include <string>
#include <vector>
#include <memory>


#include "gm_data_sound.h"



class SoundManager {
public:

	static SoundManager& GetInstance() {
		static SoundManager instance;
		return instance;
	}

	//コピーコンストラクタ削除
	SoundManager(const SoundManager&) = delete;
	SoundManager& operator=(const SoundManager&) = delete;

	//ムーブコンストラクタ削除
	SoundManager(SoundManager&&) = delete;
	SoundManager& operator=(SoundManager&&) = delete;


	void CreateBattleBGMList();
	void CreateCardSEList();
	void CreateSystemSEList();

	void PlayBattleBGM(int id);
	void PlayCardSE(int id);
	void PlaySystemSE(int id);


private:

	SoundManager() = default;
	~SoundManager() = default;


//	std::vector <std::shared_ptr<BGMData>> battle_bgm_list;
	std::vector<std::shared_ptr<SoundData>> battle_bgm_list_;
	std::vector<std::shared_ptr<SoundData>> card_se_list_;
	std::vector<std::shared_ptr<SoundData>> ui_se_list_;
	std::vector<std::shared_ptr<SoundData>> system_se_list_;

};