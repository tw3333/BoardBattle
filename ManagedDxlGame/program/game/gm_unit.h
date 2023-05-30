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

	//[0]~[9]の10x10マス盤面上の座標
	//盤面の左上頂点座標起点,row*col
	//この座標を元に、Unitが所持するObjのposが変更
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