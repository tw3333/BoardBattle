#pragma once
#include <memory>
#include <vector>

#include "gm_card.h"

#include "gm_card_effect.h"
#include "gm_card_range.h"
#include "gm_card_target.h"

#include "gm_unit.h"
#include "gm_unit_ally.h"
#include "gm_unit_enemy.h"

#include "gm_anim_manager.h"
#include "gm_sound_manager.h"

#include "gm_data_board.h"

class UICard;

//�˒��̕\���A���ʂ̔����ASE�̍Đ��AAnim�̍Đ������̃N���X�ōs��

class CardPlay {
public:

	CardPlay() {}
	~CardPlay() {}


	void Update(float delta_time);
	void Render(dxe::Camera* camera);

	void RenderSelectCardRange(UnitAlly* turn_ally, Board* board);
	void UpdateSelectCardGetUnitInRange(UnitAlly* turn_ally, std::vector<Unit*> all_untis);
	void UpdateSelectCardRangeSquarePos(SquarePos axis_pos);

	

	void DebugRender();

	void EffectExecute();

	void PlayCardExecute(Board* board); //PlayCard�̌��ʎ��s
	bool CanPlayCardExecute(Board* board);

	bool CanPlaySelectCard();

	bool IsSelectCardCostEnough();
	bool IsSelectCardTargetInRange(Board* board);

	std::vector<Unit*> ExtractUnitInRange(TOTARGET to_target); //total_units_in_range_����eUnit�𒊏o����֐�
	std::vector<SquarePos> ExtractTargetSquarePosInRange(TOTARGET to_target, Board* board); 
	int GetInRangeTargetNum(TOTARGET to_target, Board* board); //Range���ɂ���e��Unit�̐���Ԃ��֐�

	void SetSelectCard(std::shared_ptr<Card> card) { select_card_ = card; }
	void SetTurnAlly(UnitAlly* turn_ally) { turn_ally_ = turn_ally; }

	void SetSelectUICard(UICard* uicard) { select_uicard_ = uicard; }
	void SetAllyHand(std::vector<std::shared_ptr<Card>> ally_hand) { ally_hand_ = ally_hand; }

	void SetCameraToCardEffectAnim(dxe::Camera* camera);

	void SetPlayCard(std::shared_ptr<Card> card) { play_card_ = card; }
	std::shared_ptr<Card> GetPlayCard() { return play_card_; }

	std::vector<Unit*> GetTotalUnitsInRange() { return total_units_in_range_; }
	std::vector<Unit*>& GetTargetUnits() { return target_units_; }

	std::shared_ptr<CardTarget> GetCurrentCardTarget() { return current_card_target_; }
	void SetCurrentCardTarget(std::shared_ptr<CardTarget> card_target) { current_card_target_ = card_target; }

	std::vector<SquarePos> GetCardRangeSquarePos() { return card_range_square_pos_; }
	void ResetPlayCardTargetSquarePos(); //PlayCard��Target��SquarePos�����Z�b�g����֐�
	void RemovePlayCardFromHand(); //PlayCard����D����폜����
	

private:

	bool is_target_num_box_render_ = false;

	std::shared_ptr<Card> select_card_ = nullptr;
	std::shared_ptr<Card> play_card_ = nullptr; //���s����Card�̃C���X�^���X
	std::shared_ptr<CardTarget> current_card_target_ = nullptr; //���s����Card��Target�̃C���X�^���X

	UnitAlly* turn_ally_ = nullptr;

	UICard* select_uicard_ = nullptr;


	

	std::vector<std::shared_ptr<Card>> ally_hand_;
	std::vector<Unit*> total_units_in_range_;
	std::vector<Unit*> target_units_;


	std::vector<SquarePos> card_range_square_pos_; //PlayCard�̎˒�SquarePos

	int units_cnt_ = 0;

	


	//Card* play_card_ = nullptr;

	AnimManager& anim_manager_ = AnimManager::GetInstance();
	SoundManager& sound_manager_ = SoundManager::GetInstance();

	std::vector<std::shared_ptr<AnimSprite3D>> card_effect_anim_ = anim_manager_.GetDebugAnimList();

	
};