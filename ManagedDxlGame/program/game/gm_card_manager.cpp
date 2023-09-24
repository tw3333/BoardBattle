#include "gm_card_manager.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <memory>
#include <regex>


#include "gm_card.h"
#include "gm_card_effect.h"
#include "gm_card_effect_heal.h"
#include "gm_card_effect_add_shield.h"
#include "gm_card_effect_add_taunt.h"
#include "gm_card_effect_damage.h"
#include "gm_card_effect_passing_damage.h"
#include "gm_card_effect_push_out.h"
#include "gm_card_effect_add_blood.h"
#include "gm_card_effect_add_card_cost.h"
#include "gm_card_effect_add_move_cost.h"
#include "gm_card_effect_add_shield.h"
#include "gm_card_effect_add_snare.h"
#include "gm_card_effect_add_stun.h"
#include "gm_card_effect_add_taunt.h"
#include "gm_card_effect_push_out.h"
#include "gm_card_effect_share_shield.h"
#include "gm_card_effect_move.h"
#include "gm_card_effect_none.h"


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
			debug_card_data_[i]->AddCardTarget(std::make_shared<CardTarget>(1,1,TARGETTYPE::Specify, TOTARGET::Enemy,1));

		}
		else if (6 <= i) {
			debug_card_data_[i]->AddCardTarget(std::make_shared<CardTarget>(1,1,TARGETTYPE::InRange, TOTARGET::Enemy));
		}

	}





	for (auto dcd : debug_card_data_) {

		//dcd->AddCardRange(std::make_shared<CardRangeSelf>());
		dcd->AddCardRange(std::make_shared<CardRangeRight>(0,5));
		dcd->AddCardRange(std::make_shared<CardRangeUp>(0,5));
		dcd->AddCardRange(std::make_shared<CardRangeLeft>(0,5));
		dcd->AddCardRange(std::make_shared<CardRangeDown>(0,5));
		//dcd->AddCardRange(std::make_shared<CardRangeUpperLeft>(0, 2));
		//dcd->AddCardRange(std::make_shared<CardRangeUpperRight>(0, 2));
		//dcd->AddCardRange(std::make_shared<CardRangeLowerRight>(0, 2));
		//dcd->AddCardRange(std::make_shared<CardRangeLowerLeft>(1, 2));
		//dcd->AddCardRange(std::make_shared<CardRangeRound>(0, 5));





		
		//dcd->AddCardEffect(std::make_shared<CardEffectDamage>(1,5));
		//dcd->AddCardEffect(std::make_shared<CardEffectPassingDamage>(1,5));
		dcd->AddCardEffect(std::make_shared<CardEffectPushOut>(1,1, 2));



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

TARGETTYPE CardManager::StrToTargetType(const std::string& str) {

	if (str == "None") { return TARGETTYPE::None; }
	if (str == "InRange") {	return TARGETTYPE::InRange; }
	if (str == "Specify") { return TARGETTYPE::Specify; }

	return TARGETTYPE::None;
}

TOTARGET CardManager::StrToToTarget(const std::string& str) { 
	
	if (str == "None") { return TOTARGET::None; }
	if (str == "Ally") { return TOTARGET::Ally; }
	if (str == "Enemy") { return TOTARGET::Enemy; }
	if (str == "Square") { return TOTARGET::Square; }
	if (str == "All") { return TOTARGET::All; }
	if (str == "Self") { return TOTARGET::Self; }
	
	return TOTARGET::None;
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

		all_card_data_.emplace_back(new CardData(card_id, poss_ally_id, card_cost, name, card_explanation, texture_path));
	}


}

