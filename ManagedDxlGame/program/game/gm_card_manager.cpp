#include "gm_card_manager.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>


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
#include "gm_card_range_upper_left.h"
#include "gm_card_range_upper_right.h"
#include "gm_card_range_lower_left.h"
#include "gm_card_range_lower_right.h"
#include "gm_card_range_round.h"


#include "gm_card_target.h"



void CardManager::CreateDebugCardData() {

	debug_card_data_.emplace_back(new CardData(0, 1,1,"debug1","対象指定カード１","graphics/card/c1/beeding-heart.png"));
	debug_card_data_.emplace_back(new CardData(1, 1,1,"debug2", "対象指定カード1", "graphics/card/c1/bird-claw.png"));
	debug_card_data_.emplace_back(new CardData(2, 1,1,"debug3", "対象指定カード1", "graphics/card/c1/bloody-stash.png"));
	debug_card_data_.emplace_back(new CardData(3, 1,1,"debug4", "対象指定カード１", "graphics/card/c1/circle-claws.png"));
	debug_card_data_.emplace_back(new CardData(4, 1,1,"debug5", "対象指定カード１", "graphics/card/c1/claw-slashes.png"));
	debug_card_data_.emplace_back(new CardData(5, 1,1,"debug6", "AoE", "graphics/card/c1/cross-mark.png"));
	debug_card_data_.emplace_back(new CardData(6, 1,1,"debug7", "AoE", "graphics/card/c1/flaming-claw.png"));
	debug_card_data_.emplace_back(new CardData(7, 1,1,"debug8", "AoE", "graphics/card/c1/foot-trip.png"));
	debug_card_data_.emplace_back(new CardData(8, 1,1,"debug9", "AoE", "graphics/card/c1/grasping-claws.png"));
	debug_card_data_.emplace_back(new CardData(9, 1,1,"debug10", "AoE", "graphics/card/c1/healing.png"));


	for (int i = 0; i < 10; ++i) {

		if (i < 6) {
			debug_card_data_[i]->AddCardTarget(std::make_shared<CardTarget>(1,TARGETTYPE::Specify, TOTARGET::Enemy, 1));

		}
		else if (6 <= i) {
			debug_card_data_[i]->AddCardTarget(std::make_shared<CardTarget>(1,TARGETTYPE::InRange, TOTARGET::Enemy));
		}

	}





	for (auto dcd : debug_card_data_) {

		//dcd->AddCardRange(std::make_shared<CardRangeSelf>());
		//dcd->AddCardRange(std::make_shared<CardRangeLeft>(0,1));
		//dcd->AddCardRange(std::make_shared<CardRangeRight>(0,1));
		//dcd->AddCardRange(std::make_shared<CardRangeUp>(0,1));
		//dcd->AddCardRange(std::make_shared<CardRangeDown>(0,1));
		//dcd->AddCardRange(std::make_shared<CardRangeUpperLeft>(0, 2));
		//dcd->AddCardRange(std::make_shared<CardRangeUpperRight>(0, 2));
		//dcd->AddCardRange(std::make_shared<CardRangeLowerRight>(0, 2));
		//dcd->AddCardRange(std::make_shared<CardRangeLowerLeft>(1, 2));
		dcd->AddCardRange(std::make_shared<CardRangeRound>(0, 5));





		
		dcd->AddCardEffect(std::make_shared<CardEffectDamage>(1,5));

	}


	for (int i = 0; i < 10; ++i) {

		debug_deck_.push_back(std::make_shared<Card>(Card(debug_card_data_[i])));

	}

	debug_deck_.push_back(std::make_shared<Card>(Card(debug_card_data_[1])));
	debug_deck_.push_back(std::make_shared<Card>(Card(debug_card_data_[1])));
	debug_deck_.push_back(std::make_shared<Card>(Card(debug_card_data_[1])));
	debug_deck_.push_back(std::make_shared<Card>(Card(debug_card_data_[1])));



}

void CardManager::CreateDebugCardDeck() {

	for (int i = 0; i < 10; ++i) {
		
		debug_deck_.push_back(std::make_shared<Card>(Card(debug_card_data_[i])));
	}





}

void CardManager::CreateDebugCard() {

	debug_card_.emplace_back(new Card(debug_card_data_[0]));

	



}

void CardManager::LoadCardDataFromCSV(const std::string& filepath) {

	std::ifstream file(filepath);

	if (!file.is_open()) {
		std::cerr << "ファイルが開けませんでした" << std::endl;
		return;
	}

	std::string line;
	std::getline(file, line);  // ヘッダーラインをスキップ

	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::string item;

		std::getline(ss, item, ',');
		int card_id = std::stoi(item);

		std::getline(ss, item, ',');
		int poss_ally_id = std::stoi(item);

		std::getline(ss, item, ',');
		int card_cost = std::stoi(item);

		std::getline(ss, item, ',');
		std::string name = item;

		std::getline(ss, item, ',');
		std::string card_explanation = item;

		std::getline(ss, item, ',');
		std::string texture_path = item;

		all_card_data_.emplace_back(CardData(card_id, poss_ally_id, card_cost, name, card_explanation, texture_path));
	}

}



