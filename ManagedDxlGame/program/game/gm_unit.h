#pragma once

//memo
//Board��ɒu�����Unit�̊��N���X



class Unit {
public:

	virtual ~Unit(){}

	

protected:

	enum class Type {
		None,
		Ally,
		Enemy,
		Obstacle
	};

	Type type_ = Type::None;
	void setType(Type type) { type_ = type; }

};