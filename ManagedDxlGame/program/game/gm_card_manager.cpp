#include "../dxlib_ext/dxlib_ext.h"

#include "gm_card_manager.h"


CardManager* CardManager::instance_ = nullptr;

CardManager* CardManager::GetInstance() {

	if (!instance_) { instance_ = new CardManager(); }
	return instance_;

}

void CardManager::Destory() {

	if (instance_) { 
		delete instance_; 
		instance_ = nullptr;
	}

}

//debug用のカード生成
void CardManager::MakeDebugCard() {

	//for (int i = 0; i < 10; ++i) {
	//	debug_card_data_.emplace_back(new Card(1));

	//}

	//for (int i = 0; i < debug_card_data_.size(); ++i) {
	//	debug_card_data_[i]->setCardImgHandle(LoadGraph("graphics/card/card_test_img.png"));

	//}

}