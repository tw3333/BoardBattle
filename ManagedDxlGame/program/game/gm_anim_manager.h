#pragma once
#include "gm_anim_sprite3d.h"
#include "gm_data_board.h"

//�V���O���g��



struct CardEffectAnim {

	int id_; //Card��ID�Əƍ�����p
	std::shared_ptr<AnimSprite3D> card_effect_anim_ = std::make_shared<AnimSprite3D>();

};


class AnimManager {
public:

	static AnimManager& GetInstance() {

		static AnimManager instance;
		return instance;

	}

	//�R�s�[�R���X�g���N�^�폜
	AnimManager(const AnimManager&) = delete;
	AnimManager& operator=(const AnimManager&) = delete;

	//���[�u�R���X�g���N�^�폜
	AnimManager(AnimManager&&) = delete;
	AnimManager& operator = (AnimManager&&) = delete;

	void CreateDebugAnim();


	std::shared_ptr<AnimSprite3D>& GetDebugAnim() {	return debug_anim_; }
	std::vector<std::shared_ptr<AnimSprite3D>> GetDebugAnimList() { return debug_anim_list_; }
	std::vector<std::shared_ptr<AnimSprite3D>> GetAnim() { return anim_; }

	void AnimPlay(std::string anim_name, std::vector<SquarePos> target_pos);

private:

	AnimManager() = default;
	~AnimManager() = default;

	//AnimSprite3D* anim_sprite3d_ = new AnimSprite3D();

	std::shared_ptr<AnimSprite3D> debug_anim_ = std::make_shared<AnimSprite3D>();
	std::shared_ptr<AnimSprite3D> state_anim_  = std::make_shared<AnimSprite3D>();

	std::vector<std::shared_ptr<AnimSprite3D>> debug_anim_list_;
	std::vector<std::shared_ptr<AnimSprite3D>> card_effect_list_;
	std::vector<std::shared_ptr<AnimSprite3D>> anim_;


};