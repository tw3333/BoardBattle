#pragma once
#include "gm_object.h"
#include "../game/gm_data_ally.h"

//memo
//Board上に描写する

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

	ObjAlly* CreateAlly(std::string texture);
	void SetObjAllyID(int id) { ally_id_ = id; }
	const int GetObjAllyID() { return ally_id_; }

private:
	
	int ally_id_; //Objを持たせたいallyのIDを設定

	float alpha_ = 1.0f;
	int dxlib_blend_mode_ = DX_BLENDMODE_ALPHA;
	

};

