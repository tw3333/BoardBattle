#include "gm_battle_media_player.h"

#include "gm_card_target.h"
#include "gm_sound_manager.h"

void BattleMediaPlayer::Update(float delta_time) {

	if (!anim_.empty()) {

		for (auto& anim : anim_) {
			anim->Update(delta_time);
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

	for (auto &target : card->GetCardData()->GetCardTargetList()) {

		for (int i = 0; i < target->GetTargetSquaresPos().size(); ++i) {
			
			anim_[i]->SetObjPosToSquarePos(target->GetTargetSquaresPos()[i].row, target->GetTargetSquaresPos()[i].col);
			
			anim_[i]->CardAnimPlay(card->GetCardData()->GetCardAnimName());
			//anim_[i]->CardAnimPlay(s);

		}

	}

	//sound_mgr_.PlayCardSE(1);

	DrawStringEx(0, 400, -1, "debug_メディア関数実行");

}


