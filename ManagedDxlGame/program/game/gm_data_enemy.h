#pragma once
#include <string>
#include "../dxlib_ext/dxlib_ext.h"
#include "gm_enemy_behavior.h"


class EnemyData {
public:

	//CSV用コンストラクタ
	EnemyData(int enemy_id, std::string name, int hp, int power, int speed, int move_cost, int action_cost, std::string face_texture_path, std::string battle_texture_path)
	{
		enemy_id_ = enemy_id;
		name_ = name;
		hp_ = hp;
		power_ = power;
		speed_ = speed;
		move_cost_ = move_cost;
		action_cost_ = action_cost;
		texture_face_ = dxe::Texture::CreateFromFile(face_texture_path);
		texture_battle_ = dxe::Texture::CreateFromFile(battle_texture_path);
	}
	~EnemyData(){}


	//accessor
	void SetIsPicked(bool flag) { is_picked_ = flag; }
	bool GetIsPicked() { return is_picked_; }

	int const GetEnemyDataID() { return enemy_id_; }
	std::string GetName() { return name_; }
	int GetHp() { return hp_; }
	int GetPower() { return power_; }
	int GetSpeed() { return speed_; }
	int GetMoveCost() { return move_cost_; }
	int GetActionCost() { return action_cost_; }

	void SetTextureBattle(std::string texture_path) { 
		texture_battle_ = dxe::Texture::CreateFromFile(texture_path);
	}
	std::shared_ptr<dxe::Texture> GetTextureBattle() { return texture_battle_; }
	
	void SetTextureFace(std::string texture_path) {
		texture_face_ = dxe::Texture::CreateFromFile(texture_path);
	}
	std::shared_ptr<dxe::Texture> GetTextureFace() { return texture_face_; }

	void SetEnemyBehavior(std::shared_ptr<EnemyBehavior> enemy_behavior) { enemy_behavior_ = enemy_behavior; }
	std::shared_ptr<EnemyBehavior> GetEnemyBehavior() { return enemy_behavior_; }

private:

	//status
	int enemy_id_ = 0;
	std::string name_;
	int hp_ = 0;
	int power_ = 0; //攻撃や回復に使う数値
	int speed_ = 0;
	int move_cost_ = 0;
	int action_cost_= 0;


	bool is_picked_ = false;
	
	//EnemyMove,EnemyAct
	std::shared_ptr<EnemyBehavior> enemy_behavior_ = nullptr;


	//Texture
	std::shared_ptr<dxe::Texture> texture_battle_;
	std::shared_ptr<dxe::Texture> texture_face_;

};