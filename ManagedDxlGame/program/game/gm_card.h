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
	:card_id_(card_data->GetCardID()), card_cost_(card_data->GetCardCost()), current_card_cost_(card_cost_)
	, card_name_(card_data->GetCardName()), card_explanation_(card_data->GetCardExplanation())
	, card_texture_(card_data->GetCardTexture())
	{}
	~Card(){}
	

	void DisplayRange(UnitAlly* turn_ally, Board* board); //Card�̎˒��\��
	
	//g,s
	std::vector<CardRange*> GetCardRangeList() { return card_range_list_; }
	std::vector<CardEffect*> GetCardEffectList() { return card_effect_list_; }

	
	bool GetIsSpecifyTarget() { return is_specify_target_; }
	int GetTargetNum() { return target_num_; }




private:

	bool is_specify_target_ = false; //�w��^�[�Q�b�g���ǂ���
	int target_num_ = 0; //�w��^�[�Q�b�g�̐�


	int card_id_;
	int card_cost_;
	int current_card_cost_;


	std::string card_name_; //�J�[�h�̖��O
	std::string card_explanation_; //�J�[�h�̌��ʕ�


	std::shared_ptr<dxe::Texture> card_texture_;

	std::vector<CardRange*> card_range_list_;
	std::vector<CardEffect*> card_effect_list_;


};