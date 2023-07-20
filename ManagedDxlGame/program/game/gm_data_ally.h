#pragma once
#include <string>
#include <vector>
#include "../dxlib_ext/dxlib_ext.h"

#include "gm_object.h"
#include "gm_object_ally.h"

//memo
//Allyの全体データを格納するクラス
class ObjAlly;

class AllyData {
public:

	AllyData(int ally_id, std::string name, int hp, int cost, int move_cost, int speed) {
		ally_id_ = ally_id;
		name_ = name;
		hp_ = hp;
		cost_ = cost;
		move_cost_ = move_cost;
		speed_ = speed;
	}

	~AllyData(){}

	//accessor
	int GetAllyDataID() { return ally_id_; }
	std::string getImgBattlePath() { return img_battle_path; }
	void setImgBattlePath(std::string path) { img_battle_path = path; }

	int GetHp() { return hp_; }
	int GetCost() { return cost_; }
	int GetMoveCost() { return move_cost_; }
	int GetSpeed() { return speed_; }

	Shared<dxe::Texture> GetTextureFace1() { return texture_face1_; }
	Shared<dxe::Texture> GetTextureFace2() { return texture_face2_; }
	Shared<dxe::Texture> GetTextureBattle() { return texture_battle_; }
	Shared<dxe::Texture> GetTextureStand() { return texture_stand_; }

	void SetTextureFace1(std::string texture_path) { 
		texture_face1_ = dxe::Texture::CreateFromFile(texture_path);
	}
	void SetTextureFace2(std::string texture_path) {
		texture_face2_ = dxe::Texture::CreateFromFile(texture_path);
	}
	void SetTextureBattle(std::string texture_path) {
		texture_battle_ = dxe::Texture::CreateFromFile(texture_path);
	}
	void SetTextureStand(std::string texture_path) {
		texture_stand_ = dxe::Texture::CreateFromFile(texture_path);
	}

	void SetObj(ObjAlly* obj) { obj_ = obj; }
	ObjAlly* GetObj() { return obj_; }

	void SetIsPartyPicked(bool flag) { is_party_picked_ = flag; }
	bool GetIsPartyPicked() { return is_party_picked_; }
	void SetIsEditPicked(bool flag) { is_edit_picked_ = flag; }
	bool GetIsEditPiked() { return is_edit_picked_; }

private:

	int ally_id_ = 0;

	std::string name_;

	int hp_ = 0;
	
	int cost_ = 0;
	int move_cost_ = 0;
	int speed_ = 0;
	

	//状態
	bool is_party_picked_ = false;
	bool is_edit_picked_ = false;
	
	//Card


	//画像パス
	std::string img_face1_path;
	std::string img_face2_path;
	std::string img_battle_path;
	std::string img_stand_path;

	//Obj
	ObjAlly* obj_ = nullptr;

	//Texture
	Shared<dxe::Texture> texture_face1_;
	Shared<dxe::Texture> texture_face2_;
	Shared<dxe::Texture> texture_battle_;
	Shared<dxe::Texture> texture_stand_;



	//ハンドル使用用
	int img_face1_handle;
	int img_face2_handle;
	int img_battle_hadle;
	int img_stand_handle;
};