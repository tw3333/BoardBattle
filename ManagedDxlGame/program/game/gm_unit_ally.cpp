#include "gm_unit_ally.h"

#include <algorithm>
#include <random>
#include <chrono>
#include <vector>

//AllyUnit�̔Ֆʏ�̍��W�̃Z�b�g�A�܂�����ɑΉ�����Obj��Pos�̕ύX
void UnitAlly::SetBoardPos(int row, int col) {

	board_pos_ = { row, col };

	int w1 = ((DXE_WINDOW_WIDTH / 10) * 8) / 10;
	int h1 = ((DXE_WINDOW_HEIGHT / 10) * 8) / 10;

	int board_w = (DXE_WINDOW_WIDTH / 10) * 8;
	int board_h = (DXE_WINDOW_HEIGHT / 10) * 8;


	obj_->pos_.z = board_h - (h1 / 2) - (h1) * board_pos_.row;
	obj_->pos_.x = (w1 / 2) + ((w1) * board_pos_.col);

}


//UseDeck�ɎR�D�̏��Ԃ�����U��
void UnitAlly::AssignDeckOrder() {

	if (!use_deck_.empty()) {

		std::vector<int> order(use_deck_.size());

		for (size_t i = 0; i < use_deck_.size(); ++i) {
			order[i] = i;
		}

		//order���V���b�t��
		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
		std::shuffle(order.begin(), order.end(), std::default_random_engine(seed));

		//order�̏��Ԃ�use_deck_����Card�ɏ��Ԃ�����U��
		for (size_t i = 0; i < use_deck_.size(); ++i) {
			use_deck_[i]->SetDeckOrder(order[i]);
		}

	}

}


void UnitAlly::Update() {

	int w1 = ((DXE_WINDOW_WIDTH / 10) * 8) /10;
	int h1 = ((DXE_WINDOW_HEIGHT / 10) * 8) / 10;

	int board_w = (DXE_WINDOW_WIDTH / 10) * 8;
	int board_h = (DXE_WINDOW_HEIGHT / 10) * 8;


	obj_->pos_.z = board_h - (h1 / 2) - (h1) * board_pos_.row;
	obj_->pos_.x = (w1 / 2) + ((w1) * board_pos_.col);

}