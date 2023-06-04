#pragma once
#include "gm_square.h"

//memo
//SceneBattleの盤面を管理する


class BoardManager {
public:

	BoardManager(){}
	~BoardManager(){}

	void Update(float delta_time);
	

	//アクセッサー
	void SetBoardSquares(Square* board_squares[10][10]) {
		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < 10; ++j) {

				board_squares_[i][j] = board_squares[i][j];

			}
		}
	};





private:

	Square* board_squares_[10][10];


	

};