#pragma once
#include <vector>
#include "gm_ui_cardview.h"

//memo
//SceneBattle�Ŏg�p�����D��\������UI�p�N���X
//CardView�N���X���g�p���āA�eAlly�̎���D��`��

class HandView {
public:

	HandView(){}
	~HandView(){}

	void Update();
	void Render();


private:

	std::vector<Card*> hand_card_data_;
	std::vector<CardView*> cards_view_;




};
