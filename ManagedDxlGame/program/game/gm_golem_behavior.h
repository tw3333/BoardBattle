#pragma once
#include "gm_enemy_behavior.h"

#include "gm_sound_manager.h"
#include "gm_anim_manager.h"

class GolemBehavior : public EnemyBehavior {
public:

	GolemBehavior() {}
	~GolemBehavior() {}

	void Move(UnitEnemy* turn_enemy, Board* board) override;
	void Act(UnitEnemy* turn_enemy, Board* board) override;


private:


	//Move—p•Ï”
	SquarePos final_pos_;
	SquarePos target_pos_;
	SquarePos current_pos_;
	std::vector<SquarePos> move_route_;

	SoundManager& sound_mgr_ = SoundManager::GetInstance();
	AnimManager& anim_mgr_ = AnimManager::GetInstance();

};
