#pragma once

class UnitAlly;
class Board;
class Card;


class CardRange {
public:

	virtual void Range(Card* card, UnitAlly* act_ally, Board* board) = 0;


};