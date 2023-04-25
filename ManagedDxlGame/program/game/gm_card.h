#pragma once
#include <string>

class Card {
public:

	Card(int cost){
		cost_ = cost;
	
	}
	~Card(){}



private:

	int cost_;

	//std::string;
	
	
	int card_img_handle;
	std::string card_img_path;
	


};