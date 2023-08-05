#pragma once
#include <string>
#include <memory>
#include "gm_data_card.h"
#include "../dxlib_ext/dxlib_ext.h"




//memo
//Scenebattle�Ŏg�p����C���X�^���X
//Battle�Ŏg�p����̂Œl���ϓ�����
//�܂���������CardEffect���������s���Ă����


class CardRange;
class CardEffect;

class Card  {
public:

	Card(CardData* card_data)
	:card_data_(card_data), base_card_cost_(card_data->GetCardCost()), current_card_cost_(base_card_cost_)
	,is_specify_target_(card_data->GetIsSpecifyTarget()), target_num_(card_data->GetTargetNum())
	{}
	~Card(){}
	


	
	//g,s


	
	bool GetIsSpecifyTarget() { return is_specify_target_; }
	int GetTargetNum() { return target_num_; }

	CardData* GetCardData() { if (card_data_) { return card_data_; } }
	
	void SetDeckOrder(int deck_order) { deck_order_ = deck_order; }
	int GetDeckOrder() { return deck_order_; }


private:

	CardData* card_data_ = nullptr;

	int deck_order_ = 0; //�f�b�L�̉��Ԗڂɂ��邩


	bool is_specify_target_ = false; //�w��^�[�Q�b�g���ǂ���
	int target_num_ = 0; //�w��^�[�Q�b�g�̐�

	int base_card_cost_ = 0;
	int current_card_cost_ = 0;


};