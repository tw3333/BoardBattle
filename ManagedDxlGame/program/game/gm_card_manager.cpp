#include "gm_card_manager.h"

#include "gm_card.h"

#include "gm_card_effect.h"
#include "gm_card_effect_heal.h"
#include "gm_card_effect_add_shield.h"
#include "gm_card_effect_add_taunt.h"
#include "gm_card_effect_damage.h"

#include "gm_card_range.h"
#include "gm_card_renge_self.h"
#include "gm_card_range_down.h"
#include "gm_card_range_up.h"
#include "gm_card_range_left.h"
#include "gm_card_range_right.h"



void CardManager::CreateDebugCardData() {

	debug_card_data_.emplace_back(new CardData(0, 1,TargetType::SpecifyTarget,1,"debug1","対象指定カード１","graphics/card/c1/beeding-heart.png"));
	debug_card_data_.emplace_back(new CardData(1, 1, TargetType::SpecifyTarget, 1, "debug2", "対象指定カード1", "graphics/card/c1/bird-claw.png"));
	debug_card_data_.emplace_back(new CardData(2, 1, TargetType::SpecifyTarget, 1, "debug3", "対象指定カード1", "graphics/card/c1/bloody-stash.png"));
	debug_card_data_.emplace_back(new CardData(3, 1, TargetType::SpecifyTarget, 1, "debug4", "対象指定カード１", "graphics/card/c1/circle-claws.png"));
	debug_card_data_.emplace_back(new CardData(4, 1, TargetType::SpecifyTarget, 1, "debug5", "対象指定カード１", "graphics/card/c1/claw-slashes.png"));
	debug_card_data_.emplace_back(new CardData(5, 1, TargetType::AllRange, 0, "debug6", "AoE", "graphics/card/c1/cross-mark.png"));
	debug_card_data_.emplace_back(new CardData(6, 1, TargetType::AllRange, 0, "debug7", "AoE", "graphics/card/c1/flaming-claw.png"));
	debug_card_data_.emplace_back(new CardData(7, 1, TargetType::AllRange, 0, "debug8", "AoE", "graphics/card/c1/foot-trip.png"));
	debug_card_data_.emplace_back(new CardData(8, 1, TargetType::AllRange, 0, "debug9", "AoE", "graphics/card/c1/grasping-claws.png"));
	debug_card_data_.emplace_back(new CardData(9, 1, TargetType::AllRange, 0, "debug10", "AoE", "graphics/card/c1/healing.png"));

	for (auto dcd : debug_card_data_) {

		//dcd->AddCardRange(std::make_shared<CardRangeSelf>());
		dcd->AddCardRange(std::make_shared<CardRangeLeft>(0,1,Target::All));
		dcd->AddCardRange(std::make_shared<CardRangeRight>(0,1,Target::All));
		dcd->AddCardRange(std::make_shared<CardRangeUp>(0,1,Target::All));
		dcd->AddCardRange(std::make_shared<CardRangeDown>(0,1,Target::All));


		
		dcd->AddCardEffect(std::make_shared<CardEffectDamage>(5));

	}


	for (int i = 0; i < 10; ++i) {

		debug_deck_.push_back(std::make_shared<Card>(Card(debug_card_data_[i])));

	}

	debug_deck_.push_back(std::make_shared<Card>(Card(debug_card_data_[1])));
	debug_deck_.push_back(std::make_shared<Card>(Card(debug_card_data_[1])));
	debug_deck_.push_back(std::make_shared<Card>(Card(debug_card_data_[1])));
	debug_deck_.push_back(std::make_shared<Card>(Card(debug_card_data_[1])));



	for (auto dcd : debug_card_data_) {

		dcd->debug_card_range_list_.emplace_back(new CardRangeSelf());

	}


}

void CardManager::CreateDebugCardDeck() {

	for (int i = 0; i < 10; ++i) {
		
		debug_deck_.push_back(std::make_shared<Card>(Card(debug_card_data_[i])));
	}





}

void CardManager::CreateDebugCard() {

	debug_card_.emplace_back(new Card(debug_card_data_[0]));

	



}
