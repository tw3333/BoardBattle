#pragma once

//memo
//Board��ɒu�����Unit�̊��N���X



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