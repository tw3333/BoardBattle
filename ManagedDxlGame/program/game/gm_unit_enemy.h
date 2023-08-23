#pragma once
#include "gm_unit.h"
#include "../dxlib_ext/dxlib_ext.h"
#include "gm_data_enemy.h"
#include "gm_object_enemy.h"
#include "gm_enemydata_manager.h"


//#include <memory>
class Board;
class EnemyBehaviorStrategy;
class SlimeBehaviorStrategy;


class UnitEnemy : public Unit {
public:

	UnitEnemy(EnemyData* enemy_data, int row, int col)
	{
		enemy_data_ = enemy_data;
	
		max_hp_ = enemy_data->GetHp();
		current_hp_ = max_hp_;

		max_move_cost_ = enemy_data->GetMoveCost();
		current_move_cost_ = max_move_cost_;

		max_action_cost_ = enemy_data->GetActionCost();
		current_action_cost_ = max_action_cost_;

		speed_ = enemy_data->GetSpeed();

		obj_ = enemy_data->GetObj();

		//SetBoardPos(row, col);
		SetUnitSquarePos(row,col);
		InitEnemyObjPos();

		obj_->Update(0);

	}
	~UnitEnemy(){}


	void Update();

	void InitEnemyObjPos();
	void SetBoardPos(int row, int col);

	UnitType GetUnitType() const override { return UnitType::Enemy; }
	EnemyData* GetEnemyData() { return enemy_data_; }
	ObjEnemy* GetObj() { return obj_; }

	enum class MoveType {
		NotMove, //不動
		RandomMove, //コスト分ランダムに動く
		ForcusMove //taunt値が高いAllyに向かって動く
	};
	MoveType GetMoveType() { return move_type_; }
	MoveType SetMoveType(MoveType type) { move_type_ = type; }

	int GetMaxHp() { return max_hp_; }
	int GetMaxMoveCost() { return max_move_cost_; }
	int GetMaxActionCost() { return max_action_cost_; }

	int GetCurrentHp() { return current_hp_; }
	void SetCurrentHp(int hp) { current_hp_ = hp; }
	int GetCurrentMoveCost() { return current_move_cost_; }
	void SetCurrentMoveCost(int cost) { current_move_cost_ = cost; }
	int GetCurrentActionCost() { return current_action_cost_; }
	void GetCurrentActionCost(int cost) { current_action_cost_ = cost; }
	int GetCurrentDamage() { return current_damage_; }
	void SetCurrentDamage(int damage) { current_damage_ = damage; }

	//BehaviorStrategy
	void SetBehavior(EnemyBehaviorStrategy* newBehavior) {
		behavior_ = newBehavior;
	}

	void Move(Board* board);
	void Act(Board* board);

	void DecreaseCurrentHp(int value) {
		current_hp_ = (std::max)(0, current_hp_ - value);
	}

private:
	
	MoveType move_type_ = MoveType::NotMove;


	EnemyData* enemy_data_ = nullptr;
	ObjEnemy* obj_ = nullptr;
	

	EnemyBehaviorStrategy* behavior_ = nullptr;

	//ステータス
	int max_hp_;
	int current_hp_;

	int max_move_cost_;
	int current_move_cost_;

	int max_action_cost_;
	int current_action_cost_;

	int max_damage_ = 8;
	int current_damage_ = 8;

};