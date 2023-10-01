#pragma once
#include <string>
#include <vector>
#include <memory>


#include "gm_data_sound.h"
#include "../dxlib_ext/dxlib_ext.h"





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
	void CreateAllyVoiveList();
	void CreateSystemSEList();
	void CreateBattleStateSEList();
	bool CreateEnemyActSEList();

	bool CreateUISEList();
	//LoadCSV関数
	bool LoadCardSEFromCSV(std::string file_name);



	void PlayBattleBGM(int id);
	void PlayCardSE(int id);
	void PlayAllyDamagedVoice(int id);
	void PlayBattleStateSE(int id);
	void PlayEnemyActSE(int id);
	
	
	
	void PlaySystemSE(int id);
	void PlayUISE(int id);
	void PlayAllyMoveSE();



private:

	SoundManager() = default;
	~SoundManager() = default;



	std::shared_ptr<SoundData> ally_move_se_ = nullptr;

//	std::vector <std::shared_ptr<BGMData>> battle_bgm_list;
	std::vector<std::shared_ptr<SoundData>> battle_bgm_list_;
	std::vector<std::shared_ptr<SoundData>> card_se_list_;

	std::vector<std::shared_ptr<SoundData>> ally_damaged_voice_list_;
	std::vector<std::shared_ptr<SoundData>> ui_se_list_;
	std::vector<std::shared_ptr<SoundData>> system_se_list_;
	std::vector<std::shared_ptr<SoundData>> battle_state_se_list_;
	std::vector<std::shared_ptr<SoundData>> enemy_act_se_list_;

};