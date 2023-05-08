#pragma once
#include "gm_card.h"
#include "../dxlib_ext/dxlib_ext.h"

//memo
//Cardクラスを画面上に表示させるクラス
//コンストラクタに各Cardのポインタを渡して描写


class CardView {
public:

	CardView(Card* card) { 
	
		card_ = card;
			
	};
	~CardView() {};

	//メンバ関数
	void Render(int x, int y);

	//get,set
	void setIsOpened(bool is_opened) { is_opened_ = is_opened; }

private:

	Card* card_ = nullptr;

	bool is_mouse_Hovering_ = false;
	bool is_opened_ = false;


	int card_w_ = DXE_WINDOW_WIDTH / 10;
	int card_h_ = (DXE_WINDOW_HEIGHT / 10) * 2;
	int open_card_w_ = card_w_ + (card_w_ / 2);
	int open_card_h_ = card_h_ + (DXE_WINDOW_HEIGHT / 10)/2;
	
	int fit_pos_x_;
	int fit_pos_y_;

	int range_explain_box_w_ = DXE_WINDOW_WIDTH / 10;
	int range_explain_box_h_ = DXE_WINDOW_HEIGHT / 10;
};