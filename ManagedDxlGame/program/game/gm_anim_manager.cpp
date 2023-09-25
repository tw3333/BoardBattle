
#include "gm_anim_manager.h"

void AnimManager::CreateDebugAnim() {

	debug_anim_->regist(500, 500, "debug_anim", "graphics/effect/anim_flame.png", tnl::SeekUnit::ePlayMode::SINGLE, 1.0f, 8, 240, 0, 1);
	debug_anim_->regist(0, 1, "none", "nullptr", tnl::SeekUnit::ePlayMode::SINGLE, 0.0f, 8, 240, 0, 1);


	//ˆê’U–‘O‚Épool‚·‚é•ûŒü‚Åì¬
	//for (int i = 0; i < 100; ++i) {
	//	debug_anim_list_.push_back(debug_anim_);
	//}



	for (int i = 0; i < 100; ++i) {
		debug_anim_list_.emplace_back(std::make_shared<AnimSprite3D>());
	}

	int cnt = 0;
	int cnt2 = 0;
	for (auto dal : debug_anim_list_) {



		dal->regist(100, 100, "debug_anim", "graphics/effect/anim_flame.png", tnl::SeekUnit::ePlayMode::REPEAT, 1.0f, 8, 240, 0, 1);
		dal->regist(0, 1, "none", "nullptr", tnl::SeekUnit::ePlayMode::SINGLE, 0.0f, 8, 240, 0, 1);
		dal->pos_ = tnl::Vector3(cnt * 100, 0, cnt2* 100);
		cnt++;
		if (cnt % 10 == 0) {
			cnt2++;
		}
	}

	
}
