#pragma once
#include <vector>

#include "gm_data_card.h"
#include "gm_card.h"

//memo
//Cardクラスのインスタンスを生成、保持、管理するクラス
//Singleton設計

class CardManager {
public:


	static CardManager& GetInstance() {

		static CardManager instance;
		return instance;

	}

	//コピーコンストラクタ削除
	CardManager(const CardManager&) = delete;
	CardManager& operator=(const CardManager&) = delete;
	//ムーブコンストラクタ削除
	CardManager(CardManager&&) = delete;
	CardManager& operator = (CardManager&&) = delete;


	void CreateDebugCardData();


	//get,set
	//Card* getCardDateAtIndex(int index) const { return debug_card_data_[index]; }

private:

	CardManager() = default;
	~CardManager() = default;



	//メンバ変
	std::vector<CardData*> debug_card_data_;

	std::vector<Card*> all_card_data_;



};