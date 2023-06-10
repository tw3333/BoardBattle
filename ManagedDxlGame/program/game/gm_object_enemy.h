#pragma once
#include "gm_object.h"
#include "gm_data_enemy.h"




class ObjEnemy : public GameObject {
public:

	ObjEnemy() {}
	~ObjEnemy(){}

	enum {
		Boby,
		PartsMax
	};


	static ObjEnemy* Create(EnemyData* enemydata);
	void SetObjEnemyID(int id) { enemy_id_ = id; }
	int GetObjEnemyId() { return enemy_id_; }


private:

	int enemy_id_; //Obj‚ğ‚½‚¹‚½‚¢enemy‚ÌID‚ğİ’è

	float alpha_ = 1.0f;
	int dxlib_blend_mode_ = DX_BLENDMODE_ALPHA;


};
