#pragma once

//memo
//�J�[�h�̑Ώۂ��i�[����N���X

enum class TARGETTYPE {
	InRange,
	Specify,
	None
};

enum class TOTARGET {
	Ally,
	Enemy,
	Self, //���g���w��
	All, //�eUnit��
	None //�����p�����[�^
};




class CardTarget {
public:

	CardTarget(TARGETTYPE target_type, TOTARGET to_target, int target_num = 0) {
	
		target_type_ = target_type;
		to_target_ = to_target;
		target_num_ = target_num;
	
	}
	~CardTarget(){}


	TARGETTYPE GetTargetType() { return target_type_; }
	TOTARGET GetToTarget() { return to_target_; }
	int GetTargetNum() { return target_num_; }
	bool GetIsSpecified() { return is_specified_; }
	void SetIsSpecified(bool is_specified) { is_specified_ = is_specified; }

private:

	TARGETTYPE target_type_ = TARGETTYPE::None;
	TOTARGET to_target_ = TOTARGET::None;
	bool is_specified_ = false;

	int target_num_ = 0;
	

	



};