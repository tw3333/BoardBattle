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

	//[0]~[9]��10x10�}�X�Ֆʏ�̍��W
	//�Ֆʂ̍��㒸�_���W�N�_,row*col
	//���̍��W�����ɁAUnit����������Obj��pos���ύX
	struct BoardPos {
		int row;
		int col;
	};

	Type type_ = Type::None;
	void setType(Type type) { type_ = type; }

private:

	//BoardPos board_pos_;

protected:

	Type unit_type_;
	BoardPos board_pos_;


};