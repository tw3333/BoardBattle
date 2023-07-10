#include "gm_card_manager.h"


void CardManager::CreateDebugCardData() {



	debug_card_data_.emplace_back(new CardData(1,1,"debug1","debug用カードです。","graphics/card/c1/beeding-heart.png"));
	debug_card_data_.emplace_back(new CardData(2, 1, "debug2", "debug用カードです。", "graphics/card/c1/beeding-heart.png"));
	debug_card_data_.emplace_back(new CardData(3, 1, "debug3", "debug用カードです。", "graphics/card/c1/beeding-heart.png"));
	debug_card_data_.emplace_back(new CardData(4, 1, "debug4", "debug用カードです。", "graphics/card/c1/beeding-heart.png"));
	debug_card_data_.emplace_back(new CardData(5, 1, "debug5", "debug用カードです。", "graphics/card/c1/beeding-heart.png"));
	debug_card_data_.emplace_back(new CardData(6, 1, "debug6", "debug用カードです。", "graphics/card/c1/beeding-heart.png"));
	debug_card_data_.emplace_back(new CardData(7, 1, "debug7", "debug用カードです。", "graphics/card/c1/beeding-heart.png"));
	debug_card_data_.emplace_back(new CardData(8, 1, "debug8", "debug用カードです。", "graphics/card/c1/beeding-heart.png"));
	debug_card_data_.emplace_back(new CardData(9, 1, "debug9", "debug用カードです。", "graphics/card/c1/beeding-heart.png"));
	debug_card_data_.emplace_back(new CardData(10, 1, "debug10", "debug用カードです。", "graphics/card/c1/beeding-heart.png"));


	auto card1 = new Card(debug_card_data_[0]);
	auto card2 = new Card(debug_card_data_[1]);


}

void CardManager::CreateDebugCard() {

	debug_card_.emplace_back(new Card(debug_card_data_[0]));








}
