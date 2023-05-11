#pragma once
#include "gm_object.h"
#include "../game/gm_data_ally.h"

//memo
//Boardè„Ç…ï`é Ç∑ÇÈ

class ObjAlly : public GameObject {
public:

	ObjAlly() {}
	~ObjAlly(){}

	enum {
		Body,
		PartsMax

	};


	void Update(float delta_time) override;
	static ObjAlly* Create(AllyData* allydata);
	float getAlphaNum() { return alpha_; }
	int getDxLibBlendMode() { return dxlib_blend_mode_; }


private:

	float alpha_ = 1.0f;
	int dxlib_blend_mode_ = DX_BLENDMODE_ALPHA;




};

