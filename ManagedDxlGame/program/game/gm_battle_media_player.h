#pragma once

#include <memory>

#include "../dxlib_ext/dxlib_ext.h"
#include "gm_card.h"
#include "gm_anim_manager.h"
#include "gm_sound_manager.h"
#include "gm_card_play.h"

class BattleMediaPlayer {
public:

	BattleMediaPlayer() {}
	~BattleMediaPlayer() {}

	void Update(float delta_time);
	void Render(dxe::Camera* camera);

	
	void SetAnim(dxe::Camera* camera, std::vector<std::shared_ptr<AnimSprite3D>> anim);
	void CardMediaPlay(std::shared_ptr<Card> card);

	bool GetIsMediaPlaying() { return is_media_playing_; }
	


private:

	dxe::Camera* camera_ = nullptr;

	bool is_media_playing_ = false;

	SoundManager& sound_mgr_ = SoundManager::GetInstance();
	AnimManager& anim_mgr_ = AnimManager::GetInstance();

	std::vector<std::shared_ptr<AnimSprite3D>> anim_;


};