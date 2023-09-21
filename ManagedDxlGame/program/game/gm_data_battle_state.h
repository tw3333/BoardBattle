#pragma once
#include <iostream>

//í“¬‚Ég‚¤ó‘Ô‚È‚Ç

enum class State {
	Blood,
	Poison,
	Shield,
	Weak,
	Snare,
	Stun,
	Counter,
	Stand,
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


private:

	State state_ = State::None;

	int turn_count_ = 0;
	int value_ = 0;

};