#pragma once
#include "../library/tnl_vector.h"
#include "../dxlib_ext/dxlib_ext_camera.h"
#include "gm_parts.h"

//memo
//画面上に描写するオブジェクトの基底クラス

class GameObject {
public:

	GameObject(){}
	virtual ~GameObject(){
		for (auto pts : parts_) { delete pts; }
	}

	virtual void Update(float delta_time);
	virtual void Render(dxe::Camera* camera);


	tnl::Vector3 pos_;
	tnl::Quaternion rot_;
	std::vector<Parts*> parts_;


private:

	

};