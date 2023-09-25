#pragma once
#include <memory>
#include <string>

#include "gm_card.h"

class Deck {
public:

	Deck(){}
	~Deck(){}

	void SetDeckName(std::string &deck_name) { deck_name_ = deck_name; }
	std::string GetDeckName() { return deck_name_; }
	void SetDeck(std::vector<std::shared_ptr<Card>> deck) { deck_ = deck; }
	std::vector<std::shared_ptr<Card>> GetDeck() { return deck_; }


private:

	std::string deck_name_ = "";
	std::vector<std::shared_ptr<Card>> deck_;



};