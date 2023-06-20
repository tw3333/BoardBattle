#pragma once
#include <string>
#include <memory>
#include "gm_data_card.h"
#include "../dxlib_ext/dxlib_ext.h"


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
	

	enum class RangeType {
		None, //発動allyのposから
		OnlyUp,
		OnlyDown,
		OnlyLeft,
		OnlyRight,
		FourDirections, //四方向に対して
		AllEnemy, //全てのenemyに対して
		AllAlly //全てのallyに対して
	};

	enum class TargetType {
		Ally,
		Enemy
	};


	void DisplayRange(UnitAlly* turn_ally, Board* board);
	void AddInRangeUnits();
	void AddTargetUnits();

	void CardEffect();

	//g,s
	void AddRangeAllyUnits(UnitAlly* unit) { in_range_ally_list_.push_back(unit); }
	void AddRangeEnemyUnits(UnitEnemy* unit) { in_range_enemy_list_.push_back(unit); }
	void AddTargetAllyUnits(UnitAlly* unit) { target_ally_list_.push_back(unit); }
	void AddTargetEnemyUnits(UnitEnemy* unit) { target_enemy_list_.push_back(unit); }

private:

	RangeType range_type_;
	TargetType target_type_;

	int target_num_ = 1;
	int range_num_ = 1;

	int card_id_;
	int card_cost_;
	int current_card_cost_;


	std::string card_name_; //カードの名前
	std::string card_explanation_; //カードの効果文

	std::shared_ptr<dxe::Texture> card_texture_;


	std::vector<UnitAlly*> in_range_ally_list_;
	std::vector<UnitEnemy*> in_range_enemy_list_;

	std::vector<UnitAlly*> target_ally_list_;
	std::vector<UnitEnemy*> target_enemy_list_;

};