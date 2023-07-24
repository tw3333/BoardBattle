#pragma once
#include "gm_ui_component.h"
#include "gm_card.h"
#include "gm_ui_card.h"


//memo
//インスタンス化の際、カードを表示する場所を四角形で決め、その範囲内にカードを表示するようにする
//カードの上限は10枚、５枚を表示するカードの幅に上に被せてカードを詰める形で表示

class UICardHand : public UIComponent {
public:

	UICardHand(int posx, int posy, int width, int height)
		: pos_x_(posx), pos_y_(posy), width_(width), height_(height)
	{

		//int overlap_ = card_w / 8;
		//ui_cards_.push_back(new UICard(pos_x_, pos_y_, card_w, card_h));
		//ui_cards_.push_back(new UICard(pos_x_ + card_w * 1 - overlap_, pos_y_, card_w, card_h));
		//ui_cards_.push_back(new UICard(pos_x_ + card_w * 2 - overlap_ * 2, pos_y_, card_w, card_h));
		//ui_cards_.push_back(new UICard(pos_x_ + card_w * 3 - overlap_ * 3, pos_y_, card_w, card_h));
		//ui_cards_.push_back(new UICard(pos_x_ + card_w * 4 - overlap_ * 4, pos_y_, card_w, card_h));
		//ui_cards_.push_back(new UICard(pos_x_ + card_w * 5 - overlap_ * 5, pos_y_, card_w, card_h));
		//ui_cards_.push_back(new UICard(pos_x_ + card_w * 6 - overlap_ * 6, pos_y_, card_w, card_h));
		//ui_cards_.push_back(new UICard(pos_x_ + card_w * 3.5, pos_y_, card_w, card_h));
		//ui_cards_.push_back(new UICard(pos_x_ + card_w * 4, pos_y_, card_w, card_h));
		//ui_cards_.push_back(new UICard(pos_x_ + card_w * 4.5, pos_y_, card_w, card_h));
		
		//for (int i = 0; i < 5; ++i) {
		//	ui_hand_5_.push_back(new UICard(pos_x_ + (card_w *i), pos_y_, card_w, card_h));
		//}
		//for (int i = 0; i < 6; ++i) {
		//	int lap = card_w / 6;
		//	ui_hand_6_.push_back(new UICard(pos_x_ + (card_w *i) - lap, pos_y_, card_w, card_h));
		//}

		//width_ = card_w * 5;

		for (int i = 0; i < 10; ++i) {
			ui_hand_.push_back(new UICard(pos_x_, pos_y_,card_w, card_h));

		}


	}
	~UICardHand() {}


	void Update(float delta_time) override;
	void Render() override;
	void AdjustCardPos(int card_num);


	void SetHandCards(std::vector<Card*> hand_cards) { hand_cards_ = hand_cards; }
	UICard* GetMouseInsideTopCard(int mx, int my);


private:



	int pos_x_ = 0;
	int pos_y_ = 0;

	int pos2_x_ = pos_x_ + width_;
	int pos2_y_ = pos_y_ + height_;

	int width_ = card_w * 5;
	int height_ = 0;

	int overlap_ = 0;
	int total_width_ = card_w *5;

	UICard* select_card_ = nullptr;

	std::vector<UICard*> ui_cards_;
	std::vector<UICard*> ui_hand_;

	std::vector<UICard*> ui_hand_1_;
	std::vector<UICard*> ui_hand_2_;
	std::vector<UICard*> ui_hand_3_;
	std::vector<UICard*> ui_hand_4_;
	std::vector<UICard*> ui_hand_5_;
	std::vector<UICard*> ui_hand_6_;
	std::vector<UICard*> ui_hand_7_;
	std::vector<UICard*> ui_hand_8_;
	std::vector<UICard*> ui_hand_9_;
	std::vector<UICard*> ui_hand_10_;



	std::vector<Card*> hand_cards_;

	int debug_count_ = 5;

	
	int w1 = DXE_WINDOW_WIDTH / 10;
	int h1 = DXE_WINDOW_HEIGHT / 10;

	int card_w = w1 * 1 + (w1 / 2 / 2 / 2);
	int card_h = h1 * 2 + (h1 / 2);


};