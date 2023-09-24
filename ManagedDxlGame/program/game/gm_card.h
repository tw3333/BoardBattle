#pragma once
#include <string>
#include <memory>
#include "gm_data_card.h"
#include "../dxlib_ext/dxlib_ext.h"




//memo
//Scenebattleで使用するインスタンス
//Battleで使用するので値が変動する
//またここからCardEffectも実装を行っているよ


class CardRange;
class CardEffect;

class Card  {
public:

	Card(CardData* card_data)
	:card_data_(card_data), base_card_cost_(card_data->GetCardCost()), current_card_cost_(base_card_cost_)
	{}
	~Card() {  }
	
	CardData* GetCardData() {if (card_data_) { return card_data_; } }
	int GetCardID() { if (card_data_) { return card_data_->GetCardID(); } }

	
	void SetDeckOrder(int deck_order) { deck_order_ = deck_order; }
	int GetDeckOrder() { return deck_order_; }
	void SetSerialNum(int serial_num) { serial_num_ = serial_num; }
	int GetSerialNum() { return serial_num_; }

private:

	CardData* card_data_ = nullptr;

	int deck_order_ = 0; //デッキの何番目にあるか
	int serial_num_ = 0; //デッキ内で識別用の番号

	int base_card_cost_ = 0;
	int current_card_cost_ = 0;


};