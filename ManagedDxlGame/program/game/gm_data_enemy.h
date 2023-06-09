#pragma once
#include <string>
#include "../dxlib_ext/dxlib_ext.h"

class EnemyData {
public:

	EnemyData(int enemy_id, std::string name, int hp, int speed, int move_cost)
	:enemy_id_(enemy_id),name_(name),hp_(hp),speed_(speed),move_cost_(move_cost)
	{}
	~EnemyData(){}





	//accessor
	int GetEnemyDataID() { return enemy_id_; }
	std::string GetName() { return name_; }
	int GetHp() { return hp_; }
	int GetSpped() { return speed_; }
	int GetMoveCost() { return move_cost_; }

	void SetTextureBattle(std::string texture_path) { 
		texture_battle_ = dxe::Texture::CreateFromFile(texture_path);
	}



private:

	//status
	int enemy_id_;
	std::string name_;
	int hp_;
	int speed_;
	int move_cost_;


	bool is_picked_ = false;
	

	//Texture
	Shared<dxe::Texture> texture_battle_;


};