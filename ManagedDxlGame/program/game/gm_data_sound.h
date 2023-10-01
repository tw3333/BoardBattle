#pragma once

#include <string>

#include "DxLib.h"



enum class SoundType{
	None,
	BGM,
	CardSE,
	EnemyActSE,
	AllyVoice,
	BattleStateSE,
	UISE,
	SystemSE,
};


class SoundData {
public:

	//Volume設定つきコンストラクタ
	SoundData(int id, SoundType sound_type, std::string name, int volume) {
		id_ = id;
		sound_type_ = sound_type;
		sound_handle_ = LoadSoundMem(name.c_str());
		ChangeVolumeSoundMem(volume, sound_handle_);
	}

	
	SoundData(int id, SoundType sound_type ,std::string name){
		id_ = id;
		sound_type_ = sound_type;
		sound_handle_ = LoadSoundMem(name.c_str());
	}
	~SoundData(){}


	const int GetID() { return id_; }
	SoundType GetSoundType() { return sound_type_; }
	int GetSoundHandle() { return sound_handle_; }


private:

	int id_ = 0;
	SoundType sound_type_ = SoundType::None;
	int sound_handle_ = 0;


};