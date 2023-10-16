#include "gm_sound_manager.h"

#include <vector>
#include <fstream>
#include <memory>
#include <sstream>

#include "DxLib.h"




void SoundManager::CreateBattleBGMList() {

	

	battle_bgm_list_.emplace_back(std::make_shared<SoundData>(1,SoundType::BGM,"sound/bgm/battle1.mp3"));


	//SetVolumeMusicMem(0,battle_bgm_list_[0]->GetSoundHandle());
	ChangeVolumeSoundMem(5, battle_bgm_list_[0]->GetSoundHandle());





}

void SoundManager::CreateCardSEList() {

	card_se_list_.emplace_back(std::make_shared<SoundData>(1,SoundType::CardSE,"sound/se/card_se/card_se_shield1.mp3"));






}

void SoundManager::CreateAllyVoiveList() {

	//movese
	ally_move_se_ = std::make_shared<SoundData>(0,SoundType::AllyVoice,"sound/se/ally_se/ally_move_se.mp3");

	ally_damaged_voice_list_.push_back(std::make_shared<SoundData>(1,SoundType::AllyVoice,"sound/se/ally_voice/c1_damaged_voice.mp3"));
	ally_damaged_voice_list_.push_back(std::make_shared<SoundData>(2, SoundType::AllyVoice, "sound/se/ally_voice/c2_damaged_voice.mp3"));
	ally_damaged_voice_list_.push_back(std::make_shared<SoundData>(2, SoundType::AllyVoice, "sound/se/ally_voice/c3_damaged_voice.mp3"));



}

void SoundManager::CreateSystemSEList()
{

	system_se_list_.emplace_back(std::make_shared<SoundData>(1,SoundType::SystemSE,"sound/se/system_se/beep_1.mp3"));



}
void SoundManager::CreateBattleStateSEList() {

	battle_state_se_list_.push_back(std::make_shared<SoundData>(1,SoundType::BattleStateSE,"sound/se/battle_state_se/blood.mp3"));
	battle_state_se_list_.push_back(std::make_shared<SoundData>(2, SoundType::BattleStateSE, "sound/se/battle_state_se/poison.mp3"));
	battle_state_se_list_.push_back(std::make_shared<SoundData>(3, SoundType::BattleStateSE, "sound/se/battle_state_se/snare.mp3"));
	battle_state_se_list_.push_back(std::make_shared<SoundData>(4, SoundType::BattleStateSE, "sound/se/battle_state_se/stun.mp3"));

	for (auto se : battle_state_se_list_) {

		SetVolumeSoundMem(5,se->GetSoundHandle());

	}




}

bool SoundManager::CreateEnemyActSEList() {

	enemy_act_se_list_.push_back(std::make_shared<SoundData>(1,SoundType::EnemyActSE,"sound/se/enemy_act_se/slime_attack_se.mp3"));






	return true;
}

bool SoundManager::CreateUISEList() {

	if (ui_se_list_.empty()) {

		ui_se_list_.resize(UISE::UISENum);

		ui_se_list_[UISE::PushButton] = std::make_shared<SoundData>(UISE::PushButton,SoundType::UISE,"sound/se/ui_se/se_push_button.mp3");
		ui_se_list_[UISE::BackPhase] = std::make_shared<SoundData>(UISE::BackPhase, SoundType::UISE, "sound/se/ui_se/se_back_phase.mp3");
		ui_se_list_[UISE::CantUseCard] = std::make_shared<SoundData>(UISE::CantUseCard, SoundType::UISE, "sound/se/ui_se/se_cant_use_card.mp3");
		ui_se_list_[UISE::MatchCursorTarget] = std::make_shared<SoundData>(UISE::MatchCursorTarget, SoundType::UISE, "sound/se/ui_se/se_math_cursor_target.mp3");
		ui_se_list_[UISE::AddCard] = std::make_shared<SoundData>(UISE::AddCard, SoundType::UISE, "sound/se/ui_se/se_add_card.mp3");


	}

	return false;
}

