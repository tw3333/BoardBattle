#pragma once
#include <string>
#include <memory>
#include "gm_data_card.h"
#include "../dxlib_ext/dxlib_ext.h"

#include "gm_card_range.h"
#include "gm_card_effect.h"


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
	:card_data_(card_data), base_card_cost_(card_data->GetCardCost()), current_card_cost_(base_card_cost_)
	,is_specify_target_(card_data->GetIsSpecifyTarget()), target_num_(card_data->GetTargetNum())
	{}
	~Card(){}
	

	void DisplayRange(UnitAlly* turn_ally, Board* board); //Card�̎˒��\��
	
	//g,s
	std::vector<CardRange*> GetCardRangeList() { return card_range_list_; }
	std::vector<CardEffect*> GetCardEffectList() { return card_effect_list_; }
	void AddCardRange(CardRange* card_range) { card_range_list_.push_back(card_range); }
	void AddCardEffect(CardEffect* card_effect) { card_effect_list_.push_back(card_effect); }


	
	bool GetIsSpecifyTarget() { return is_specify_target_; }
	int GetTargetNum() { return target_num_; }
	CardData* GetCardData() { return card_data_; }
	


private:

	CardData* card_data_ = nullptr;

	bool is_specify_target_ = false; //�w��^�[�Q�b�g���ǂ���
	int target_num_ = 0; //�w��^�[�Q�b�g�̐�

	int base_card_cost_ = 0;
	int current_card_cost_ = 0;


	std::vector<CardRange*> card_range_list_;
	std::vector<CardEffect*> card_effect_list_;


};