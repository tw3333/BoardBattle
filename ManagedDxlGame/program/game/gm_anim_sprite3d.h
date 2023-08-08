#pragma once
#include "gm_object.h"

//memo
// 改定
//コンストラクタでCameraを設定
//画像の縦割りに対応



class AnimUnit {
public:

	Shared<tnl::SeekUnit> seek_;
	Shared<dxe::Texture> texture_;
	uint32_t parts_start_index_ = 0;

};

class AnimSprite3D : public GameObject {
private:

	float alpha_ = 1.0f;
	int dxlib_blend_mode_ = DX_BLENDMODE_ALPHA;
	tnl::Vector3 mtrl_emmisive_ = { 1, 1, 1 };
	std::unordered_map<std::string, Shared<AnimUnit>> anims_;
	Shared<AnimUnit> anim_current_ = nullptr;
	dxe::Camera* billboard_target_ = nullptr;

public:
	
	//AnimSprite3D(dxe::Camera* camera) { billboard_target_ = camera; }
	AnimSprite3D() {}

	void Update(float delta_time) override;

	//Cameraのセット
	void SetCamera(dxe::Camera* camera) { billboard_target_ = camera; }

	void AnimIsRender(bool flag) { for (auto& p : this->parts_) { p->is_render_ = flag; } }
	void Play(); //Animの最後が残る対策。後で根本から修正

	//------------------------------------------------------------------------------------------
	// アニメーションの切り替え
	// arg1... 切り替えたいアニメーションの名前
	// tips... regist 関数で登録されているアニメーションに切り替える
	void setCurrentAnim(const std::string& anim_name);

	//------------------------------------------------------------------------------------------
	// アニメーションのコントローラを取得
	const Shared<tnl::SeekUnit> getCurrentAnimSeekUnit() { return anim_current_->seek_; }

	//------------------------------------------------------------------------------------------
	// １種類のアニメーション情報の登録
	// arg1... 作成される板ポリの横幅
	// arg2... 作成される板ポリの縦幅
	// arg3... 登録するアニメーションの任意の名前
	// arg4... アニメーションに使用されるテクスチャパス
	// arg5... 再生モード ( tnl::SeekUnit::ePlayMode::REPEAT 等 )
	// arg6... 全体の再生時間
	// arg7... アニメーションのフレーム数
	// arg8... 1フレームあたりの画像の高さ
	// arg9... 上から何コマ目から読み込むか
	void regist(
		const float plane_width
		, const float plane_height
		, const std::string& anim_name
		, const std::string& tex_path
		, const tnl::SeekUnit::ePlayMode play_mode
		, const float play_time
		, const uint32_t frame_num
		, const uint32_t frame_size_h
		, const uint32_t frame_start_num_h
		, const uint32_t row_num); //縦割り分割用

};