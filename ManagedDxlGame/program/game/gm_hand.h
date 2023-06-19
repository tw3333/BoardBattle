#pragma once
#include <vector>

#include "gm_card.h"

//memo
//SceneBattleで各Allyの手札を管理するクラス
//描写、発動、破棄などの処理を行う


class Hand {
public:

	Hand() {};
	~Hand() {};



private:

	std::vector<Card*> hand_card_data_;




};