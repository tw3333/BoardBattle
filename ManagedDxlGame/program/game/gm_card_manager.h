#pragma once
#include <vector>

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

private:

	CardManager(){};
	~CardManager(){};

	static CardManager* instance_;

	//�����o��
	std::vector<Card*> debug_card_data_;
	std::vector<Card*> all_card_data_;



};