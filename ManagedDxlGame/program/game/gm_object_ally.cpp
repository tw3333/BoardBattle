#include "gm_object_ally.h"

ObjAlly* ObjAlly::Create(AllyData* allydata) {

	ObjAlly* obj_ally = new ObjAlly();
	obj_ally->parts_.resize(PartsMax);

	Parts* body = new Parts();
	body->mesh_ = dxe::Mesh::CreatePlaneMV({100,100,0});
	//body->mesh_->setTexture(dxe::Texture::CreateFromFile(allydata->getImgBattlePath().c_str()));
	body->mesh_->setTexture(dxe::Texture::CreateFromFile(allydata->getImgBattlePath().c_str()));

	body->ofs_rot_ = tnl::Quaternion::RotationAxis({ 1,0,0 }, tnl::ToRadian(20));
	body->mesh_->setAlpha(obj_ally->alpha_);
	body->mesh_->setBlendMode(obj_ally->dxlib_blend_mode_);


	obj_ally->parts_[Body] = body;

	obj_ally->Update(0);

	return obj_ally;
}

void ObjAlly::Update(float delta_time) {
	GameObject::Update(delta_time);

}