bool SoundManager::LoadCardSEFromCSV(std::string file_name) {

	if (card_se_list_.empty()) {

		std::ifstream file(file_name);

		if (!file.is_open()) {
			return false;
		}

		std::string line;
		
		std::getline(file, line); //ヘッダー飛ばし

		while (std::getline(file, line)) {
			std::istringstream iss(line);
			std::string id_str, path;

			std::getline(iss, id_str, ',');
			std::getline(iss, path, ',');

			int id = std::stoi(id_str);
			card_se_list_.emplace_back(std::make_shared<SoundData>(id, SoundType::CardSE, path));
		}


		return true;
	}

	return false;
}

bool SoundManager::LoadBattleStateSEFromCSV(std::string file_name) {

	if (battle_state_se_list_.empty()) {

		std::ifstream file(file_name);

		if (!file.is_open()) {
			return false;
		}

		std::string line;

		std::getline(file, line); //ヘッダー飛ばし

		while (std::getline(file, line)) {
			std::istringstream iss(line);
			std::string id_str, path, volume_str;

			std::getline(iss, id_str, ',');
			std::getline(iss, path, ',');
			std::getline(iss, volume_str, ',');


			int id = std::stoi(id_str);
			int volume = std::stoi(volume_str);
			battle_state_se_list_.emplace_back(std::make_shared<SoundData>(id, SoundType::BattleStateSE, path, volume));
		}

		return true;
	}

	return false;
}





void SoundManager::PlayBattleBGM(int id) {

	for (auto bbl : battle_bgm_list_) {

		if (bbl->GetID() == id) {

			PlaySoundMem(bbl->GetSoundHandle(), DX_PLAYTYPE_LOOP, false);
			break;
		}
	}

}

void SoundManager::PlayCardSE(int card_id) {

	if (!card_se_list_.empty()) {

		for (auto csl : card_se_list_) {

			if (csl->GetID() == card_id) {

				PlaySoundMem(csl->GetSoundHandle(), DX_PLAYTYPE_BACK, true);
				break;
			}
		}

	}

}

void SoundManager::PlayAllyDamagedVoice(int id) {

	if (!ally_damaged_voice_list_.empty()) {

		for (auto se : ally_damaged_voice_list_) {

			if (se->GetID() == id) {

				PlaySoundMem(se->GetSoundHandle(), DX_PLAYTYPE_BACK, true);
				break;
			}
		}

	}

}



void SoundManager::PlayEnemyActSE(int id) {

	if (!enemy_act_se_list_.empty()) {

		for (auto se : enemy_act_se_list_) {

			if (se->GetID() == id) {

				PlaySoundMem(se->GetSoundHandle(), DX_PLAYTYPE_BACK, true);
				break;		
		
			}

		}

	}

}

void SoundManager::PlaySystemSE(int id)
{
	if (!system_se_list_.empty()) {

		for (auto ssl : system_se_list_) {

			if (ssl->GetID() == id) {

				PlaySoundMem(ssl->GetSoundHandle(), DX_PLAYTYPE_BACK, true);
				break;

			}

		}

	}

}

void SoundManager::PlayUISE(UISE ui_se) {

	if (!ui_se_list_.empty()) {
		PlaySoundMem(ui_se_list_[ui_se]->GetSoundHandle(),DX_PLAYTYPE_BACK,true);
	}

}



void SoundManager::PlayAllyMoveSE() {
	
	if (ally_move_se_) {

		PlaySoundMem(ally_move_se_->GetSoundHandle(),DX_PLAYTYPE_BACK,true);

	}

}

void SoundManager::PlayBattleStateSE(State state) {

	if (!battle_state_se_list_.empty()) {

		for (auto &se : battle_state_se_list_) {

			if (state == State::Blood) {

				if (se->GetID() == 1) {
					PlaySoundMem(se->GetSoundHandle(), DX_PLAYTYPE_BACK, true);
					break;
				}

			}
			else if (state == State::Snare) {

				if (se->GetID() == 2) {
					PlaySoundMem(se->GetSoundHandle(), DX_PLAYTYPE_BACK, true);
					break;
				}

			}	
			else if (state == State::Stun) {

				if (se->GetID() == 3) {
					PlaySoundMem(se->GetSoundHandle(), DX_PLAYTYPE_BACK, true);
					break;
				}

			}

		}

	}

}