void CardManager::LoadCardRangeFromCSV(const std::string& filepath) {

	std::ifstream file(filepath);
	if (!file.is_open()) {
		return;
	}

	// ヘッダー行をスキップ
	std::string line;
	std::getline(file, line);

	while (std::getline(file, line)) {
		std::istringstream ss(line);
		std::string token;
		std::vector<std::string> tokens;

		while (std::getline(ss, token, ',')) {
			tokens.push_back(token);
		}

		int card_id = std::stoi(tokens[0]);

		CardData* card_data = nullptr;

		for (auto carddata : all_card_data_) {
			if (carddata->GetCardID() == card_id) {
				card_data = carddata;
				break;
			}
		}

		for (size_t i = 1; i < tokens.size(); i += 3) {
			std::string direction = tokens[i];
			if (direction.empty()) {
				break;
			}

			int leave = std::stoi(tokens[i + 1]);
			int range = std::stoi(tokens[i + 2]);

			std::shared_ptr<CardRange> cardRange;

			//TODO:関数化
			if (direction == "Right") {
				cardRange = std::make_shared<CardRangeRight>(leave, range);
			}
			else if (direction == "Left") {
				cardRange = std::make_shared<CardRangeLeft>(leave, range);
			}
			else if (direction == "Up") {
				cardRange = std::make_shared<CardRangeUp>(leave, range);
			}
			else if (direction == "Down") {
				cardRange = std::make_shared<CardRangeDown>(leave, range);
			}
			else if (direction == "UpperLeft") {
				cardRange = std::make_shared<CardRangeUpperLeft>(leave, range);
			}
			else if (direction == "UpperRight") {
				cardRange = std::make_shared<CardRangeUpperRight>(leave, range);
			}
			else if (direction == "LowerLeft") {
				cardRange = std::make_shared<CardRangeLowerLeft>(leave, range);
			}
			else if (direction == "LowerRight") {
				cardRange = std::make_shared<CardRangeLowerRight>(leave, range);
			}
			else if (direction == "Round") {
				cardRange = std::make_shared<CardRangeRound>(leave, range);
			}
			else if (direction == "Self") {
				cardRange = std::make_shared<CardRangeSelf>();
			} 

			card_data->AddCardRange(cardRange);
		}
	}
}



void CardManager::LoadCardTargetFromCSV(const std::string& filepath) {

	if (!all_card_data_.empty()) {

		std::ifstream file(filepath);
		
		if (!file.is_open()) {
			std::cerr << "Failed to open the CSV file." << std::endl;
			return;
		}

		std::string line;
		// Skip the header line
		std::getline(file, line);

		while (std::getline(file, line)) {
			std::istringstream ss(line);
			std::string token;

			int card_id, ref_num, target_num;
			TARGETTYPE target_type;
			TOTARGET to_target;

			// CardID
			std::getline(ss, token, ',');
			card_id = std::stoi(token);

			// RefNum
			std::getline(ss, token, ',');
			ref_num = std::stoi(token);

			// CardTarget
			std::getline(ss, token, ',');
			target_type = StrToTargetType(token);

			// ToTarget
			std::getline(ss, token, ',');
			to_target = StrToToTarget(token);

			// TargetNum
			std::getline(ss, token, ',');
			target_num = std::stoi(token);

			all_card_target_.emplace_back(std::make_shared<CardTarget>(CardTarget(card_id, ref_num, target_type, to_target, target_num)));
		}
		
		file.close();
	}

	for (auto& target : all_card_target_) {

		for (auto& data : all_card_data_) {

			if (target->GetCardID() == data->GetCardID()) {

				data->AddCardTarget(target);
			}
		}
	}

}

void CardManager::LoadCardEffectFromCSV(const std::string& filepath) {












}


