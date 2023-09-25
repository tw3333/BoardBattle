#include "gm_allydata_manager.h"




void AllyDataManager::DebugLoadAllyData() {

	all_ally_data_.emplace_back(new AllyData(1,"ミア",30,3,5,35));
	all_ally_data_.emplace_back(new AllyData(2,"ルーセント",30,3,1,25));
	all_ally_data_.emplace_back(new AllyData(3,"ズズ",30,3,1,30));
	all_ally_data_.emplace_back(new AllyData(4,"ライン",40,3,1,20));

	all_ally_data_[0]->SetObj(obj_mgr_.GetObjAllyAtID(1));
	all_ally_data_[1]->SetObj(obj_mgr_.GetObjAllyAtID(2));
	all_ally_data_[2]->SetObj(obj_mgr_.GetObjAllyAtID(3));
	all_ally_data_[3]->SetObj(obj_mgr_.GetObjAllyAtID(4));

	all_ally_data_[0]->SetIsDeckEditPicked(true);



	is_loaded_ = true;
}

void AllyDataManager::DebugLoadAllyTexture() {

	all_ally_data_[0]->SetTextureFace1("graphics/unit/ally/c1_face1.png");
	all_ally_data_[0]->SetTextureFace2("graphics/unit/ally/c1_face2.png");
	all_ally_data_[0]->SetTextureBattle("graphics/unit/ally/c1_battle.png");
	all_ally_data_[0]->SetTextureStand("graphics/unit/ally/c1_stand.png");

	all_ally_data_[1]->SetTextureFace1("graphics/unit/ally/c2_face1.png");
	all_ally_data_[1]->SetTextureFace2("graphics/unit/ally/c2_face2.png");
	all_ally_data_[1]->SetTextureBattle("graphics/unit/ally/c2_battle.png");
	all_ally_data_[1]->SetTextureStand("graphics/unit/ally/c2_stand.png");

	all_ally_data_[2]->SetTextureFace1("graphics/unit/ally/c3_face1.png");
	all_ally_data_[2]->SetTextureFace2("graphics/unit/ally/c3_face2.png");
	all_ally_data_[2]->SetTextureBattle("graphics/unit/ally/c3_battle.png");
	all_ally_data_[2]->SetTextureStand("graphics/unit/ally/c3_stand.png");

	all_ally_data_[3]->SetTextureFace1("graphics/unit/ally/c4_face1.png");
	all_ally_data_[3]->SetTextureFace2("graphics/unit/ally/c4_face2.png");
	all_ally_data_[3]->SetTextureBattle("graphics/unit/ally/c4_battle.png");
	all_ally_data_[3]->SetTextureStand("graphics/unit/ally/c4_stand.png");

}

std::shared_ptr<AllyData> AllyDataManager::GetDeckEditAllyData() {

	std::shared_ptr<AllyData> ret = nullptr;

	if (!all_ally_data_.empty()) {

		for (auto ally : all_ally_data_) {

			if (ally->GetIsDeckEditPiked()) {

				ret = ally;
			}

		}

	}


	return ret;
}

std::vector<std::shared_ptr<AllyData>> AllyDataManager::GetPartyPickAllyData()
{

	if (!all_ally_data_.empty()) {

		std::vector<std::shared_ptr<AllyData>> ret;


		for (auto ally : all_ally_data_) {

			if (ally->GetIsPartyPicked()) {

				ret.push_back(ally);

			}

		}



		return ret;	
	}

}



