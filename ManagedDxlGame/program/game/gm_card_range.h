#pragma once

class UnitAlly;
class Board;

class CardRange {
public:

	virtual void Range(UnitAlly* act_ally, Board* board) = 0;

};