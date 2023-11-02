#pragma once
#include "gm_data_board.h"
#include <random>
#include <chrono>
#include <iostream>

//memo
//UnitEnemyの各行動の基底クラス
class Board;
class UnitEnemy;
class UnitAlly;

//BFSで使う構造体
struct BFSNode {
	SquarePos pos;
	SquarePos prev_pos; // 一つ前のノード（経路の復元のため）
	int cost; // このノードに到達するためのコスト
	BFSNode(SquarePos pos, SquarePos prev, int _cost) : pos(pos), prev_pos(prev), cost(_cost) {}
};

static std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());


class EnemyBehavior {
public:

	virtual void Move(UnitEnemy* turn_enemy, Board* board) = 0;
	virtual void Act(UnitEnemy* turn_enemy, Board* board) = 0;
	
	//Behaviorクラスで使う凡庸的な関数
	UnitAlly* GetNearestAlly(UnitEnemy* turn_enemy, Board* board); //一番近い味方のユニットを返す
	UnitAlly* ExtractMostTauntAlly(std::vector<UnitAlly*> allies); //渡したUnitAllyの配列の高い味方のユニットを返す



};