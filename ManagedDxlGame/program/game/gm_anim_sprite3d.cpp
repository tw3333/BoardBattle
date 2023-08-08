#include "gm_anim_sprite3d.h"

//--------------------------------------------------------------------------------------------------------
void AnimSprite3D::setCurrentAnim(const std::string& anim_name) {
	
	int idx = 0;

	// これまで表示していたアニメーションを非表示にする
	if (anim_current_) {
		anim_current_->seek_->stop();
		idx = anim_current_->parts_start_index_ + anim_current_->seek_->getSeekFrame(tnl::SeekUnit::eFrameType::CURRENT);
		parts_[idx]->is_render_ = false;
	}

	// 現在のアニメーションを更新して再生
	anim_current_ = anims_[anim_name];
	idx = anim_current_->parts_start_index_;

	for (int i = 0; i < anim_current_->seek_->getTotalFrameNum(); ++i) {
		parts_[idx + i]->mesh_->setAlpha(alpha_);
		parts_[idx + i]->mesh_->setBlendMode(dxlib_blend_mode_);
		parts_[idx + i]->mesh_->setMtrlEmissive(mtrl_emmisive_);
	}

	idx += anim_current_->seek_->getSeekFrame(tnl::SeekUnit::eFrameType::CURRENT);
	parts_[idx]->is_render_ = true;
	anim_current_->seek_->play();

}


//--------------------------------------------------------------------------------------------------------
void AnimSprite3D::Update(float delta_time) {

	if (anim_current_->seek_->GetIsPlaying()) {
		// 更新前のフレームを非表示にする
		int idx = anim_current_->parts_start_index_ + anim_current_->seek_->getSeekFrame(tnl::SeekUnit::eFrameType::CURRENT);
		parts_[idx]->is_render_ = false;

		// アニメーションのフレームを更新
		anim_current_->seek_->update(delta_time);

		// 新しいフレームを表示状態にする
		idx = anim_current_->parts_start_index_ + anim_current_->seek_->getSeekFrame(tnl::SeekUnit::eFrameType::CURRENT);
		parts_[idx]->is_render_ = true;

		// パーツ座標の更新
		parts_[idx]->mesh_->pos_ = pos_;
		parts_[idx]->mesh_->rot_ = tnl::Quaternion::LookAtAxisY(billboard_target_->pos_, billboard_target_->target_);
		parts_[idx]->mesh_->rot_ = tnl::Quaternion::RotationAxis({ 1,0,0 }, tnl::ToRadian(20));
	}
	else if(!anim_current_->seek_->GetIsPlaying())  {

		for (auto p : this->parts_) {
			p->is_render_ = false;
		}
	}



	//// パーツ座標の更新
	//parts_[idx]->mesh_->pos_ = pos_;
	//parts_[idx]->mesh_->rot_ = tnl::Quaternion::LookAtAxisY(billboard_target_->pos_, billboard_target_->target_);
	//parts_[idx]->mesh_->rot_ = tnl::Quaternion::RotationAxis({ 1,0,0 }, tnl::ToRadian(20));

	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_W)) {
		this->AnimIsRender(false);
	}


}

//--------------------------------------------------------------------------------------------------------
void AnimSprite3D::regist(
	const float plane_width
	, const float plane_height
	, const std::string& anim_name
	, const std::string& tex_path
	, const tnl::SeekUnit::ePlayMode play_mode
	, const float play_time
	, const uint32_t frame_num
	, const uint32_t frame_size_h
	, const uint32_t frame_start_num_h
	, const uint32_t row_num) //縦分分割に対応するために追加
{
	// １種類のアニメーション情報を作成
	Shared<AnimUnit> unit = std::make_shared<AnimUnit>();
	unit->seek_ = tnl::SeekUnit::Create(60, play_time, frame_num, play_mode, tnl::SeekUnit::ePlayDir::FORWARD);
	unit->texture_ = dxe::Texture::CreateFromFile(tex_path);
	unit->parts_start_index_ = parts_.size();
	anims_[anim_name] = unit;

	int img_w, img_h;
	GetGraphSize(unit->texture_->getDxLibGraphHandle(), &img_w, &img_h);

	// フレーム毎にパーツを作成
	//float sv = (float)frame_start_num_h / (float)img_h;
	//float ev = (float)(frame_start_num_h + frame_size_h) / (float)img_h;

	uint32_t frames_per_row = frame_num / row_num;

	for (int i = 0; i < frame_num; ++i) {

		int row = i / frames_per_row;
		int col = i % frames_per_row;

		float su = (float)col / (float)frames_per_row;
		float eu = (float)(col + 1) / (float)frames_per_row;

		float sv = (float)row / (float)row_num;
		float ev = (float)(row + 1) / (float)row_num;

		Parts* parts = new Parts();
		//parts->mesh_ = dxe::Mesh::CreatePlaneMV(
		//	{ plane_width, plane_height, 0 }, 1, 1, true, 
		//	{ (float)i / (float)frame_num, sv, 0 }, { float(i+1) / (float)frame_num, ev, 0 });
		parts->mesh_ = dxe::Mesh::CreatePlaneMV(
			{ plane_width, plane_height, 0 }, 1, 1, true,
			{ su, sv, 0 }, { eu, ev, 0 });

		parts->mesh_->setTexture(unit->texture_);
		parts->mesh_->setDefaultLightEnable(false);
		parts_.emplace_back(parts);
		parts_[unit->parts_start_index_ + i]->is_render_ = false;

	}

}