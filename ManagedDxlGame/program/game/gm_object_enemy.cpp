#include "gm_object_enemy.h"




void ObjEnemy::Update(float delta_time) {
	GameObject::Update(delta_time);
}

void ObjEnemy::Render(dxe::Camera* camera) {
	GameObject::Render(camera);
}

ObjEnemy* ObjEnemy::Create(EnemyData* enemydata) {
	
	ObjEnemy* obj = new ObjEnemy();
	obj->parts_.resize(PartsMax);

	//Body
	Parts* body = new Parts();
	body->mesh_ = dxe::Mesh::CreatePlane({ 80,100,0 });
	//body->mesh_->setTexture(dxe::Texture::CreateFromFile(allydata->getImgBattlePath().c_str()));
	body->mesh_->setTexture(enemydata->GetTextureBattle());
	body->ofs_pos_ = { 0,50,0 };
	body->ofs_rot_ = tnl::Quaternion::RotationAxis({ 1,0,0 }, tnl::ToRadian(20));
	body->mesh_->setAlpha(obj->alpha_);
	body->mesh_->setBlendMode(obj->dxlib_blend_mode_);
	
	
	obj->parts_[Boby] = body;

	obj->Update(0);

	return obj;

}

ObjEnemy* ObjEnemy::CreateEnemy(int id, std::string texture_path) {

	auto obj = new ObjEnemy();
	obj->SetObjEnemyID(id);

	obj->parts_.resize(PartsMax);

	//Body
	Parts* body = new Parts();
	body->mesh_ = dxe::Mesh::CreatePlane({ 80,100,0 });
	body->mesh_->setTexture(dxe::Texture::CreateFromFile(texture_path));
	body->ofs_pos_ = { 0,50,0 };
	body->ofs_rot_ = tnl::Quaternion::RotationAxis({ 1,0,0 }, tnl::ToRadian(20));
	body->mesh_->setAlpha(obj->alpha_);
	body->mesh_->setBlendMode(obj->dxlib_blend_mode_);

	obj->parts_[Boby] = body;

	obj->Update(0);

	return obj;
}

ObjEnemy* ObjEnemy::CreateObj(std::shared_ptr<EnemyData> enemydata)
{
	ObjEnemy* obj = new ObjEnemy();
	obj->parts_.resize(PartsMax);

	//Body
	Parts* body = new Parts();
	body->mesh_ = dxe::Mesh::CreatePlane({ 80,100,0 });
	//body->mesh_->setTexture(dxe::Texture::CreateFromFile(allydata->getImgBattlePath().c_str()));
	body->mesh_->setTexture(enemydata->GetTextureBattle());
	body->ofs_pos_ = { 0,50,0 };
	body->ofs_rot_ = tnl::Quaternion::RotationAxis({ 1,0,0 }, tnl::ToRadian(20));
	body->mesh_->setAlpha(obj->alpha_);
	body->mesh_->setBlendMode(obj->dxlib_blend_mode_);


	obj->parts_[Boby] = body;

	obj->Update(0);

	return obj;
}
