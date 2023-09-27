#pragma once

//SceneBattle�Ŏg�p����Board�Ɋւ���܂Ƃ߂��N���X

struct BoardPos
{
	int row = 0;
	int col = 0;

};


//[0]~[9]��10x10�}�X�Ֆʏ�̍��W
//�Ֆʂ̍��㒸�_���W�N�_,row*col
struct SquarePos {
	
	//SquarePos(int r, int c) : row(r), col(c) {}
	
	int row = 0;
	int col = 0;

	bool operator==(const SquarePos& other) const {
		return row == other.row && col == other.col;
	}

	bool operator<(const SquarePos& other) const {
		if (row < other.row) return true;
		if (row > other.row) return false;
		return col < other.col;
	}

};

