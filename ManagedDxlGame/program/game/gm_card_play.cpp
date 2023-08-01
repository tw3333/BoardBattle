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

void CardPlay::Render() {

	

}

void CardPlay::RenderSelectCardRange(UnitAlly* turn_ally, Board* board) {

	//if (select_card_) {

	//	if (!select_card_->GetCardData()->GetCardRangeList().empty()) {

	//		for (auto r : select_card_->GetCardData()->GetCardRangeList()) {

	//			r->DisplayRange(turn_ally, board);

	//		}

	//	}

	//}

	//if (select_card_) {

	//	//if (!select_card_->GetCardData()->debug_card_range_list_.empty()) {
	//	//	
	//	//	DrawStringEx(0,400,-1,"RangeListには何か入っています");

	//	//	//for (auto r : select_card_->GetCardData()->debug_card_range_list_) {

	//	//	//	r->DisplayRange(turn_ally, board);

	//	//	//}

	//	//	for (int i = 0; i < select_card_->GetCardData()->debug_card_range_list_.size(); ++i) {

	//	//		select_card_->GetCardData()->debug_card_range_list_[i]->DisplayRange(turn_ally, board);
	//	//	}

	//	//}

	//	select_card_->GetCardData()->card_range_->DisplayRange(turn_ally, board);

	//}
	//else if (!select_card_) {

	//	board->ResetRangeTile();

	//}

	//試し処理
	if (select_uicard_) {
		select_uicard_->GetCardPtr()->GetCardData()->card_range_->DisplayRange(turn_ally, board);
	}
	else if(!select_uicard_) {
		board->ResetRangeTile();
	}



}

void CardPlay::DebugRender() {

	if (select_card_) {

		DrawStringEx(0,300,-1,"選択されているカードID：%d",select_card_->GetCardData()->GetCardID());
	}

	if (!select_card_) {
		DrawStringEx(0, 300, -1, "選択されているカードID:選択されていません");

	}


}
