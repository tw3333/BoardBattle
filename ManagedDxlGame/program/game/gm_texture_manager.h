#pragma once
#include "../dxlib_ext/dxlib_ext.h"

//memo
//シングルトン設計

class TextureManager {
public:

	static TextureManager* GetInstance();
	static void Destory();

	Shared<dxe::Texture> selectphase_back1_;
	int selectphase_back1_img_ = 0;

	
	void LoadTexture();

private:

	TextureManager() {};
	~TextureManager() {};

	static TextureManager* instance_;

	



};