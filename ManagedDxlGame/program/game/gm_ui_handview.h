#pragma once
#include <vector>
#include "gm_ui_cardview.h"

//memo
//SceneBattleで使用する手札を表示するUI用クラス
//CardViewクラスを使用して、各Allyの持つ手札を描写

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
