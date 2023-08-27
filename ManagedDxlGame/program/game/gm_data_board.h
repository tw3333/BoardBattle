#pragma once

//SceneBattleで使用するBoardに関するまとめたクラス

struct BoardPos
{
	int row = 0;
	int col = 0;

};


//[0]~[9]の10x10マス盤面上の座標
//盤面の左上頂点座標起点,row*col
struct SquarePos {
	
	SquarePos(int r, int c) : row(r), col(c) {}
	
	int row = 0;
	int col = 0;

	bool operator==(const SquarePos& other) const {
		return row == other.row && col == other.col;
	}

};

