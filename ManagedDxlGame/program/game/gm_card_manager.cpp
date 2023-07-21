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



	debug_card_data_.emplace_back(new CardData(0,1,false,0,"debug1","debug用カードです。","graphics/card/c1/beeding-heart.png"));

	debug_card_data_[0]->AddCardEffect(std::make_shared<CardEffectHeal>(5));
	debug_card_data_[0]->AddCardRange(std::make_shared<CardRangeSelf>());


	for (int i = 0; i < 10; ++i) {

		debug_deck_.push_back(std::make_shared<Card>(Card(debug_card_data_[0])));
	}


}

void CardManager::CreateDebugCardDeck() {

	for (int i = 0; i < 10; ++i) {
		
		debug_deck_.push_back(std::make_shared<Card>(Card(debug_card_data_[0])));
	}





}

void CardManager::CreateDebugCard() {

	debug_card_.emplace_back(new Card(debug_card_data_[0]));

	



}
