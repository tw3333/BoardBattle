#pragma once
#include <vector>


//memo
//カードの対象を格納するクラス

enum class TARGETTYPE {
	InRange,
	Specify,
	None
};

enum class TOTARGET {
	Ally,
	Enemy,
	Self, //自身を指定
	All, //各Unitに
	None //初期パラメータ
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



private:

	TARGETTYPE target_type_ = TARGETTYPE::None;
	TOTARGET to_target_ = TOTARGET::None;
	bool is_specified_ = false;
	bool is_determined_ = false;

	int target_num_ = 0;
	
	int target_ref_num_ = 0;

	std::vector<Unit*> target_units_;

};