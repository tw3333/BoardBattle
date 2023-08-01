#pragma once

class SoundManager {
public:

	static SoundManager& GetInstance() {
		static SoundManager instance;
		return instance;
	}

	//�R�s�[�R���X�g���N�^�폜
	SoundManager(const SoundManager&) = delete;
	SoundManager& operator=(const SoundManager&) = delete;
	//���[�u�R���X�g���N�^�폜
	SoundManager(SoundManager&&) = delete;
	SoundManager& operator = (SoundManager&&) = delete;






private:



	SoundManager() = default;
	~SoundManager() = default;



	
};