#include "gm_sound_manager.h"

#include "DxLib.h"




void SoundManager::CreateBattleBGMList() {

	

	battle_bgm_list_.emplace_back(std::make_shared<SoundData>(1,SoundType::BGM,"sound/bgm/battle1.mp3"));


	SetVolumeMusicMem(1,battle_bgm_list_[0]->GetSoundHandle());





}

void SoundManager::CreateCardSEList() {

	card_se_list_.emplace_back(std::make_shared<SoundData>(1,SoundType::CardSE,"sound/se/card_se_shield1.mp3"));





}

void SoundManager::CreateAllyVoiveList() {

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





void SoundManager::PlayBattleBGM(int id) {

	for (auto bbl : battle_bgm_list_) {

		if (bbl->GetID() == id) {

			PlaySoundMem(bbl->GetSoundHandle(), DX_PLAYTYPE_LOOP, false);
			break;
		}
	}

}

void SoundManager::PlayCardSE(int id) {

	if (!card_se_list_.empty()) {

		for (auto &csl : card_se_list_) {

			if (csl->GetID() == id) {

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

void SoundManager::PlayBattleStateSE(int id) {

	if (!battle_state_se_list_.empty()) {

		for (auto se : battle_state_se_list_) {

			if (se->GetID() == id) {

				PlaySoundMem(se->GetSoundHandle(),DX_PLAYTYPE_BACK,true);


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


