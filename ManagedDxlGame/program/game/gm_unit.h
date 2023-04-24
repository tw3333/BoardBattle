#pragma once

//memo
//Boardã‚É’u‚©‚ê‚éUnit‚ÌŠî’êƒNƒ‰ƒX



class Unit {
public:

	virtual ~Unit(){}

	enum class Type {
		None,
		Ally,
		Enemy,
		Obstacle
	};

private:

	Type type_ = Type::None;

};