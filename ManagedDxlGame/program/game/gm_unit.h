#pragma once

//memo
//Board上に置かれるUnitの基底クラス

//Unitがどのタイプかを表す
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

	//[0]~[9]の10x10マス盤面上の座標
	//盤面の左上頂点座標起点,row*col
	//この座標を元に、Unitが所持するObjのposが変更
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

	//Unit共通の状態
	bool is_dead_ = false;
	bool is_acted_ = false;
	bool is_turn_ = false;

};