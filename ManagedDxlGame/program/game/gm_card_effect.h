#pragma once
#include <vector>

class Unit;



class CardEffect {
public:

	virtual void Effect(std::vector<Unit*> untis) = 0;
	
	int effect_ref_num_ = 0;

};