#include "gm_ui_cardview.h"


//Card�N���X�̃C���X�^���X�`�ʂ���֐�
//arg1...�`�ʂ��������W�̍��㒸�_���Wx, arg2...�`�ʂ��������W�̍��㒸�_���Wy
void CardView::Render(int x, int y) {

	if (is_opened_) {

		DrawExtendGraph(x, y, x + card_w_, y + card_h_, card_->getCardImgHandle(), false);


	}
	else {

		DrawExtendGraph(x, y, x + card_w_, y + card_h_, card_->getCardImgHandle(), false);

	}
	
	
}




