#pragma once
#include <vector>
#include "gm_ally.h"

//memo
//Ally�̃C���X�^���X���쐬�A�ێ��A�Ǘ�����N���X
//Singleton�݌v

class AllyManager {
public:

	static AllyManager* GetInstance();
	static void Destory();

	std::vector<Ally*> allies_;

private:

	AllyManager(){};
	~AllyManager(){};

	static AllyManager* instance_;

	//�SAlly�̃C���X�^���X
	//std::vector<Ally*> allies_;



};