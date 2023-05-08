#pragma once
#include "gm_unit.h"
#include <string>


class Ally : public Unit{
public:

	Ally(int id, int hp, int cost, int speed){
	
		setType(Type::Ally);
		ally_id_ = id;
		max_hp_ = hp;
		now_hp_ = hp;
		max_cost_ = cost;
		now_cost_ = cost;
		speed_ = speed;
	
	}

	~Ally(){}

	//getter,setter
	Unit::Type getTYPE() { return type_; }
	int getAllyID() { return ally_id_; }
	int getAllyMaxHp() { return max_hp_; }
	int getAllyNowHp() { return now_hp_; }
	int getAllyMaxCost() { return max_cost_; }
	int getAllyNowCost() { return now_cost_; }
	int getAllySpeed() { return speed_; }


	//�����o�֐�
	
	
private:

	//type_ = Type::Ally;
	
	//Ally�Ǘ��pID
	int ally_id_;

	//�X�e�[�^�X
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