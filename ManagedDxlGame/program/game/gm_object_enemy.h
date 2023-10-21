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

	void Update(float delta_time) override;
	void Render(dxe::Camera* camera) override;

	static ObjEnemy* Create(EnemyData* enemydata);
	static ObjEnemy* CreateEnemy(int id, std::string texture_path);
	static ObjEnemy* CreateObj(std::shared_ptr<EnemyData> enemydata);


	void SetObjEnemyID(int id) { enemy_id_ = id; }
	int GetObjEnemyId() { return enemy_id_; }


private:

	int enemy_id_; //Obj‚ğ‚½‚¹‚½‚¢enemy‚ÌID‚ğİ’è

	float alpha_ = 1.0f;
	int dxlib_blend_mode_ = DX_BLENDMODE_ALPHA;


};
