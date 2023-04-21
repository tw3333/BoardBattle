#pragma once
#include "gm_unit.h"
#include <string>


class Ally : public Unit{
public:

	Ally() {}
	~Ally(){}

	//getter,setter
	Unit::Type getTYPE() { return type_; }
	int getAllyID() { return ally_id_; }


	//メンバ関数
	

private:

	Unit::Type type_ = Unit::Type::Ally;
	
	//Ally管理用ID
	int ally_id_;

	//ステータス
	int max_hp_;
	int now_hp_;

	int max_cost_;
	int now_cost_;

	int speed_;

	std::string img_face1_path;
	std::string img_face2_path;
	std::string img_battle_path;
	std::string img_stand_path;

	int img_face1_handle;
	int img_face2_handle;
	int img_battle_hadle;
	int img_stand_handle;

};