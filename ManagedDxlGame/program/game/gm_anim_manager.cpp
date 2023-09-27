
#include "gm_anim_manager.h"

void AnimManager::CreateDebugAnim() {

	debug_anim_->regist(150, 100, "debug_anim", "graphics/effect/card_anim/anim_shield.png", tnl::SeekUnit::ePlayMode::SINGLE, 1.5f, 20, 142, 0, 4);
	debug_anim_->regist(0, 1, "none", "nullptr", tnl::SeekUnit::ePlayMode::SINGLE, 0.0f, 8, 240, 0, 1);


	//ˆê’U–‘O‚Épool‚·‚é•ûŒü‚Åì¬
	//for (int i = 0; i < 100; ++i) {
	//	debug_anim_list_.push_back(debug_anim_);
	//}



	//for (int i = 0; i < 100; ++i) {
	//	debug_anim_list_.emplace_back(std::make_shared<AnimSprite3D>());
	//}

	//int cnt = 0;
	//int cnt2 = 0;
	//for (auto dal : debug_anim_list_) {


	//	dal->regist(100, 100, "debug_anim", "graphics/effect/anim_flame.png", tnl::SeekUnit::ePlayMode::REPEAT, 1.0f, 8, 240, 0, 1);
	//	dal->regist(0, 1, "none", "nullptr", tnl::SeekUnit::ePlayMode::SINGLE, 0.0f, 8, 240, 0, 1);

	//}

	//10x10‚Ìanim_pool
	for (int i = 0; i < 100; ++i) {
		anim_.emplace_back(std::make_shared<AnimSprite3D>());
	}

	for (auto anim : anim_) {

		anim->regist(100, 100, "debug_anim", "graphics/effect/anim_flame.png", tnl::SeekUnit::ePlayMode::SINGLE, 1.0f, 8, 240, 0, 1);
		anim->regist(100, 100, "anim_attack", "graphics/effect/card_anim/anim_attack.png", tnl::SeekUnit::ePlayMode::SINGLE, 1.0f, 5, 240, 0, 1);
		anim->regist(100, 100, "anim_blood", "graphics/effect/card_anim/anim_blood.png", tnl::SeekUnit::ePlayMode::SINGLE, 1.0f, 5, 240, 0, 1);
		anim->regist(100, 100, "anim_buf", "graphics/effect/card_anim/anim_buf.png", tnl::SeekUnit::ePlayMode::SINGLE, 1.0f, 10, 240, 0, 1);
		anim->regist(100, 100, "anim_crow", "graphics/effect/card_anim/anim_crow.png", tnl::SeekUnit::ePlayMode::SINGLE, 1.0f, 8, 240, 0, 2);
		anim->regist(100, 100, "anim_flame", "graphics/effect/card_anim/anim_flame.png", tnl::SeekUnit::ePlayMode::SINGLE, 1.0f, 8, 240, 0, 1);
		anim->regist(100, 100, "anim_heal", "graphics/effect/card_anim/anim_heal.png", tnl::SeekUnit::ePlayMode::SINGLE, 1.0f, 8, 240, 0, 1);
		anim->regist(100, 100, "anim_ice", "graphics/effect/card_anim/anim_ice.png", tnl::SeekUnit::ePlayMode::SINGLE, 1.0f, 8, 240, 0, 1);
		anim->regist(100, 100, "anim_shield", "graphics/effect/card_anim/anim_shield.png", tnl::SeekUnit::ePlayMode::SINGLE, 1.0f, 10, 192, 0, 2);
		anim->regist(100, 100, "anim_sword", "graphics/effect/card_anim/anim_sword.png", tnl::SeekUnit::ePlayMode::SINGLE, 1.0f, 5, 240, 0, 1);
		anim->regist(100, 100, "anim_thunder", "graphics/effect/card_anim/anim_thunder.png", tnl::SeekUnit::ePlayMode::SINGLE, 1.0f, 8, 480, 0, 1);
		anim->regist(100, 100, "anim_wind", "graphics/effect/card_anim/anim_wind.png", tnl::SeekUnit::ePlayMode::SINGLE, 1.0f, 8, 240, 0, 1);
		
	
	}


	
}
