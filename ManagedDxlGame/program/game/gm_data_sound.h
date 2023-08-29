#pragma once

#include <string>

#include "DxLib.h"



enum class SoundType{
	BGM,
	CardSE,
	UISE,
	SystemSE
};


class SoundData {
public:

	SoundData(int id, SoundType sound_type ,std::string name){
		id_ = id;
		sound_type_ = sound_type;
		sound_handle_ = LoadSoundMem(name.c_str());
	}
	~SoundData(){}


	int GetID() { return id_; }
	SoundType GetSoundType() { return sound_type_; }
	int GetSoundHandle() { return sound_handle_; }


private:

	int id_;
	SoundType sound_type_;
	int sound_handle_;

};