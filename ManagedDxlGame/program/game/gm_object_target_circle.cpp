#include "gm_object_target_circle.h"

void ObjTargetCircle::Update(float delta_time) {

	GameObject::Update(delta_time);
	this->parts_[InRangeCircle]->ofs_rot_ *= tnl::Quaternion::RotationAxis({ 0, 0, 1 }, tnl::ToRadian(1));
	this->parts_[TargetCircle]->ofs_rot_ *= tnl::Quaternion::RotationAxis({ 0, 0, 1 }, tnl::ToRadian(-1));


}

//void ObjTargetCircle::Render(dxe::Camera* camera) {
//
//
//
//
//
//}

ObjTargetCircle* ObjTargetCircle::Create(TextureColor color) {

	ObjTargetCircle* obj_ = new ObjTargetCircle();
	obj_->parts_.resize(PartsMax);
	obj_->SetTextureColor(color);

//	
	Parts* in_range_circle = new Parts();
	in_range_circle->mesh_ = dxe::Mesh::CreatePlaneMV({120,120,0});
	in_range_circle->mesh_->setTexture(obj_->current_in_range_circle_texture_);
//	in_range_circle->ofs_rot_ = tnl::Quaternion::RotationAxis({ 1, 0, 0 }, tnl::ToRadian(20));
	in_range_circle->mesh_->setAlpha(obj_->alpha_);
	in_range_circle->mesh_->setBlendMode(obj_->dxlib_blend_mode_);
	in_range_circle->ofs_pos_ = { 0,50,0 };
	obj_->parts_[InRangeCircle] = in_range_circle;

//
	Parts* target_circle = new Parts();
	target_circle->mesh_ = dxe::Mesh::CreatePlaneMV({100,100,0});
	target_circle->mesh_->setTexture(obj_->current_target_circle_texture_);	
//	target_circle->ofs_rot_ = tnl::Quaternion::RotationAxis({ 1, 0, 0 }, tnl::ToRadian(20));
	target_circle->mesh_->setAlpha(obj_->alpha_);
	target_circle->mesh_->setBlendMode(obj_->dxlib_blend_mode_);
	target_circle->ofs_pos_ = { 0,50,0 };
	obj_->parts_[TargetCircle] = target_circle;

	obj_->rot_ = tnl::Quaternion::RotationAxis({ 1, 0, 0 }, tnl::ToRadian(20));
	
//

	obj_->Update(0);
	return obj_;

}

void ObjTargetCircle::SetTextureColor(TextureColor color) {

	switch (color)
	{
	case TextureColor::Red:
		current_in_range_circle_texture_ = in_range_circle_color_.red;
		current_target_circle_texture_ = target_circle_color_.red;
		break;

	case TextureColor::Black:
		current_in_range_circle_texture_ = in_range_circle_color_.black;
		current_target_circle_texture_ = target_circle_color_.black;
		break;
	
	case TextureColor::YellowGreen:
		current_in_range_circle_texture_ = in_range_circle_color_.yellow_green;
		current_target_circle_texture_ = target_circle_color_.yellow_green;
		break;

	case TextureColor::DarkGreen:
		current_in_range_circle_texture_ = in_range_circle_color_.dark_green;
		current_target_circle_texture_ = target_circle_color_.dark_green;
		break;

	default:
		break;
	}

}