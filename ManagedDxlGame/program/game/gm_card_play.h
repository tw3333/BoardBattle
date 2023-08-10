#pragma once
#include <memory>
#include <vector>

#include "gm_card.h"

#include "gm_card_effect.h"
#include "gm_card_range.h"

#include "gm_unit.h"
#include "gm_unit_ally.h"
#include "gm_unit_enemy.h"

#include "gm_anim_manager.h"
#include "gm_sound_manager.h"

class UICard;

//射程の表示、効果の発動、SEの再生、Animの再生をこのクラスで行う

class CardPlay {
public:

	CardPlay() {}
	~CardPlay() {}


	void Update(float delta_time);
	void Render(dxe::Camera* camera);

	void RenderSelectCardRange(UnitAlly* turn_ally, Board* board);
	void UpdateSelectCardGetUnitInRange(UnitAlly* turn_ally, std::vector<Unit*> all_untis);

	void DebugRender();

	void EffectExecute();


	void SetSelectCard(std::shared_ptr<Card> card) { select_card_ = card; }
	void SetCard(Card* card) { play_card_ = card; }
	void SetTurnAlly(UnitAlly* turn_ally) { turn_ally_ = turn_ally; }

	void SetSelectUICard(UICard* uicard) { select_uicard_ = uicard; }
	void SetAllyHand(std::vector<std::shared_ptr<Card>> ally_hand) { ally_hand_ = ally_hand; }

	void SetCameraToCardEffectAnim(dxe::Camera* camera);

private:

	bool is_target_num_box_render_ = false;

	std::shared_ptr<Card> select_card_ = nullptr;
	UnitAlly* turn_ally_ = nullptr;

	UICard* select_uicard_ = nullptr;
	

	std::vector<std::shared_ptr<Card>> ally_hand_;
	std::vector<Unit*> total_units_in_range_;




	Card* play_card_ = nullptr;

	AnimManager& anim_manager_ = AnimManager::GetInstance();
	SoundManager& sound_manager_ = SoundManager::GetInstance();

	std::vector<std::shared_ptr<AnimSprite3D>> card_effect_anim_ = anim_manager_.GetDebugAnimList();

	
};