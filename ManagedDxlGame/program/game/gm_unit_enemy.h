#pragma once
#include "gm_unit.h"
#include "../dxlib_ext/dxlib_ext.h"
#include "gm_data_enemy.h"
#include "gm_object_enemy.h"
#include "gm_enemydata_manager.h"


#include <memory>

class Board;
class EnemyBehaviorStrategy;
class SlimeBehaviorStrategy;


class UnitEnemy : public Unit {
public:


	//座標指定なしコンストラクタ
	UnitEnemy(std::shared_ptr<EnemyData> enemydata) {
		enemy_data_ = enemydata;
		//hp
		max_hp_ = enemydata->GetHp();
		current_hp_ = max_hp_;
		//move_cost
		max_move_cost_ = enemydata->GetMoveCost();
		current_move_cost_ = max_move_cost_;
		//action_cost
		max_action_cost_ = enemydata->GetActionCost();
		current_action_cost_ = max_action_cost_;
		//power
		init_power_ = enemydata->GetPower();
		current_power_ = init_power_;
		//speed
		speed_ = enemydata->GetSpeed();
	}

	~UnitEnemy(){}


	void Update(float delta_time) override;
	void Render(dxe::Camera* camera) override;

	void InitEnemyObjPos();


	UnitType GetUnitType() const override { return UnitType::Enemy; }
	std::shared_ptr<EnemyData> GetEnemyData() { return enemy_data_; }

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
	int GetInitPower() { return init_power_; }

	int GetCurrentHp() { return current_hp_; }
	void SetCurrentHp(int hp) { current_hp_ = hp; }

	int GetCurrentMoveCost() { return current_move_cost_; }
	void SetCurrentMoveCost(int cost) { current_move_cost_ = cost; }

	int GetCurrentActionCost() { return current_action_cost_; }
	void GetCurrentActionCost(int cost) { current_action_cost_ = cost; }

	int GetCurrentPower() { return current_power_; }

	//BehaviorStrategy

	void Move(Board* board);
	void Act(Board* board);

	void DecreaseCurrentHp(int value) {
		current_hp_ = (std::max)(0, current_hp_ - value);
	}
	void DecreaseDirectCurrentHp(int value) { 
		current_hp_ = (std::max)(0, current_hp_ - value);
	}
	void IncreareCurrentHp(int value) {
		current_hp_ = (std::min)(max_hp_, current_hp_ + value);
	}



	int GetShieldValue() { return shield_value_; }

	bool GetIsMoved() { return is_moved_; }
	void SetIsMoved(bool is_moved) { is_moved_ = is_moved; }
	bool GetIsEnemyActed() { return is_enemy_acted_; }
	void SetIsEnemyActed(bool is_enemy_acted) { is_enemy_acted_ = is_enemy_acted; }


private:
	
	MoveType move_type_ = MoveType::NotMove;

	std::shared_ptr<EnemyData> enemy_data_ = nullptr; 

	//ステータス
	//move_cost
	int max_move_cost_ = 0;
	int current_move_cost_ = 0;
	//action_cost
	int max_action_cost_ = 0;
	int current_action_cost_ = 0;
	//power
	int init_power_ = 0;
	int current_power_ = 0;

	//Enemy特有のフラグ
	bool is_moved_ = false;
	bool is_enemy_acted_ = false;

};