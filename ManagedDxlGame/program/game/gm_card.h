#pragma once
#include <string>
#include <memory>
#include "gm_data_card.h"
#include "../dxlib_ext/dxlib_ext.h"

//memo
//Scenebattleで使用するインスタンス
//Battleで使用するので値が変動する
//またここからCardEffectも実装を行っているよ


class Card {
public:

	Card(CardData* card_data)
	:card_id_(card_data->GetCardID()), card_cost_(card_data->GetCardCost()), current_card_cost_(card_cost_)
	, card_name_(card_data->GetCardName()), card_explanation_(card_data->GetCardExplanation())
	,card_texture_(card_data->GetCardTexture())
	{}
	~Card(){}


	void CardCurrentEffect(float delt_time);

	//g,s


private:

	int card_id_;
	int card_cost_;
	int current_card_cost_;

	std::string card_name_; //カードの名前
	std::string card_explanation_; //カードの効果文

	std::shared_ptr<dxe::Texture> card_texture_;



};