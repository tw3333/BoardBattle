#include "gm_sound_manager.h"

#include "DxLib.h"




void SoundManager::CreateBattleBGMList() {

	battle_bgm_list_.emplace_back(std::make_shared<SoundData>(1,SoundType::BGM,"sound/bgm/battle1.mp3"));








}

void SoundManager::CreateCardSEList() {

	card_se_list_.emplace_back(std::make_shared<SoundData>(1,SoundType::CardSE,"sound/se/cardse_fire.mp3"));





}

void SoundManager::CreateSystemSEList()
{

	system_se_list_.emplace_back(std::make_shared<SoundData>(1,SoundType::SystemSE,"sound/se/system_se/beep_1.mp3"));



} bv




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

		for (auto csl : card_se_list_) {

			if (csl->GetID() == id) {

				PlaySoundMem(csl->GetSoundHandle(), DX_PLAYTYPE_BACK, true);
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


