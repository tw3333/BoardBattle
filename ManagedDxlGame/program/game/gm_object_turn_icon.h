#pragma once
#include "gm_object.h"

class ObjTurnIcon : public GameObject {
public:

	ObjTurnIcon() {}
	~ObjTurnIcon() {}

	enum {
		Icon,
		PartsMax
	};


	void Update(float delta_time) override;
	
	static ObjTurnIcon* Create();

private:




	
};