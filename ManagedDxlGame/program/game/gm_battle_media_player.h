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
	
	void SetAnim(dxe::Camera* camera, std::vector<std::shared_ptr<AnimSprite3D>> anim);
	void SetObjBattleStateIcon(std::shared_ptr<ObjBattleStateIcon> obj_battle_state) { obj_battle_state_ = obj_battle_state; }
	void SetObjBattleStateAnim(dxe::Camera* camera, std::shared_ptr<AnimSprite3D> obj_battle_state_anim);

	void CardMediaPlay(std::shared_ptr<Card> card);

	void BattleStateMediaPlay(Unit* unit, State state);

	State GetAnimBattleState(){ return anim_battle_state_; }
	void SetAnimBattleState(State state) { anim_battle_state_ = state; }

private:

	State anim_battle_state_ = State::None; //Ä¶‚·‚éBattleState‚Ìí—Ş

	SoundManager& sound_mgr_ = SoundManager::GetInstance();
	AnimManager& anim_mgr_ = AnimManager::GetInstance();
	ObjectManager& obj_mgr_ = ObjectManager::GetInstance();

	dxe::Camera* camera_ = nullptr;

	bool is_media_playing_ = false;
	bool is_battle_state_media_playing_ = false;


	std::vector<std::shared_ptr<AnimSprite3D>> anim_;
	std::shared_ptr<ObjBattleStateIcon> obj_battle_state_ = nullptr;
	std::shared_ptr<AnimSprite3D> obj_battle_state_anim_ = nullptr;


};