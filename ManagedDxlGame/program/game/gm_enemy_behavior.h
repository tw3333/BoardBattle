#pragma once
#include "gm_data_board.h"
#include <random>
#include <chrono>
#include <iostream>

//memo
//UnitEnemy�̊e�s���̊��N���X
class Board;
class UnitEnemy;
class UnitAlly;

//BFS�Ŏg���\����
struct BFSNode {
	SquarePos pos;
	SquarePos prev_pos; // ��O�̃m�[�h�i�o�H�̕����̂��߁j
	int cost; // ���̃m�[�h�ɓ��B���邽�߂̃R�X�g
	BFSNode(SquarePos pos, SquarePos prev, int _cost) : pos(pos), prev_pos(prev), cost(_cost) {}
};

static std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());


class EnemyBehavior {
public:

	virtual void Move(UnitEnemy* turn_enemy, Board* board) = 0;
	virtual void Act(UnitEnemy* turn_enemy, Board* board) = 0;
	
	//Behavior�N���X�Ŏg���}�f�I�Ȋ֐�
	UnitAlly* GetNearestAlly(UnitEnemy* turn_enemy, Board* board); //��ԋ߂������̃��j�b�g��Ԃ�
	UnitAlly* ExtractMostTauntAlly(std::vector<UnitAlly*> allies); //�n����UnitAlly�̔z��̍��������̃��j�b�g��Ԃ�



};