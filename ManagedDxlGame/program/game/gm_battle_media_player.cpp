#include "gm_battle_media_player.h"

#include "gm_card_target.h"
#include "gm_data_card.h"
#include "gm_card.h"
#include "gm_sound_manager.h"

void BattleMediaPlayer::Update(float delta_time) {

	if (!anim_.empty()) {

		is_media_playing_ = false;

		for (auto& anim : anim_) {
			anim->Update(delta_time);

			if (anim->getCurrentAnimSeekUnit()->GetIsPlaying()) {
				is_media_playing_ = true;
			}
		}
	}
	
	if (obj_battle_state_anim_) {
		is_battle_state_media_playing_ = false;

		obj_battle_state_anim_->Update(delta_time);

		if (obj_battle_state_anim_->getCurrentAnimSeekUnit()->GetIsPlaying()) {
			is_battle_state_media_playing_ = true;
		}
	}
	
	if (obj_battle_state_icon_) {
		obj_battle_state_icon_->Update(delta_time);
	}

	if (battle_state_anim_timer_start_) {
		timer_ += delta_time;
		is_battle_state_media_playing_ = true;
	}

	if (timer_ >= battle_state_anim_total_time_) {
		timer_ = 0.0f;
		battle_state_anim_timer_start_ = false;
		obj_battle_state_icon_->SetIsRender(false);
		is_battle_state_media_playing_ = false;
	}


}

void BattleMediaPlayer::Render(dxe::Camera* camera) {

	if (!anim_.empty()) {
		for (auto& anim : anim_) {
			anim->Render(camera);

		}
	}

	if (obj_battle_state_anim_) {
		obj_battle_state_anim_->Render(camera);
	}

	if (obj_battle_state_icon_) {
		obj_battle_state_icon_->Render(camera);
	}

	//DrawStringEx(0,350,-1,"battle_state_timer[%f]",timer_);

}

void BattleMediaPlayer::SetAnim(dxe::Camera* camera, std::vector<std::shared_ptr<AnimSprite3D>> anim) {

	anim_ = anim;

	if (!anim_.empty()) {
		for (auto & anim : anim_) {
			anim->SetBillBoardCamera(camera);
			anim->setCurrentAnim("none");
		}
	}

}

void BattleMediaPlayer::SetObjBattleStateAnim(dxe::Camera* camera, std::shared_ptr<AnimSprite3D> obj_battle_state_anim) {

	obj_battle_state_anim_ = obj_battle_state_anim;
	
	if (obj_battle_state_anim_) {
		obj_battle_state_anim_->SetBillBoardCamera(camera);
		obj_battle_state_anim_->setCurrentAnim("none");
	}


}

void BattleMediaPlayer::CardMediaPlay(std::shared_ptr<Card> card) {

	//Anim
	int anim_cnt = 0;
	for (auto &target : card->GetCardData()->GetCardTargetList()) {

		for (int i = 0; i < target->GetTargetSquaresPos().size(); ++i) {
			
			anim_[anim_cnt]->SetObjPosToSquarePos(target->GetTargetSquaresPos()[anim_cnt].row, target->GetTargetSquaresPos()[anim_cnt].col);
			anim_[anim_cnt]->CardAnimPlay(card->GetCardData()->GetCardAnimName());

			//DrawStringEx(0,300,-1,"playtime:%f",anim_[anim_cnt]->GetPlayTime());

			anim_cnt++;
		}

	}

	//SE
	sound_mgr_.PlayCardSE(card->GetCardData()->GetCardID());
	
	//DrawStringEx(0, 400, -1, "debug_メディア関数実行");

}

void BattleMediaPlayer::BattleStateMediaPlay(Unit* unit, State state) {

	battle_state_anim_timer_start_ = true;
	is_battle_state_media_played_ = true;

	//Noneの場合再生しない
	if (state == State::None) {
		return;
	}


	if (state == State::Blood) {

		obj_battle_state_anim_->SetObjPosToSquarePos(unit->GetUnitSquarePos().row, unit->GetUnitSquarePos().col);
		obj_battle_state_icon_->SetObjPosToSquarePos(unit->GetUnitSquarePos().row, unit->GetUnitSquarePos().col);
		obj_battle_state_icon_->SetIconTextute(BattleStateIconGraph::Blood);
		obj_battle_state_icon_->SetIsRender(true);

		obj_battle_state_anim_->CardAnimPlay("anim_blood");
		sound_mgr_.PlayBattleStateSE(state);
	}
	else if (state == State::Stun) {

		obj_battle_state_anim_->SetObjPosToSquarePos(unit->GetUnitSquarePos().row, unit->GetUnitSquarePos().col);
		obj_battle_state_icon_->SetObjPosToSquarePos(unit->GetUnitSquarePos().row, unit->GetUnitSquarePos().col);
		obj_battle_state_icon_->SetIconTextute(BattleStateIconGraph::Stun);
		obj_battle_state_icon_->SetIsRender(true);

		obj_battle_state_anim_->CardAnimPlay("anim_debuff");
		sound_mgr_.PlayBattleStateSE(state);
	}
	else if (state == State::Snare) {

		obj_battle_state_anim_->SetObjPosToSquarePos(unit->GetUnitSquarePos().row, unit->GetUnitSquarePos().col);
		obj_battle_state_icon_->SetObjPosToSquarePos(unit->GetUnitSquarePos().row, unit->GetUnitSquarePos().col);
		obj_battle_state_icon_->SetIconTextute(BattleStateIconGraph::Snare);
		obj_battle_state_icon_->SetIsRender(true);


		obj_battle_state_anim_->CardAnimPlay("anim_debuff");
		sound_mgr_.PlayBattleStateSE(state);
	}


}

bool BattleMediaPlayer::BattleStateMediaTimer(float delta_time) {

	if (battle_state_anim_timer_start_) {
		timer_ += delta_time;
		is_battle_state_media_playing_ = true;
	}

	if (timer_ >= battle_state_anim_total_time_) {
		timer_ = 0.0f;
		battle_state_anim_timer_start_ = false;
		obj_battle_state_icon_->SetIsRender(false);
		is_battle_state_media_playing_ = false;
		is_battle_state_media_played_ = true;

		return true;
	}

	return false;
}




//memo
	//for (auto square : card->GetCardData()->GetCardTargetList()) {

	//	if (square->GetTargetSquaresPos().empty()) {
	//		DrawStringEx(0,420,-1,"TargetSquareが空ですよ！");
	//	}

	//}

	//for (int i = 0; i < 5; ++i) {

	//	anim_[i]->SetObjPosToSquarePos(i, i);

	//	//anim_[i]->CardAnimPlay(card->GetCardData()->GetCardAnimName());
	//	anim_[i]->CardAnimPlay("anim_attack");

	//}