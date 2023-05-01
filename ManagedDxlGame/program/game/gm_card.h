#pragma once
#include <string>

class Card {
public:

	Card(int cost){
		cost_ = cost;
	
	}
	~Card(){}

	//g,s
	void setCardImgHandle(int handle) { card_img_handle_ = handle;  };

private:

	int card_id_;
	std::string card_name_;
	std::string card_explanation_; //カードの効果文

	int card_img_handle_; 
	std::string card_img_path_;


	//パラメータ
	int cost_;


};