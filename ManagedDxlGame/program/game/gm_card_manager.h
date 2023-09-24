#pragma once
#include <vector>
#include <memory>
#include <string>

#include "gm_card_target.h"
#include "gm_card_effect.h"
#include "gm_card_range.h"

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

	TARGETTYPE StrToTargetType(const std::string& str);
	TOTARGET StrToToTarget(const std::string& str);

	void LoadCardDataFromCSV(const std::string& filepath);
	void LoadCardRangeFromCSV(const std::string& filepath);
	void LoadCardTargetFromCSV(const std::string& filepath);

	void LoadCardEffectFromCSV(const std::string& filepath);

	void LoadAllCardTargetFromCSV(const std::string& filepath);
	void LoadAllCardEffectFromCSV(const std::string& filepath);


	void LoadAllCardRangeFromCSV(const std::string& filepath);


	void CombineCardData();

	void CreateAllInitCard();
	void LoadC1DeckFromCSV(const std::string& filepath);
	void LoadC2DeckFromCSV(const std::string& filepath);
	void LoadC3DeckFromCSV(const std::string& filepath);

	void SeparetePossCards();


	std::vector<std::shared_ptr<Card>> GetDebugDeck() { return debug_deck_;	}
	std::vector<CardData*> GetAllCardData() { return all_card_data_; }
	std::vector<std::shared_ptr<Card>> GetAllCard() { return all_card_; }

	std::vector<std::shared_ptr<CardTarget>> GetAllCardTarget() { return all_card_target_; }
	std::vector<std::shared_ptr<CardEffect>> GetAllCardEffect() { return all_card_effect_; }

	std::vector <std::shared_ptr<Card>> GetC1Deck() { return c1_deck_; }
	std::vector <std::shared_ptr<Card>> GetC2Deck() { return c2_deck_; }
	std::vector <std::shared_ptr<Card>> GetC3Deck() { return c3_deck_; }

	std::vector<std::shared_ptr<Card>> GetC1PossCards() { return c1_poss_cards; }
	std::vector<std::shared_ptr<Card>> GetC2PossCards() { return c2_poss_cards; }
	std::vector<std::shared_ptr<Card>> GetC3PossCards() { return c3_poss_cards; }

	//get,set
	//Card* getCardDateAtIndex(int index) const { return debug_card_data_[index]; }

private:

	CardManager() = default;
	~CardManager() = default;



	//メンバ変
	std::vector<CardData*> debug_card_data_;
	
	std::vector<Card*> debug_card_;
	std::vector<std::shared_ptr<Card>> debug_deck_;

	//std::vector<Card> c1_deck_;
	//std::vector<Card> c2_deck_;
	//std::vector<Card> c3_deck_;
	//std::vector<Card> c4_deck_;

	std::vector<std::shared_ptr<Card>> c1_deck_;
	std::vector<std::shared_ptr<Card>> c2_deck_;
	std::vector<std::shared_ptr<Card>> c3_deck_;


	//std::vector<std::shared_ptr<Card>> all_card_; //全てのカード

	std::vector<CardData*> all_card_data_; //全てのカードのCardData
	std::vector<std::shared_ptr<Card>> all_card_; //全てのカード
	std::vector<std::shared_ptr<Card>> c1_poss_cards;
	std::vector<std::shared_ptr<Card>> c2_poss_cards;
	std::vector<std::shared_ptr<Card>> c3_poss_cards;



	std::vector<std::shared_ptr<CardTarget>> all_card_target_; //全てのカードのCardTarget
	std::vector<std::shared_ptr<CardEffect>> all_card_effect_; //全てのカードのCardTarget
	std::vector<std::shared_ptr<CardRange>> all_card_range_; //全てのカードのCardTarget


};