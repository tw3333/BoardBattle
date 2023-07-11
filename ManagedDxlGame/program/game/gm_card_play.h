#pragma once
#include "gm_card.h"

#include "gm_card_effect.h"
#include "gm_card_range.h"

#include "gm_unit.h"
#include "gm_unit_ally.h"
#include "gm_unit_enemy.h"


class CardPlay {
public:

	CardPlay() {}
	~CardPlay() {}


	void Update();

	void Render();

	void EffectExecute();

	void SetCard(Card* card) { play_card_ = card; }

private:


	Card* select_card_ = nullptr;
	Card* play_card_ = nullptr;

	std::vector<CardEffect*> card_effect_list_;
	std::vector<CardRange*> card_range_list_;

	std::vector<Unit*> in_range_units_;
	
	

};