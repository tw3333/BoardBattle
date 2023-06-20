#pragma once
#include "gm_ui_component.h"
#include "gm_unit.h"
#include "gm_unit_ally.h"
#include "gm_unit_enemy.h"



class UITurnView : public UIComponent {
public:

	UITurnView(int x, int y, int width, int height, std::vector<Unit*> all_units) : all_units_(all_units)
	{
		x_ = x;
		y_ = y;
		width_ = width;
		height_ = height;

	}
	~UITurnView() {}

	void Update(float delt_time) override;
	void Render() override;


	bool reset_ = true;

private:

	std::vector<int> unit_graph_handles_;
	std::vector<Unit*> all_units_; 

	//Ši”[—p
	UnitAlly* ally_ = nullptr;
	UnitEnemy* enemy_ = nullptr;

	int x_;
	int y_;
	int width_;
	int height_;

	//ColorCode
	int	color_ground_work_ = GetColor(200, 197, 166);

};