#pragma once
#include <memory>
#include <vector>

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

	void RenderSelectCardRange(UnitAlly* turn_ally, Board* board);
	void DebugRender();

	void EffectExecute();


	void SetSelectCard(std::shared_ptr<Card> card) { select_card_ = card; }
	void SetCard(Card* card) { play_card_ = card; }



private:

	std::shared_ptr<Card> select_card_ = nullptr;
	






	Card* play_card_ = nullptr;

	std::vector<CardEffect*> card_effect_list_;
	std::vector<CardRange*> card_range_list_;

	std::vector<Unit*> in_range_units_;
	std::vector<Unit*> target_units_;
	
	

};