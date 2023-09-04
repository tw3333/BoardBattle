#pragma once
#include <string>
#include "../dxlib_ext/dxlib_ext.h"
#include "gm_enemy_act.h"
#include "gm_enemy_move.h"

class ObjEnemy;

class EnemyData {
public:


	EnemyData(int enemy_id, std::string name, int hp, int power, int speed, int move_cost, int action_cost)
	:enemy_id_(enemy_id), name_(name), hp_(hp),power_(power), speed_(speed),move_cost_(move_cost)
	, action_cost_(action_cost)
	{}
	~EnemyData(){}


	//accessor
	void SetIsPicked(bool flag) { is_picked_ = flag; }
	bool GetIsPicked() { return is_picked_; }

	int GetEnemyDataID() { return enemy_id_; }
	std::string GetName() { return name_; }
	int GetHp() { return hp_; }
	int GetPower() { return power_; }
	int GetSpeed() { return speed_; }
	int GetMoveCost() { return move_cost_; }
	int GetActionCost() { return action_cost_; }

	void SetTextureBattle(std::string texture_path) { 
		texture_battle_ = dxe::Texture::CreateFromFile(texture_path);
	}
	Shared<dxe::Texture> GetTextureBattle() { return texture_battle_; }
	
	void SetTextureFace(std::string texture_path) {
		texture_face_ = dxe::Texture::CreateFromFile(texture_path);
	}
	Shared<dxe::Texture> GetTextureFace() { return texture_face_; }

	void SetObj(ObjEnemy* obj) { obj_ = obj; }
	ObjEnemy* GetObj() { return obj_; }

	void SetEnemyMove(std::shared_ptr<EnemyMove> enemy_move) { enemy_move_ = enemy_move; }
	void SetEnemyAct(std::shared_ptr<EnemyAct> enemy_act) { enemt_act_ = enemy_act; }
	std::shared_ptr<EnemyMove> GetEnemyMove() { return enemy_move_; }
	std::shared_ptr<EnemyAct> GetEnemyAct() { return enemt_act_; }

private:

	//status
	int enemy_id_;
	std::string name_;
	int hp_;
	int power_; //�U����񕜂Ɏg�����l
	int speed_;
	int move_cost_;
	int action_cost_;


	bool is_picked_ = false;
	
	std::shared_ptr<EnemyMove> enemy_move_ = nullptr;
	std::shared_ptr<EnemyAct> enemt_act_ = nullptr;
	
	
	

	//Obj
	ObjEnemy* obj_ = nullptr;

	//Texture
	Shared<dxe::Texture> texture_battle_;
	Shared<dxe::Texture> texture_face_;


};