#pragma once
#include <array>
#include <vector>
#include <memory>
#include "gm_square.h"
#include "../dxlib_ext/dxlib_ext.h"
#include "gm_object_manager.h"

#include "gm_select_square.h"

#include "gm_unit.h"
#include "gm_unit_ally.h"
#include "gm_unit_enemy.h"


//memo
//SceneBattleの盤面上を管理するクラス
//1マス(Squareクラス)をここで生成

//ToDo
//ここでステージ毎のマス目や敵の生成を管理？


class Board {
public:

	Board(){
		Create();
		select_square_ = new SelectSquare(board_squares_);
	}
	~Board(){}

	void Create();
	void Update(float delta_time);
	void Render(dxe::Camera* camera);

	std::array<std::array<Square*, 10>, 10> getBoardSquares() { return board_squares_;}
	void SetCamera(dxe::Camera* camera) { camera_ = camera; }

	void GetMouseOverSquarePos(int& row, int& col) { 
		row = select_square_->GetSelectSquareRow();
		col = select_square_->GetSelectSquareCol();
	}

	void UpdateCanMoveSquare();
	void SetParty(UnitAlly* party[3]) { std::copy(party, party + 3, party_); }

private:

	UnitAlly* party_[3];
	std::vector<UnitEnemy*> enemies_;


	ObjectManager& omgr_ = ObjectManager::GetInstance();

	std::array<std::array<Square*, 10>, 10> board_squares_;//10x10のマス配列

	SelectSquare* select_square_ = nullptr;

	dxe::Camera* camera_; //select_squareのレイ計算用

	int w1 = DXE_WINDOW_WIDTH / 10;
	int h1 = DXE_WINDOW_HEIGHT / 10;

	//ColorCode
	int gray_ = GetColor(128, 128, 128);

};