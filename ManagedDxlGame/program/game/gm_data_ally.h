#pragma once
#include <string>
#include <vector>

//memo
//Ally�̑S�̃f�[�^���i�[����N���X

class AllyData {
public:

	AllyData() {}
	~AllyData(){}


private:

	int ally_id_;

	std::string name_;

	int hp_;
	int cost_;

	int move_cost_;
	int speed_;
	
	//���
	bool is_party_picked_ = false;
	bool is_edit_picked_ = false;
	
	//Card


	//�摜�p�X
	std::string img_face1_path;
	std::string img_face2_path;
	std::string img_battle_path;
	std::string img_stand_path;

	//�n���h���g�p�p
	int img_face1_handle;
	int img_face2_handle;
	int img_battle_hadle;
	int img_stand_handle;
};