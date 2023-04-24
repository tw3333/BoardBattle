#pragma once

//memo
//Board上に置かれるUnitの基底クラス



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