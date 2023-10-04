#pragma once

class BattleConfig {
public:

	BattleConfig() {}
	~BattleConfig() {}


	const int GetMaxHandNum() { return max_hand_num_; }


private:

	int max_hand_num_ = 10;
	


};