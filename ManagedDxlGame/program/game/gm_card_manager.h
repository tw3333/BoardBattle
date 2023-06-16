#pragma once
#include <vector>
#include "gm_data_card.h"
#include "gm_card.h"

//memo
//Card�N���X�̃C���X�^���X�𐶐��A�ێ��A�Ǘ�����N���X
//Singleton�݌v

class CardManager {
public:

	static CardManager* GetInstance();
	static void Destory();


	//�����o�֐�
	void MakeDebugCard();
	void CreateDebugCardData();


	//get,set
	Card* getCardDateAtIndex(int index) const { return debug_card_data_[index]; }

private:

	CardManager(){};
	~CardManager(){};

	static CardManager* instance_;

	//�����o��
	std::vector<Card*> debug_card_data_;
	std::vector<Card*> all_card_data_;



};