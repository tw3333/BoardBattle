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

	

private:

	AllyManager(){};
	~AllyManager(){};

	static AllyManager* instance_;

	//�����o�ϐ�	
	std::vector<Ally*> all_ally_data_;


};