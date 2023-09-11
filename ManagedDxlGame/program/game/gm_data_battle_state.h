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
	void DecreaseTurnCount(int cnt) { turn_count_ = (std::max)(0, turn_count_ - cnt); }
	void DecreaseValue(int value) { value_ = (std::max)(0, value_ - value); }


	State GetState() { return state_; }


private:

	State state_ = State::None;

	int turn_count_ = 0;
	int value_ = 0;


	
};