void CardManager::LoadAllCardTargetFromCSV(const std::string& filepath) {

	std::ifstream file(filepath);
	if (!file.is_open()) {
		std::cerr << "Failed to open the file." << std::endl;
		return;
	}

	std::string line;
	// Skip header
	std::getline(file, line);

	std::regex cardTargetRegex(R"(CardTarget\((\d+),(\d+),(\w+),(\w+),(\d+)\))");

	while (std::getline(file, line)) {
		std::sregex_iterator it(line.begin(), line.end(), cardTargetRegex);
		std::sregex_iterator it_end;

		for (; it != it_end; ++it) {
			std::smatch match = *it;
			int card_id = std::stoi(match[1].str());
			int ref_num = std::stoi(match[2].str());
			TARGETTYPE target_type = (match[3].str() == "Specify") ? TARGETTYPE::Specify:
				(match[3].str() == "InRange") ? TARGETTYPE::InRange : TARGETTYPE::None;
			TOTARGET to_target = (match[4].str() == "Enemy") ? TOTARGET::Enemy :
				(match[4].str() == "Ally") ? TOTARGET::Ally :
				(match[4].str() == "Square") ? TOTARGET::Square : TOTARGET::None;
			int target_num = std::stoi(match[5].str());

			all_card_target_.push_back(std::make_shared<CardTarget>(card_id, ref_num, target_type, to_target, target_num));
		}
	}

	file.close();
}

void CardManager::LoadAllCardEffectFromCSV(const std::string& filepath) {

	std::ifstream file(filepath);
	if (!file.is_open()) {
		std::cerr << "Failed to open the file." << std::endl;
		return;
	}

	std::string line;
	// Skip header
	std::getline(file, line);

	std::regex cardEffectRegex(R"((\w+)\((\d+)(?:,(\d+))?(?:,(\d+))?(?:,(\d+))?\))");

	while (std::getline(file, line)) {
		std::sregex_iterator it(line.begin(), line.end(), cardEffectRegex);
		std::sregex_iterator it_end;

		for (; it != it_end; ++it) {
			std::smatch match = *it;
			std::string effect_type = match[1].str();
			int card_id = std::stoi(match[2].str());
			int ref_num = std::stoi(match[3].str());
			int value = (match[4].str().empty()) ? 0 : std::stoi(match[4].str());

			//TODO:関数化
			if (effect_type == "AddBlood") {
				all_card_effect_.push_back(std::make_shared<CardEffectAddBlood>(card_id, ref_num));
			}
			else if (effect_type == "AddCardCost") {
				all_card_effect_.push_back(std::make_shared<CardEffectAddCardCost>(card_id, ref_num, value));
			}
			else if (effect_type == "AddMoveCost") {
				all_card_effect_.push_back(std::make_shared<CardEffectAddMoveCost>(card_id, ref_num, value));
			}
			else if (effect_type == "AddShield") {
				all_card_effect_.push_back(std::make_shared<CardEffectAddShield>(card_id, ref_num, value));
			}
			else if (effect_type == "AddSnare") {
				all_card_effect_.push_back(std::make_shared<CardEffectAddSnare>(card_id, ref_num, value));
			}
			else if (effect_type == "AddStun") {
				all_card_effect_.push_back(std::make_shared<CardEffectAddStun>(card_id, ref_num, value));
			}
			else if (effect_type == "AddTaunt") {
				all_card_effect_.push_back(std::make_shared<CardEffectAddTaunt>(card_id, ref_num, value));
			}
			else if (effect_type == "Damage") {
				all_card_effect_.push_back(std::make_shared<CardEffectDamage>(card_id, ref_num, value));
			}
			else if (effect_type == "Heal") {
				all_card_effect_.push_back(std::make_shared<CardEffectHeal>(card_id, ref_num, value));
			}
			else if (effect_type == "Move") {
				all_card_effect_.push_back(std::make_shared<CardEffectMove>(card_id, ref_num));
			}
			else if (effect_type == "None") {
				all_card_effect_.push_back(std::make_shared<CardEffectNone>(card_id, ref_num));
			}
			else if (effect_type == "PassingDamage") {
				all_card_effect_.push_back(std::make_shared<CardEffectPassingDamage>(card_id, ref_num, value));
			}
			else if (effect_type == "PushOut") {
				all_card_effect_.push_back(std::make_shared<CardEffectPushOut>(card_id, ref_num,value));
			}
			else if (effect_type == "ShareShield") {
				all_card_effect_.push_back(std::make_shared<CardEffectShareShield>(card_id, ref_num));
			}

			// ... [Add other effect types like AddMoveCost, Heal, etc. here]
		}
	}

	file.close();

}

