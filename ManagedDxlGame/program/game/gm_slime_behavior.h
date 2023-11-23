#pragma once
#include "gm_enemy_behavior.h"
#include <random>
#include <chrono>
#include <iostream>
#include "gm_data_board.h"

#include "gm_sound_manager.h"
#include "gm_anim_manager.h"


// グローバルな乱数生成器
static std::mt19937 s_rng(std::chrono::steady_clock::now().time_since_epoch().count());

class SlimeBehavior : public EnemyBehavior {
public:

	SlimeBehavior(){}
	~SlimeBehavior(){}

	void Move(UnitEnemy* turn_enemy, Board* board) override;
	void Act(UnitEnemy* turn_enemy, Board* board) override;
	
	bool IsAllyAdjacent(UnitEnemy* turn_enemy, Board* board);
	std::vector<SquarePos> GetActRangePos(UnitEnemy* turn_enemy);
	std::pair<SquarePos, std::vector<SquarePos>> GetBestMoveAlongPath(SquarePos start_pos, const std::vector<SquarePos>& targetPositions, Board* board, int move_cost);

private:

	//Move用変数
	SquarePos final_pos_;
	SquarePos target_pos_;
	SquarePos current_pos_;
	std::vector<SquarePos> move_route_;

	SoundManager& sound_mgr_ = SoundManager::GetInstance();
	AnimManager& anim_mgr_ = AnimManager::GetInstance();
};