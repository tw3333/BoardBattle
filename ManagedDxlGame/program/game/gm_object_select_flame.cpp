#include "gm_object_select_flame.h"

ObjSelectFlame* ObjSelectFlame::Create() {

	ObjSelectFlame* obj_select_flame = new ObjSelectFlame();
	obj_select_flame->parts_.resize(PartsMax);

	Parts* select_flame = new Parts();
	select_flame->mesh_ = dxe::Mesh::CreatePlaneMV(
		{obj_select_flame->getSquareSize().w,obj_select_flame->getSquareSize().h,0});
	select_flame->mesh_->setTexture(dxe::Texture::CreateFromFile("graphics/tile/select_flame.png"));
	select_flame->ofs_pos_ = { 0,2,0 };
	select_flame->ofs_rot_ = tnl::Quaternion::RotationAxis({ 1, 0, 0 }, tnl::ToRadian(90));
	select_flame->mesh_->setAlpha(obj_select_flame->alpha_);
	select_flame->mesh_->setBlendMode(obj_select_flame->dxlib_blend_mode_);

	obj_select_flame->parts_[SelectFlame] = select_flame;

	obj_select_flame->Update(0);
	return obj_select_flame;

}

void ObjSelectFlame::Update(float delta_time) {
	
	GameObject::Update(delta_time);

	if (is_flashing_) {

		const float PI = 3.14159265;
		
		time_ += delta_time;

		alpha_ = (std::sin(time_ * frequency_ * PI) + 1.0) / 2.0;
		parts_[SelectFlame]->mesh_->setAlpha(alpha_);

	}


}