void CardManager::CombineCardData() {

	if (!all_card_data_.empty() && !all_card_target_.empty()) {

		for (auto& carddata : all_card_data_) {

			for (auto &cardtarget : all_card_target_) {

				if (carddata->GetCardID() == cardtarget->GetCardID()) {

					carddata->AddCardTarget(cardtarget);
				}
			}

			for (auto &cardeffect : all_card_effect_) {

				if (carddata->GetCardID() == cardeffect->GetCardID()) {
					carddata->AddCardEffect(cardeffect);
				}

			}

		}

	}

}

void CardManager::CreateAllInitCard() {

	if (!all_card_data_.empty()) {

		for (auto data : all_card_data_) {

			all_card_.emplace_back(std::make_shared<Card>(Card(data)));


		}
	}

}

void CardManager::LoadC1DeckFromCSV(const std::string& filepath) {

	if (!all_card_.empty()) {

		std::ifstream file(filepath);
		if (!file.is_open()) {
			std::cerr << "Error opening file: " << filepath << std::endl;
			return;
		}

		std::string line;

		// ヘッダ行をスキップ
		std::getline(file, line);

		while (std::getline(file, line)) {
			std::stringstream lineStream(line);
			std::string cell;

			// CardIDを取得
			std::getline(lineStream, cell, ',');
			int cardID = std::stoi(cell);

			// CardNumを取得
			std::getline(lineStream, cell, ',');
			int cardNum = std::stoi(cell);

			for (const auto& cardPtr : all_card_) {
				if (cardPtr->GetCardData()->GetCardID() == cardID) {
					for (int i = 0; i < cardNum; i++) {
						// all_card_からのポインタのコピーをc1_deck_に追加
						c1_deck_.push_back(cardPtr);
					}
					break;
				}
			}
		}

		file.close();
	}

}

void CardManager::LoadC2DeckFromCSV(const std::string& filepath) {

	if (!all_card_.empty()) {

		std::ifstream file(filepath);
		if (!file.is_open()) {
			std::cerr << "Error opening file: " << filepath << std::endl;
			return;
		}

		std::string line;

		// ヘッダ行をスキップ
		std::getline(file, line);

		while (std::getline(file, line)) {
			std::stringstream lineStream(line);
			std::string cell;

			// CardIDを取得
			std::getline(lineStream, cell, ',');
			int cardID = std::stoi(cell);

			// CardNumを取得
			std::getline(lineStream, cell, ',');
			int cardNum = std::stoi(cell);

			for (const auto& cardPtr : all_card_) {
				if (cardPtr->GetCardData()->GetCardID() == cardID) {
					for (int i = 0; i < cardNum; i++) {
						// all_card_からのポインタのコピーをc1_deck_に追加
						c2_deck_.push_back(cardPtr);
					}
					break;
				}
			}
		}

		file.close();
	}


}

void CardManager::LoadC3DeckFromCSV(const std::string& filepath) {

	if (!all_card_.empty()) {

		std::ifstream file(filepath);
		if (!file.is_open()) {
			std::cerr << "Error opening file: " << filepath << std::endl;
			return;
		}

		std::string line;

		// ヘッダ行をスキップ
		std::getline(file, line);

		while (std::getline(file, line)) {
			std::stringstream lineStream(line);
			std::string cell;

			// CardIDを取得
			std::getline(lineStream, cell, ',');
			int cardID = std::stoi(cell);

			// CardNumを取得
			std::getline(lineStream, cell, ',');
			int cardNum = std::stoi(cell);

			for (const auto& cardPtr : all_card_) {
				if (cardPtr->GetCardData()->GetCardID() == cardID) {
					for (int i = 0; i < cardNum; i++) {
						// all_card_からのポインタのコピーをc1_deck_に追加
						c3_deck_.push_back(cardPtr);
					}
					break;
				}
			}
		}

		file.close();
	}

}



