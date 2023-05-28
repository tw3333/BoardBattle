#include "gm_anim_sprite3d_mamanger.h"

AnimSprite3D* AnimSprite3DManager::Create(dxe::Camera* camera) {

	auto sprite = new AnimSprite3D(camera);

	sprite->regist(23,48,"shield","graphics/effect/c1_anim_down.png",
		TestSeekUnit::ePlayMode::REPEAT,1.0f,4,48,0,2);

	sprite->setCurrentAnim("shield");

	return sprite;

}