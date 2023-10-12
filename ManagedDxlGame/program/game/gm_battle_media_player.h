#pragma once

#include <memory>

#include "../dxlib_ext/dxlib_ext.h"
#include "gm_card.h"
#include "gm_data_battle_state.h"
#include "gm_anim_manager.h"
#include "gm_sound_manager.h"
#include "gm_card_play.h"
#include "gm_object_battle_state_icon.h"

#include "gm_unit.h"

class BattleMediaPlayer {
public:

	BattleMediaPlayer() {}
	~BattleMediaPlayer() {}

	void Update(float delta_time);
	void Render(dxe::Camera* camera);

	bool GetIsMediaPlaying() { return is_media_playing_; }
	bool GetIsBattleStateMediaPlaying() { return is_battle_state_media_playing_; }
	
	void SetAnim(dxe::Camera* camera, std::vector<std::shared_ptr<AnimSprite3D>> anim);
	void SetObjBattleStateIcon(std::shared_ptr<ObjBattleStateIcon> obj_battle_state_icon) { obj_battle_state_icon_ = obj_battle_state_icon; }
	void SetObjBattleStateAnim(dxe::Camera* camera, std::shared_ptr<AnimSprite3D> obj_battle_state_anim);

	void CardMediaPlay(std::shared_ptr<Card> card);

	void BattleStateMediaPlay(Unit* unit, State state);

	State GetAnimBattleState(){ return anim_battle_state_; }
	void SetAnimBattleState(State state) { anim_battle_state_ = state; }
	bool GetIsBattleStateMediaPlayed() { return is_battle_state_media_played_; }
	void SetIsBattleStateMediaPlayed(bool is_played) { is_battle_state_media_played_ = is_played; }

	bool BattleStateMediaTimer(float delta_time);


	bool test_ = false;
	float test_timer_ = 0.0f;

private:

	float timer_ = 0.0f;
	float battle_state_anim_total_time_ = 1.0f;
	bool battle_state_anim_timer_start_ = false;



	State anim_battle_state_ = State::None; //çƒê∂Ç∑ÇÈBattleStateÇÃéÌóﬁ

	SoundManager& sound_mgr_ = SoundManager::GetInstance();
	AnimManager& anim_mgr_ = AnimManager::GetInstance();
	ObjectManager& obj_mgr_ = ObjectManager::GetInstance();

	dxe::Camera* camera_ = nullptr;

	bool is_media_playing_ = false;
	bool is_battle_state_media_playing_ = false;
	bool is_battle_state_media_played_ = false;
	


	std::vector<std::shared_ptr<AnimSprite3D>> anim_;


	std::shared_ptr<ObjBattleStateIcon> obj_battle_state_icon_ = nullptr;
	std::shared_ptr<AnimSprite3D> obj_battle_state_anim_ = nullptr;


};