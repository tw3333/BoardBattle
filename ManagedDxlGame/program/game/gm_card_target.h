#pragma once

//memo
//カードの対象を格納するクラス

enum InRangeToTarget {
	Ally,
	Enemy,
	All,
	None
};


class CardTarget {
public:

	CardTarget(InRangeToTarget in_range_to_target,int target_num = 0) {
	
		in_range_to_target_ = in_range_to_target;
		target_num_ = target_num;
	
	}
	~CardTarget(){}


	int GetTargetNum() { return target_num_; }

private:

	InRangeToTarget in_range_to_target_ = InRangeToTarget::None;
	int target_num_;
	



};