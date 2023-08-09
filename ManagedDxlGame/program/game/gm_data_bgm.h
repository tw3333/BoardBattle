#pragma once

#include <string>

#include "DxLib.h"


class BGMData {
public:

	BGMData(int id, std::string file_path) {
		id_ = id;
		bgm_handle_ = LoadSoundMem(file_path.c_str());
	}
	
	~BGMData(){};

	int GetID() { return id_; }
	int GetBGMHandle() { return bgm_handle_; }


private:

	int id_;
	int bgm_handle_;


};