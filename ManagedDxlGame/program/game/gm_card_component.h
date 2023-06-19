#pragma once

class CardComponent {
public:

	virtual ~CardComponent(){}

	virtual void DisplayRange() = 0;
	virtual void CardEffect() = 0;


};