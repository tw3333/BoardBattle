#pragma once
#include <string>

#include "gm_data_battle_state.h"


//シングルトン

class BattleStateConfig {
public:
	
	static BattleStateConfig& GetInstance() {
		static BattleStateConfig instance;
		return instance;
	}

	//コピーコンストラクタ削除
	BattleStateConfig(const BattleStateConfig&) = delete;
	BattleStateConfig& operator=(const BattleStateConfig&) = delete;
	//ムーブコンストラクタ削除
	BattleStateConfig(BattleStateConfig&&) = delete;
	BattleStateConfig& operator = (BattleStateConfig&&) = delete;


	void LoadBattleStateConfigFromCSV(const std::string& filepath);
	int const GetBattleStateInitTurnCount(State state);
	int const GetBattleStateInitValueNum(State state);


private:

	BattleStateConfig() = default;
	~BattleStateConfig() = default;


	//初期ターンカウント
	int init_blood_turn_count_ = 0;
	int init_poison_turn_count_ = 0;
	int init_shield_turn_count_ = 0;
	int init_weak_turn_count_ = 0;
	int init_snare_turn_count_ = 0;
	int init_stun_turn_count_ = 0;
	int init_counter_turn_count_ = 0;
	int init_stand_turn_count_ = 0;
	int init_blood_turn_count_ = 0;

	//初期数値
	int init_blood_value_ = 0;
	int init_poison_value_ = 0;
	int init_shield_value_ = 0;
	int init_weak_value_ = 0;
	int init_snare_value_ = 0;
	int init_stun_value_ = 0;
	int init_counter_value_ = 0;
	int init_stand_value_ = 0;





};