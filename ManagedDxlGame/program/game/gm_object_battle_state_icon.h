#pragma once
#include "gm_object.h"

enum BattleStateIcon {
	Blood,
	Poison,
	Stun,
	Snare
};


class ObjBattleStateIcon : public GameObject {
public:

	ObjBattleStateIcon() {}
	~ObjBattleStateIcon(){}

	enum {
		Icon,
		PartsMax
	};

	void Update(float delta_time) override;
	void Render(dxe::Camera* camera) override;

	static ObjBattleStateIcon* Create();



private:




};