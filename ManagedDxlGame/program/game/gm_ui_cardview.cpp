#include "gm_ui_cardview.h"


//Cardクラスのインスタンス描写する関数
//arg1...描写したい座標の左上頂点座標x, arg2...描写したい座標の左上頂点座標y
void CardView::Render(int x, int y) {

	if (is_opened_) {

		DrawExtendGraph(x, y, x + card_w_, y + card_h_, card_->getCardImgHandle(), false);


	}
	else {

		DrawExtendGraph(x, y, x + card_w_, y + card_h_, card_->getCardImgHandle(), false);

	}
	
	
}




