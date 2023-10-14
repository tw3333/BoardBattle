#pragma once
#include <iostream>

//êÌì¨Ç…égÇ§èÛë‘Ç»Ç«

enum class State {
	Blood,
	Poison,
	Snare,
	Stun,
	AddMoveCost,
	AddCardCost,
	None
};



class BattleState {
public:

	BattleState(State state,int value = 0, int turn_count = 0) {
		state_ = state;
		value_ = value;
		turn_count_ = turn_count;
	}

	~BattleState(){}

	void AddValue(int add_value) { value_ += add_value; }
	void DecreaseValue(int value) { value_ = (std::max)(0, value_ - value); }
	void SetValue(int value) { value_ = value; }
	
	void AddTrunCount(int cnt) { turn_count_ += cnt; }
	void DecreaseTurnCount(int cnt) { turn_count_ = (std::max)(0, turn_count_ - cnt); }
	void SetTurnCount(int turn_count) { turn_count_ = turn_count; }

	State GetState() { return state_; }

	int GetValue() { return value_; }
	int GetTurnCount() { return turn_count_; }

	bool &GetIsProc() { return is_proc_; }
	void SetIsProc(bool is_proc) { is_proc_ = is_proc; }
	bool GetIsAddTurn() { return add_turn_; }
	void SetIsAddTurn(bool add_turn) { add_turn_ = add_turn; }

private:

	bool is_proc_ = false;
	bool add_turn_ = true;


	State state_ = State::None;

	int turn_count_ = 0;
	int value_ = 0;



};