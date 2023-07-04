#pragma once
#include "gm_card.h"



class CardPlay {
public:

	CardPlay() {}
	~CardPlay() {}


	void Update();
	void Render();



private:


	Card* select_card_ = nullptr;
	Card* play_card_ = nullptr;





};