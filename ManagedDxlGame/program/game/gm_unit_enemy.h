#pragma once
#include "gm_unit.h"
#include "../dxlib_ext/dxlib_ext.h"
#include "gm_data_enemy.h"
#include "gm_object_enemy.h"
#include "gm_enemydata_manager.h"
#include "gm_object_manager.h"

class UnitEnemy : public Unit {
public:

	UnitEnemy(int id, EnemyData* enemy_data, int row, int col){
	
		enemy_data_ = enemy_data;

		ObjectManager& instance_ = ObjectManager::GetInstance();
		obj_ = instance_.GetObjEnemyAtID(id);
		SetBoardPos(row, col);
	
		max_hp_ = enemy_data->GetHp();
		current_hp_ = max_hp_;

		max_move_cost_ = enemy_data->GetMoveCost();
		current_move_cost_ = max_move_cost_;

		max_action_cost_ = enemy_data->GetActionCost();
		current_action_cost_ = max_action_cost_;

		speed_ = enemy_data->GetSpeed();


	}
	~UnitEnemy(){}


	void Update();

	void SetBoardPos(int row, int col);

	UnitType GetUnitType() const override { return UnitType::Enemy; }
	ObjEnemy* GetObj() { return obj_; }

	enum class MoveType {
		NotMove, //不動
		RandomMove, //コスト分ランダムに動く
		ForcusMove //taunt値が高いAllyに向かって動く
	};
	MoveType GetMoveType() { return move_type_; }
	MoveType SetMoveType(MoveType type) { move_type_ = type; }

	int GetMaxHp() { return max_hp_; }
	
	int GetCurrentHp() { return current_hp_; }
	void SetCurrentHp(int hp) { current_hp_ = hp; }


private:
	
	MoveType move_type_ = MoveType::NotMove;


	EnemyData* enemy_data_ = nullptr;
	ObjEnemy* obj_ = nullptr;

	

	//ステータス
	int max_hp_;
	int current_hp_;

	int max_move_cost_;
	int current_move_cost_;

	int max_action_cost_;
	int current_action_cost_;

	

};