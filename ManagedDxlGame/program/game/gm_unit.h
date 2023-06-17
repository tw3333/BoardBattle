#pragma once

//memo
//Board��ɒu�����Unit�̊��N���X

//Unit���ǂ̃^�C�v����\��
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

	//[0]~[9]��10x10�}�X�Ֆʏ�̍��W
	//�Ֆʂ̍��㒸�_���W�N�_,row*col
	//���̍��W�����ɁAUnit����������Obj��pos���ύX
	struct BoardPos {
		int row;
		int col;
	};


	//UnitType unit_type_ = Unit::UnitType::None;
	
	//void setType(Type type) { type_ = type; }
	bool GetIsDead() { return is_dead_; }
	bool GetIsActed() { return is_acted_; }
	bool GetIsTurn() { return is_turn_; }
	int GetSpeed() { return speed_; }

	void SetIsDead(bool flag) { is_dead_ = flag; }
	void SetIsActed(bool flag) { is_acted_ = flag; }
	void SetIsTurn(bool flag) { is_turn_ = flag; }
	
	void SetBoardPos(int row, int col) { board_pos_.row = row; board_pos_.col = col; }
	BoardPos GetBoardPos() { return board_pos_; }

private:


protected:

	
	BoardPos board_pos_;
	UnitType unit_type = UnitType::None;
	int speed_ = 0;

	//Unit���ʂ̏��
	bool is_dead_ = false;
	bool is_acted_ = false;
	bool is_turn_ = false;

};