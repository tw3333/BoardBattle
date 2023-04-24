#pragma once
#include <vector>
#include "gm_ally.h"

//memo
//Allyのインスタンスを作成、保持、管理するクラス
//Singleton設計

class AllyManager {
public:

	static AllyManager* GetInstance();
	static void Destory();

	std::vector<Ally*> allies_;

private:

	AllyManager(){};
	~AllyManager(){};

	static AllyManager* instance_;

	//全Allyのインスタンス
	//std::vector<Ally*> allies_;



};