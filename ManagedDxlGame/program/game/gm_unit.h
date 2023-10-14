#pragma once
#include <memory>

#include "gm_data_board.h"
#include "gm_data_battle_state.h"
#include "gm_object.h"

//memo
//Board上に置かれるUnitの基底クラス

//Unitがどのタイプかを表す
enum class UnitType {
	None,
	Ally,
	Enemy,
	Obstacle
};

class Unit {
public:

	virtual ~Unit(){}

	virtual UnitType GetUnitType() const = 0;
	virtual void Update(float delta_time) = 0;

	//UnitType unit_type_ = Unit::UnitType::None;
	
	//void setType(Type type) { type_ = type; }
	bool GetIsDead() { return is_dead_; }
	bool GetIsActed() { return is_acted_; }
	bool GetIsTurn() { return is_turn_; }
	int GetSpeed() { return speed_; }

	void SetIsDead(bool flag) { is_dead_ = flag; }
	void SetIsActed(bool flag) { is_acted_ = flag; }
	void SetIsTurn(bool flag) { is_turn_ = flag; }
	

	void SetUnitSquarePos(int row, int col) { unit_square_pos_.row = row; unit_square_pos_.col = col; }
	SquarePos GetUnitSquarePos() { return unit_square_pos_; }

	//std::shared_ptr<GameObject> GetUnitObj() { return unit_obj_; }
	GameObject* GetUnitObj() { return unit_obj_; }
	std::vector<BattleState>& GetBattleState() { return state_; }
	void AddBattleState(BattleState state) { state_.emplace_back(state); }

	void DecreaseShieldValue(int value) { shield_value_ = (std::max)(0, shield_value_ - value); }
	void DecreaseDirectCurrentHp(int value) { current_hp_ = (std::max)(0, current_hp_ - value); }


	void AddShieldValue(int value) { shield_value_ += value; }

	void DecreaseBattleStateTurn();


	bool IsBattleStateAllProcedStartOfTurn();
	void ResetAllBattleStateProced();
	//void DeeleteBattleState

	bool GetIsAllStateProc() { return is_all_state_proced_; }
	void SetIsAllStateProc(bool flag) { is_all_state_proced_ = flag; }

	bool GetIsStunTurn() { return is_stun_turn_; }
	void SetIsStunTurn(bool flag) { is_stun_turn_ = flag; }
	bool GetIsSnareTurn() { return is_snare_turn_; }
	void SetIsSnareTurn(bool flag) { is_snare_turn_ = flag; }
	bool GetIsBlood() { return is_blood_; }
	void SetIsBlood(bool flag) { is_blood_ = flag; }

private:


protected:

	//std::shared_ptr<GameObject> unit_obj_;
	GameObject* unit_obj_;


	SquarePos unit_square_pos_; //盤面上のUnitの位置

	UnitType unit_type = UnitType::None;

	//Unit共通のステータス
	int speed_ = 0;
	int shield_value_ = 0; //シールド値
	int max_hp_ = 0;
	int current_hp_ = 0;
	std::vector<BattleState> state_; //BattleState

	//Unit共通の状態
	bool is_dead_ = false; 
	bool is_acted_ = false;
	bool is_turn_ = false;
	bool is_all_state_proced_ = false;
	bool is_stun_turn_ = false;
	bool is_snare_turn_ = false;
	bool is_blood_ = false;

};