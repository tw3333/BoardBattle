#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include "gm_parts.h"


class Model {
public:

	Model() {};
	virtual ~Model() {
		for (auto pts : parts_) delete pts;
	}
	
	tnl::Vector3 pos_;
	tnl::Quaternion rot_;
	std::vector<Parts*> parts_;

	


};