#pragma once
#include "gm_ui_component.h"
#include "gm_card.h"
#include "gm_ui_card.h"


//memo
//インスタンス化の際、カードを表示する場所を四角形で決め、その範囲内にカードを表示するようにする
//カードの上限は10枚とする

class UICardHand : public UIComponent {
public:
	
	UICardHand(int posx, int posy, int width, int height) 
	: pos_x_(posx), pos_y_(posy), width_(width), height_(height)
	{
		

		
	
	}
	~UICardHand(){}

	void Update(float delta_time) override;
	void Render() override;

	void SetHandCards(std::vector<Card*> hand_cards) { hand_cards_ = hand_cards; }

private:



	int pos_x_;
	int pos_y_;
	int width_;
	int height_;

	std::vector<UICard> ui_cards_;
	std::vector<Card*> hand_cards_;

	

};