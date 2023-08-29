#pragma once
#include <vector>

#include "gm_data_board.h"

//memo
//�J�[�h�̑Ώۂ��i�[����N���X

enum class TARGETTYPE {
	InRange,
	Specify,
	None //�������p
};

enum class TOTARGET {
	Ally,
	Enemy,
	Square, //�}�X�w��
	Self, //���g���w��
	All, //�eUnit��
	None //�������p
};

class Unit;


class CardTarget {
public:

	CardTarget(int ref_num, TARGETTYPE target_type, TOTARGET to_target, int target_num = 0) {
		target_ref_num_ = ref_num;
		target_type_ = target_type;
		to_target_ = to_target;
		target_num_ = target_num;
	}
	~CardTarget() { for (auto a : target_units_) { delete a; } }


	TARGETTYPE GetTargetType() { return target_type_; }
	TOTARGET GetToTarget() { return to_target_; }
	int GetTargetNum() { return target_num_; }
	bool GetIsSpecified() { return is_specified_; }
	void SetIsSpecified(bool is_specified) { is_specified_ = is_specified; }

	bool GetIsDetermined() { return is_determined_; }
	void SetIsDetermined(bool is_determined) { is_determined_ = is_determined; }



	int GetTargetRefNum() { return target_ref_num_; }

	std::vector<Unit*>& GetTargetUnits() { return target_units_; }
	void SetTargetUnits(std::vector<Unit*> target_units) { target_units_ = target_units; }
	void AddTargetUnit(Unit* target_unit) { target_units_.push_back(target_unit); }

	void SetTargetSquaresPos(std::vector<SquarePos> target_squares_pos) { target_squares_pos_ = target_squares_pos; }
	std::vector<SquarePos>& GetTargetSquaresPos() { return target_squares_pos_; }
	void AddTargetSquarePos(SquarePos target_square_pos) { target_squares_pos_.push_back(target_square_pos); }


private:

	TARGETTYPE target_type_ = TARGETTYPE::None;
	TOTARGET to_target_ = TOTARGET::None;
	
	bool is_specified_ = false;
	bool is_determined_ = false; //���肵�����ǂ���

	int target_num_ = 0;
	
	int target_ref_num_ = 0; //CardEffect�Ƃ̏ƍ��ԍ�

	std::vector<Unit*> target_units_;
	std::vector<SquarePos> target_squares_pos_; //���ʂ𔭓�����}�X��,�eUnit�̍��W
};