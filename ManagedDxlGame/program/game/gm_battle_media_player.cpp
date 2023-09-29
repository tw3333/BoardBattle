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


}

void BattleMediaPlayer::Render(dxe::Camera* camera) {

	if (!anim_.empty()) {
		for (auto& anim : anim_) {
			anim->Render(camera);
		}
	}

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

void BattleMediaPlayer::CardMediaPlay(std::shared_ptr<Card> card) {

	//Anim
	int anim_cnt = 0;
	for (auto &target : card->GetCardData()->GetCardTargetList()) {

		for (int i = 0; i < target->GetTargetSquaresPos().size(); ++i) {
			
			anim_[anim_cnt]->SetObjPosToSquarePos(target->GetTargetSquaresPos()[anim_cnt].row, target->GetTargetSquaresPos()[anim_cnt].col);
			anim_[anim_cnt]->CardAnimPlay(card->GetCardData()->GetCardAnimName());

			anim_cnt++;
		}

	}

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

	//SE
	sound_mgr_.PlayCardSE(1);
	
	DrawStringEx(0, 400, -1, "debug_メディア関数実行");

}


