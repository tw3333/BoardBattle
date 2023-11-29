#pragma once
#include "gm_enemy_behavior.h"

#include "gm_data_board.h"
#include "gm_sound_manager.h"
#include "gm_anim_manager.h"

#include <vector>
#include <random>
#include <chrono>
#include <iostream>

// �O���[�o���ȗ���������
static std::mt19937 a_rng(std::chrono::steady_clock::now().time_since_epoch().count());


class AttackPopoBehavior : public EnemyBehavior {
public:

	AttackPopoBehavior(){}
	~AttackPopoBehavior(){}

	void Move(UnitEnemy* turn_enemy, Board* board) override;
	void Act(UnitEnemy* turn_enemy, Board* board) override;


	bool IsAllyActInRange(UnitEnemy* turn_enemy, Board* board);
	bool IsAllyAdjacent(UnitEnemy* turn_enemy, Board* board);
	int CalDistance(SquarePos pos1, SquarePos pos2) {
		return abs(pos1.row - pos2.row) + abs(pos1.col - pos2.col);
	}

	std::pair<SquarePos, std::vector<SquarePos>> GetBestMoveAlongPath(SquarePos start_pos, const std::vector<SquarePos>& targetPositions, Board* board, int move_cost);

	std::vector<SquarePos> GetOneStepAwaySquares(SquarePos pos, Board* board); //�n�����}�X��1�}�X���ꂽ�ړ��\�ȃ}�X��Ԃ�
	std::vector<SquarePos> GetAllAlliesOneStepAwaySquares(Board* board); //�S�Ă�Ally��1�}�X���ꂽ�ړ��\�ȃ}�X��Ԃ�

private:

	//Move�p�ϐ�
	SquarePos final_pos_;
	SquarePos target_pos_;
	SquarePos current_pos_;
	std::vector<SquarePos> move_route_;

	SoundManager& sound_mgr_ = SoundManager::GetInstance();
	AnimManager& anim_mgr_ = AnimManager::GetInstance();


};