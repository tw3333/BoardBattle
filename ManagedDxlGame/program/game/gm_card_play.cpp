#include "gm_card_play.h"

#include "gm_card.h"
#include "gm_card_effect.h"

#include "gm_card_range.h"
#include "gm_card_range_self.h"

#include "gm_unit.h"
#include "gm_unit_ally.h"
#include "gm_unit_enemy.h"

#include "gm_board.h"
#include "gm_ui_card.h"
#include "../dxlib_ext/dxlib_ext.h"

#include <algorithm>
#include <vector>


void CardPlay::Update(float delta_time) {

	//for (auto a : anim_manager_.GetDebugAnimList()) {

	//	a->Update(delta_time);

	//}

	if (!card_effect_anim_.empty()) {
		for (auto cea : card_effect_anim_) { cea->Update(delta_time); }
	}

	if (select_uicard_) {

		if (tnl::Input::IsMouseTrigger(eMouseTrigger::IN_LEFT)) {

			if (select_uicard_->GetCardPtr()->GetCardData()->GetTargetType() == TargetType::SpecifyTarget) {





			}




		}




	}





}

void CardPlay::Render(dxe::Camera* camera) {

	DebugRender();

	if (!card_effect_anim_.empty()) {
		for (auto cea : card_effect_anim_) { cea->Render(camera); }
	}




}

//選択されているUICardの射程を盤面に表示
void CardPlay::RenderSelectCardRange(UnitAlly* turn_ally, Board* board) {

	if (select_uicard_) {

		for (auto a: select_uicard_->GetCardPtr()->GetCardData()->GetCardRangeList()) {
			a->DisplayRange(turn_ally,board);

		}


		//select_uicard_->GetCardPtr()->GetCardData()->card_range_->DisplayRange(turn_ally, board);
	}
	else if(!select_uicard_) {
		board->ResetRangeTile();
	}



}


//Cardの持つ射程内のUnitを配列に格納
void CardPlay::UpdateSelectCardGetUnitInRange(UnitAlly* turn_ally, std::vector<Unit*> all_units) {

	if (select_uicard_) {

		total_units_in_range_.clear();

		for (auto a : select_uicard_->GetCardPtr()->GetCardData()->GetCardRangeList())
		{
			std::vector<Unit*> unit_in_range = a->GetUnitInRange(turn_ally, all_units);
			total_units_in_range_.insert(total_units_in_range_.end(), unit_in_range.begin(), unit_in_range.end());
		}

		//debugcode
		DrawStringEx(0,600,-1,"対象が%d人います",total_units_in_range_.size());

	}

}

void CardPlay::DebugRender() {

	if (select_uicard_) {

		DrawStringEx(0,650,-1,"このカードは[%d]です",select_uicard_->debug_cnt_);

	}
	else {
		DrawStringEx(0,650,-1,"select_uicard_がnullです");
	}


	for (int i = 0; i < total_units_in_range_.size(); ++i) {


		DrawStringEx(0, 250 + 20 * i, -1, "AnimPosX:%d", anim_manager_.GetDebugAnimList()[i]->pos_.x);


		

	}

}

void CardPlay::EffectExecute()
{
	if (select_uicard_ && turn_ally_) {

		if (tnl::Input::IsMouseTrigger(eMouseTrigger::IN_LEFT)) {

			//どの射程にも誰もいない場合は処理を中断する
			//for (auto a : select_uicard_->GetCardPtr()->GetCardData()->GetCardRangeList()) {

			//	if (a->GetIsUnitInRange() == false) {

			//		//debugcode
			//		DrawStringEx(0, 500, -1, "射程に誰もいないよ！");

			//		return;
			//	}
			//}
			if (total_units_in_range_.empty()) {

				//debugcode
				DrawStringEx(0, 500, -1, "射程に誰もいないよ！");

				return;
			}


			//効果実行処理
			for (auto a : select_uicard_->GetCardPtr()->GetCardData()->GetCardEffectList()) {

				a->Effect(total_units_in_range_);
			}

			for (int i = 0; i < total_units_in_range_.size(); ++i) {

				if (total_units_in_range_[i]->GetUnitType() == UnitType::Ally) {

					UnitAlly* unit_ally = dynamic_cast<UnitAlly*>(total_units_in_range_[i]);
					card_effect_anim_[i]->pos_ = unit_ally->GetObj()->pos_;

				}
				else if (total_units_in_range_[i]->GetUnitType() == UnitType::Enemy) {

					UnitEnemy* unit_enemy = dynamic_cast<UnitEnemy*>(total_units_in_range_[i]);
					card_effect_anim_[i]->pos_ = unit_enemy->GetObj()->pos_;

				}

				card_effect_anim_[i]->setCurrentAnim(select_uicard_->GetCardPtr()->GetCardData()->debug_anim_name_);

			}
			
			for (int i = 0; i < total_units_in_range_.size(); ++i) {

				card_effect_anim_[i]->getCurrentAnimSeekUnit()->play();

			}

			//Se再生
			//sound_manager_.PlayCardSE(select_uicard_->GetCardPtr()->GetCardData()->GetCardID());
			sound_manager_.PlayCardSE(1);




			int select_serial_num = select_uicard_->GetCardPtr()->GetSerialNum();

			

			//turn_ally_->GetHand().pop_back();
			//UIと同じカードPtrをHandから削除
			turn_ally_->GetHand().erase(std::remove_if(turn_ally_->GetHand().begin(), turn_ally_->GetHand().end(),
				[select_serial_num](const std::shared_ptr<Card>& card) {
				return card->GetSerialNum() == select_serial_num;
				}), turn_ally_->GetHand().end());
		
		}

	}

}


//カードの効果を実行
void CardPlay::PlayCardExecute() {

	if (play_card_ && turn_ally_) {
		
		if (play_card_->GetCardData()->GetTargetType() == TargetType::AllRange) {

			//効果実行処理
			for (auto a : play_card_->GetCardData()->GetCardEffectList()) {

				a->Effect(total_units_in_range_);
			}




		}
		else if (play_card_->GetCardData()->GetTargetType() == TargetType::SpecifyTarget) {

				



		}







	}





}

void CardPlay::SetCameraToCardEffectAnim(dxe::Camera* camera) {

	if (!card_effect_anim_.empty()) {

		for (auto cra : card_effect_anim_) {
			cra->SetCamera(camera);
			cra->setCurrentAnim("none");
		}

	}

}
