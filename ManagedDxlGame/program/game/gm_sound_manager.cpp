#include "gm_sound_manager.h"

#include "DxLib.h"




void SoundManager::CreateBattleBGMList() {

	battle_bgm_list_.emplace_back(std::make_shared<SoundData>(1,SoundType::BGM,"sound/bgm/battle1.mp3"));








}

void SoundManager::PlayBattleBGM(int id) {

	for (auto bbl : battle_bgm_list_) {

		if (bbl->GetID() == id) {

			PlaySoundMem(bbl->GetSoundHandle(), DX_PLAYTYPE_LOOP, false);
			break;
		}
	}

}
