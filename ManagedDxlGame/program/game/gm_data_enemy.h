#pragma once
#include <string>

class EnemyData {
public:

	EnemyData(){}
	~EnemyData(){}





	//accessor
	int GetEnemyDataID() { return enemy_id_; }


private:

	int enemy_id_;
	
	std::string name_;

	int hp_;
	int speed_;

	int move_cost_;


	bool is_picked_ = false;
	


};