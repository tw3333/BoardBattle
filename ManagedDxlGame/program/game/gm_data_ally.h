#pragma once
#include <string>
#include <vector>

//memo
//Allyの全体データを格納するクラス

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
	
	//状態
	bool is_party_picked_ = false;
	bool is_edit_picked_ = false;
	
	//Card


	//画像パス
	std::string img_face1_path;
	std::string img_face2_path;
	std::string img_battle_path;
	std::string img_stand_path;

	//ハンドル使用用
	int img_face1_handle;
	int img_face2_handle;
	int img_battle_hadle;
	int img_stand_handle;
};