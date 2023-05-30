#pragma once
#include "gm_object.h"

//memo




class ObjTargetCircle : public GameObject {
public:

	ObjTargetCircle(){}
	~ObjTargetCircle(){}

	enum {
		InRangeCircle,
		TargetCircle,
		PartsMax
	};

	enum class TextureColor {
		Red,
		Black,
		YellowGreen,
		DarkGreen
	};

	void Update(float delta_time) override;
	//void Render(dxe::Camera* camera) override;

	//member
	static ObjTargetCircle* Create(TextureColor color);
	void SetTextureColor(TextureColor color);


private:

	//dxe::Texture in_range_circle_ = dxe::Texture::CreateFromFile();

	struct InRangeCircleTexture {
		Shared<dxe::Texture> red = 
			dxe::Texture::CreateFromFile("graphics/tile/in_range_circle_red.png");
		Shared<dxe::Texture> black = 
			dxe::Texture::CreateFromFile("graphics/tile/in_range_circle_black.png");
		Shared<dxe::Texture> yellow_green = 
			dxe::Texture::CreateFromFile("graphics/tile/in_range_circle_yellow_green.png");
		Shared<dxe::Texture> dark_green = 
			dxe::Texture::CreateFromFile("graphics/tile/in_range_circle_dark_green.png");
	};

	struct TargetCircleTexture {
		Shared<dxe::Texture> red = 
			dxe::Texture::CreateFromFile("graphics/tile/target_circle_red.png");
		Shared<dxe::Texture> black = 
			dxe::Texture::CreateFromFile("graphics/tile/target_circle_black.png");
		Shared<dxe::Texture> yellow_green = 
			dxe::Texture::CreateFromFile("graphics/tile/target_circle_yellow_green.png");
		Shared<dxe::Texture> dark_green = 
			dxe::Texture::CreateFromFile("graphics/tile/target_circle_dark_green.png");
	};

	InRangeCircleTexture in_range_circle_color_;
	TargetCircleTexture target_circle_color_;

	Shared<dxe::Texture> current_in_range_circle_texture_;
	Shared<dxe::Texture> current_target_circle_texture_;


	float alpha_ = 1.0;
	int dxlib_blend_mode_ = DX_BLENDMODE_ALPHA;


	float time_ = 0;
	const float PI_ = 3.14159265;
	float frequency_ = 1.3; //ì_ñ≈ÇÃë¨ìxí≤êÆópïœêî
	
};