#pragma once
#include <vector>

#include "gm_card.h"

//memo
//Cardクラスのインスタンスを生成、保持、管理するクラス
//Singleton設計

class CardManager {
public:

	static CardManager* GetInstance();
	static void Destory();


	//メンバ関数
	void MakeDebugCard();

private:

	CardManager(){};
	~CardManager(){};

	static CardManager* instance_;

	//メンバ変
	std::vector<Card*> debug_card_data_;
	std::vector<Card*> all_card_data_;



};