#include "gm_unit_ally.h"

#include <algorithm>
#include <random>
#include <chrono>
#include <vector>

//Obj���W�̏�����
void UnitAlly::InitAllyObjPos() {

	int w1 = ((DXE_WINDOW_WIDTH / 10) * 8) / 10;
	int h1 = ((DXE_WINDOW_HEIGHT / 10) * 8) / 10;

	int board_w = (DXE_WINDOW_WIDTH / 10) * 8;
	int board_h = (DXE_WINDOW_HEIGHT / 10) * 8;


	obj_->pos_.z = board_h - (h1 / 2) - (h1) * unit_square_pos_.row;
	obj_->pos_.x = (w1 / 2) + ((w1) * unit_square_pos_.col);

	obj_->Update(0);
}


//Damage�v�Z
void UnitAlly::DecreaseCurrentHp(int value) {

	//�V�[���h������΃V�[���h��D�悵�Č��炷
	if (shield_value_ >= value) {

		shield_value_ -= value;
		return;
	}

	//�V�[���h���Ȃ����HP�����炷
	int actual_damage = value - shield_value_;
	shield_value_ = 0;
	current_hp_ = (std::max)(0, current_hp_ - actual_damage);

}

//UseDeck�ɎR�D�̏��Ԃ�����U��(�V���b�t��)
void UnitAlly::AssignRandomDeckOrderToUseDeck() {

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


//UseDeck�̐擪���珇�Ԃ�����U��
void UnitAlly::AssignDeckOrderToUseDeck() {

	if (!use_deck_.empty()) {

		for (size_t i = 0; i < use_deck_.size(); ++i) {
			use_deck_[i]->SetDeckOrder(i);
		}
	}
}




//UseDeck�ɃV���A���i���o�[������U��
void UnitAlly::AssignSerialNumberToUseDeck() {

	if (!use_deck_.empty()) {

		for (size_t i = 0; i < use_deck_.size(); ++i) {
			use_deck_[i]->SetSerialNum(i);
		}

	}

}



void UnitAlly::ShuffleUseDeck() {

	if (!use_deck_.empty()) {

		//��������
		std::random_device rd;
		std::mt19937 gen(rd());

		// Fisher-Yates�V���b�t���A���S���Y��
		for (int i = use_deck_.size() - 1; i >= 0; --i) {
			std::uniform_int_distribution<int> dist(0, i);
			int j = dist(gen);
			std::swap(use_deck_[i], use_deck_[j]);
		}

	}

}


void UnitAlly::Update(float delta_time) {

	int w1 = ((DXE_WINDOW_WIDTH / 10) * 8) /10;
	int h1 = ((DXE_WINDOW_HEIGHT / 10) * 8) / 10;

	int board_w = (DXE_WINDOW_WIDTH / 10) * 8;
	int board_h = (DXE_WINDOW_HEIGHT / 10) * 8;


	obj_->pos_.z = board_h - (h1 / 2) - (h1) * unit_square_pos_.row;
	obj_->pos_.x = (w1 / 2) + ((w1) * unit_square_pos_.col);

	unit_obj_->pos_.z = board_h - (h1 / 2) - (h1)*unit_square_pos_.row;
	unit_obj_->pos_.x = (w1 / 2) + ((w1)*unit_square_pos_.col);

	unit_obj_->Update(delta_time);
}