#pragma once
#include "gm_anim_sprite3d.h"

class AnimManager {
public:

	static AnimManager& GetInstance() {

		static AnimManager instance;
		return instance;

	}

	//コピーコンストラクタ削除
	AnimManager(const AnimManager&) = delete;
	AnimManager& operator=(const AnimManager&) = delete;

	//ムーブコンストラクタ削除
	AnimManager(AnimManager&&) = delete;
	AnimManager& operator = (AnimManager&&) = delete;

	void CreateDebugAnim();




private:

	AnimManager() = default;
	~AnimManager() = default;

	AnimSprite3D* anim_sprite3d_ = new AnimSprite3D();



};