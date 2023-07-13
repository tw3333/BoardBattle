#pragma once
#include <string>
#include <memory>
#include "gm_data_card.h"
#include "../dxlib_ext/dxlib_ext.h"

#include "gm_card_range.h"
#include "gm_card_effect.h"


//memo
//Scenebattleで使用するインスタンス
//Battleで使用するので値が変動する
//またここからCardEffectも実装を行っているよ

class UnitAlly;
class UnitEnemy;
class Board;

class Card  {
public:

	Card(CardData* card_data)
	:card_id_(card_data->GetCardID()), card_cost_(card_data->GetCardCost()), current_card_cost_(card_cost_)
	, card_name_(card_data->GetCardName()), card_explanation_(card_data->GetCardExplanation())
	, card_texture_(card_data->GetCardTexture())
	{}
	~Card(){}
	

	void DisplayRange(UnitAlly* turn_ally, Board* board); //Cardの射程表示
	
	//g,s
	void AddRangeAllyUnits(UnitAlly* unit) { in_range_ally_list_.push_back(unit); }
	void AddRangeEnemyUnits(UnitEnemy* unit) { in_range_enemy_list_.push_back(unit); }
	void AddTargetAllyUnits(UnitAlly* unit) { target_ally_list_.push_back(unit); }
	void AddTargetEnemyUnits(UnitEnemy* unit) { target_enemy_list_.push_back(unit); }
	
	bool GetIsSpecifyTarget() { return is_specify_target_; }
	int GetTargetNum() { return target_num_; }




private:

	bool is_specify_target_ = false; //指定ターゲットかどうか
	int target_num_ = 0; //指定ターゲットの数


	int card_id_;
	int card_cost_;
	int current_card_cost_;


	std::string card_name_; //カードの名前
	std::string card_explanation_; //カードの効果文


	std::shared_ptr<dxe::Texture> card_texture_;

	std::vector<CardRange*> card_range_list_;
	std::vector<CardEffect*> card_effect_list_;

	std::vector<UnitAlly*> in_range_ally_list_;
	std::vector<UnitEnemy*> in_range_enemy_list_;
	std::vector<UnitAlly*> target_ally_list_;
	std::vector<UnitEnemy*> target_enemy_list_;

	std::vector<Unit*> in_range_unit_list_;
	std::vector<Unit*> target_unit_list_;


};