#pragma once

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
	SoundManager& operator = (SoundManager&&) = delete;






private:



	SoundManager() = default;
	~SoundManager() = default;



	
};