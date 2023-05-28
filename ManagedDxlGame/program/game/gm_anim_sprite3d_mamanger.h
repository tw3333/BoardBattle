#pragma once
#include "gm_anim_sprite3d.h"

class AnimSprite3DManager {
public:

	static AnimSprite3DManager& GetInstance() {
		static AnimSprite3DManager instance_;
		return instance_;
	}

	AnimSprite3DManager(const AnimSprite3DManager&) = delete;
	AnimSprite3DManager& operator=(const AnimSprite3DManager&) = delete;

	AnimSprite3DManager(const AnimSprite3DManager&&) = delete;
	AnimSprite3DManager& operator=(const AnimSprite3DManager&&) = delete;


	//member
	AnimSprite3D* Create(dxe::Camera* camera);
	



private:

	AnimSprite3DManager() = default;
	~AnimSprite3DManager() = default;

	//member

};