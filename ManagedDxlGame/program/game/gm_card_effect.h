#pragma once
#include <vector>

class Unit;
class UnitAlly;
class UnitEnemy;


class CardEffect {
public:


	
	virtual void Effect(std::vector<Unit*> untis);


};