#pragma once

//memo
//�]���̐݌v
//Battle�V�[����Phase���Ǘ�����

class PhaseManager {
public:

	static PhaseManager* GetInstance(); //�C���X�^���X�̎擾
	static void Destory(); //�C���X�^���X�̍폜


private:

	PhaseManager() {};
	~PhaseManager() {};

	static PhaseManager* instance_;


};