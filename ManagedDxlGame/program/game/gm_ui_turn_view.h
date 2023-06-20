#pragma once
#include "gm_ui_component.h"
#include "gm_unit.h"
#include "gm_unit_ally.h"
#include "gm_unit_enemy.h"



class UITurnView : public UIComponent {
public:

	UITurnView(std::vector<Unit*> all_units) 
	{}
	~UITurnView() {}




private:

	std::vector<Unit*> all_units_; 





};