#pragma once
#include <vector>

#include "gm_card.h"

//memo
//SceneBattleで各Allyの手札を管理するクラス

class Hand {
public:

	Hand() {};
	~Hand() {};



private:

	std::vector<Card*> hand_card_data_;




};