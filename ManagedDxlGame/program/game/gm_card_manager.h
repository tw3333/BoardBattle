#pragma once
#include <vector>
#include <memory>





//memo
//Cardクラスのインスタンスを生成、保持、管理するクラス
//Singleton設計
class Card;
class CardData;

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
	void CreateDebugCardDeck();
	void CreateDebugCard();


	//get,set
	//Card* getCardDateAtIndex(int index) const { return debug_card_data_[index]; }

private:

	CardManager() = default;
	~CardManager() = default;



	//メンバ変
	std::vector<CardData*> debug_card_data_;
	
	std::vector<Card*> debug_card_;
	std::vector<std::shared_ptr<Card>> debug_deck_;


	std::vector<Card*> all_card_data_;
	
	std::vector<Card*> c1_card_data_;
	std::vector<Card*> c2_card_data_;
	std::vector<Card*> c3_card_data_;
	std::vector<Card*> c4_card_data_;
};