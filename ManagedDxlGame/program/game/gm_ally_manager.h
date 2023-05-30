#pragma once
#include <vector>



//memo
//Allyのインスタンスを作成、保持、管理するクラス
//Singleton設計

class AllyManager {
public:

	static AllyManager* GetInstance();
	static void Destory();

	

private:

	AllyManager(){};
	~AllyManager(){};

	static AllyManager* instance_;

	//メンバ変数	
	/*std::vector<Ally*> all_ally_data_;*/


};