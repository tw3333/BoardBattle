#pragma once
#include <vector>

#include "gm_data_card.h"
#include "gm_card.h"

//memo
//Card�N���X�̃C���X�^���X�𐶐��A�ێ��A�Ǘ�����N���X
//Singleton�݌v

class CardManager {
public:


	static CardManager& GetInstance() {

		static CardManager instance;
		return instance;

	}

	//�R�s�[�R���X�g���N�^�폜
	CardManager(const CardManager&) = delete;
	CardManager& operator=(const CardManager&) = delete;
	//���[�u�R���X�g���N�^�폜
	CardManager(CardManager&&) = delete;
	CardManager& operator = (CardManager&&) = delete;


	void CreateDebugCardData();


	//get,set
	//Card* getCardDateAtIndex(int index) const { return debug_card_data_[index]; }

private:

	CardManager() = default;
	~CardManager() = default;



	//�����o��
	std::vector<CardData*> debug_card_data_;

	std::vector<Card*> all_card_data_;



};