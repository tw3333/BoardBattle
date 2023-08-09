#include "gm_anim_manager.h"

void AnimManager::CreateDebugAnim() {

	debug_anim_->regist(100, 100, "debug_anim", "graphics/effect/anim_flame.png", tnl::SeekUnit::ePlayMode::SINGLE,1.0f,8,240,0,1);







	//ˆê’U–‘O‚Épool‚·‚é•ûŒü‚Åì¬
	for (int i = 0; i < 100; ++i) {
		debug_anim_list_.push_back(debug_anim_);
	}







}
