#include "gm_card_play.h"

#include "gm_card.h"
#include "gm_card_effect.h"
#include "gm_card_range.h"
#include "gm_unit.h"
#include "gm_unit_ally.h"
#include "gm_unit_enemy.h"

void CardPlay::Render() {

	

}

void CardPlay::RenderSelectCardRange(UnitAlly* turn_ally, Board* board) {

	if (select_card_) {

		if (!select_card_->GetCardEffectList().empty()) {

			for (auto r : select_card_->GetCardRangeList()) {

				r->DisplayRange(turn_ally, board);

			}

		}

	}


}

void CardPlay::DebugRender() {

	if (select_card_) {

		DrawStringEx(300,0,-1,"選択されているカード：%s",select_card_->GetCardData()->GetCardName());
	}

}
