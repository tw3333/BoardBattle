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

void CardPlay::Render() {

	DebugRender();

}

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

void CardPlay::UpdateSelectCardGetUnitInRange(UnitAlly* turn_ally, std::vector<Unit*> all_units) {

	if (select_uicard_) {

		total_units_in_range_.clear();

		for (auto a : select_uicard_->GetCardPtr()->GetCardData()->GetCardRangeList())
		{
			std::vector<Unit*> unit_in_range = a->GetUnitInRange(turn_ally, all_units);
			total_units_in_range_.insert(total_units_in_range_.end(), unit_in_range.begin(), unit_in_range.end());
		}

		//debugcode
		DrawStringEx(0,600,-1,"�Ώۂ�%d�l���܂�",total_units_in_range_.size());

	}

}

void CardPlay::DebugRender() {

	if (select_uicard_) {

		DrawStringEx(0,650,-1,"���̃J�[�h��[%d]�ł�",select_uicard_->debug_cnt_);

	}
	else {
		DrawStringEx(0,650,-1,"select_uicard_��null�ł�");
	}




}

void CardPlay::EffectExecute()
{
	if (select_uicard_ && turn_ally_) {

		if (tnl::Input::IsMouseTrigger(eMouseTrigger::IN_LEFT)) {

			//�ǂ̎˒��ɂ��N�����Ȃ��ꍇ�͏����𒆒f����
			//for (auto a : select_uicard_->GetCardPtr()->GetCardData()->GetCardRangeList()) {

			//	if (a->GetIsUnitInRange() == false) {

			//		//debugcode
			//		DrawStringEx(0, 500, -1, "�˒��ɒN�����Ȃ���I");

			//		return;
			//	}
			//}
			if (total_units_in_range_.empty()) {

				//debugcode
				DrawStringEx(0, 500, -1, "�˒��ɒN�����Ȃ���I");

				return;
			}


			//���ʎ��s����
			for (auto a : select_uicard_->GetCardPtr()->GetCardData()->GetCardEffectList()) {

				a->Effect(total_units_in_range_);
			}			
		}
	}




}
