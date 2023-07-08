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

		int overlap_ = card_w / 8;
		
		ui_cards_.push_back(new UICard(pos_x_, pos_y_, card_w, card_h));
		ui_cards_.push_back(new UICard(pos_x_ + card_w * 1 - overlap_, pos_y_, card_w, card_h));
		ui_cards_.push_back(new UICard(pos_x_ + card_w * 2 - overlap_ * 2, pos_y_, card_w, card_h));
		ui_cards_.push_back(new UICard(pos_x_ + card_w * 3 - overlap_ * 3, pos_y_, card_w, card_h));
		ui_cards_.push_back(new UICard(pos_x_ + card_w * 4 - overlap_ * 4, pos_y_, card_w, card_h));
		ui_cards_.push_back(new UICard(pos_x_ + card_w * 5 - overlap_ * 5, pos_y_, card_w, card_h));
		ui_cards_.push_back(new UICard(pos_x_ + card_w * 6 - overlap_ * 6, pos_y_, card_w, card_h));
		//ui_cards_.push_back(new UICard(pos_x_ + card_w * 3.5, pos_y_, card_w, card_h));
		//ui_cards_.push_back(new UICard(pos_x_ + card_w * 4, pos_y_, card_w, card_h));
		//ui_cards_.push_back(new UICard(pos_x_ + card_w * 4.5, pos_y_, card_w, card_h));

		
		width_ = card_w * 5;
	
	}
	~UICardHand(){}

	void Update(float delta_time) override;
	void Render() override;

	void SetHandCards(std::vector<Card*> hand_cards) { hand_cards_ = hand_cards; }
	UICard* GetMouseInsideTopCard(int mx, int my);


private:



	int pos_x_;
	int pos_y_;

	int pos2_x_ = pos_x_ + width_;
	int pos2_y_ = pos_y_ + height_;
	
	int width_;
	int height_;

	//int overlap_ = card_w / 7;

	UICard* select_card_ = nullptr;
	std::vector<UICard*> ui_cards_;
	std::vector<Card*> hand_cards_;

	
	int w1 = DXE_WINDOW_WIDTH / 10;
	int h1 = DXE_WINDOW_HEIGHT / 10;

	int card_w = w1 * 1 + (w1 / 2 / 2 / 2);
	int card_h = h1 * 2 + (h1 / 2);


};