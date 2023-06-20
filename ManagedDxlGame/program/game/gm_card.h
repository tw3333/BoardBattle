#pragma once
#include <string>
#include <memory>
#include "gm_data_card.h"
#include "../dxlib_ext/dxlib_ext.h"


//memo
//Scenebattle�Ŏg�p����C���X�^���X
//Battle�Ŏg�p����̂Œl���ϓ�����
//�܂���������CardEffect���������s���Ă����

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
		None, //����ally��pos����
		OnlyUp,
		OnlyDown,
		OnlyLeft,
		OnlyRight,
		FourDirections, //�l�����ɑ΂���
		AllEnemy, //�S�Ă�enemy�ɑ΂���
		AllAlly //�S�Ă�ally�ɑ΂���
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


	std::string card_name_; //�J�[�h�̖��O
	std::string card_explanation_; //�J�[�h�̌��ʕ�

	std::shared_ptr<dxe::Texture> card_texture_;


	std::vector<UnitAlly*> in_range_ally_list_;
	std::vector<UnitEnemy*> in_range_enemy_list_;

	std::vector<UnitAlly*> target_ally_list_;
	std::vector<UnitEnemy*> target_enemy_list_;

};