#include "gm_object_square.h"
#include "../dxlib_ext/dxlib_ext_texture.h"

ObjSquare* ObjSquare::Create() {

	ObjSquare* obj_square = new ObjSquare();
	obj_square->parts_.resize(PartsMax);

	//dxe::Texture tex = dxe::Texture::CreateFromFile("graphics/tile/test_tile.png");

//BaseSquare
	Parts* base_square = new Parts();
	base_square->mesh_ = dxe::Mesh::CreatePlaneMV({obj_square->getSize().x,obj_square->getSize().z,0});
	base_square->mesh_->setTexture(dxe::Texture::CreateFromFile("graphics/tile/test_tile.png"));
	base_square->ofs_pos_ = { 0,1,0 };
	base_square->ofs_rot_ = tnl::Quaternion::RotationAxis({ 1, 0, 0 }, tnl::ToRadian(90));
	//base_square->mesh_->setAlpha(obj_square->alpha_);
	//base_square->mesh_->setBlendMode(obj_square->dxlib_blend_mode_);
	obj_square->parts_[BaseSquare] = base_square;

//RangeTile
	Parts* range_tile = new Parts();
	range_tile->mesh_ = dxe::Mesh::CreatePlaneMV({ obj_square->getSize().x -10,obj_square->getSize().z -10,0 });
	range_tile->mesh_->setTexture(dxe::Texture::CreateFromFile("graphics/tile/plain-square.png"));
	range_tile->ofs_pos_ = { 0,2,0 };
	range_tile->ofs_rot_ = tnl::Quaternion::RotationAxis({ 1, 0, 0 }, tnl::ToRadian(90));
	range_tile->mesh_->setAlpha(obj_square->alpha_);
	range_tile->mesh_->setBlendMode(obj_square->dxlib_blend_mode_);
	range_tile->is_render_ = false;
	obj_square->parts_[RangeTile] = range_tile;

//CandidateTie
	Parts* candidate_tile = new Parts();
	candidate_tile->mesh_ = dxe::Mesh::CreatePlaneMV({ obj_square->getSize().x - 5,obj_square->getSize().z - 5,0 });
	candidate_tile->mesh_->setTexture(dxe::Texture::CreateFromFile("graphics/tile/in_range_circle_red.png"));
	candidate_tile->ofs_pos_ = { 0,3,0 };
	candidate_tile->ofs_rot_ = tnl::Quaternion::RotationAxis({ 1, 0, 0 }, tnl::ToRadian(90));
	candidate_tile->mesh_->setAlpha(1.0);
	candidate_tile->mesh_->setBlendMode(obj_square->dxlib_blend_mode_);
	candidate_tile->is_render_ = false;
	obj_square->parts_[CandidateTile] = candidate_tile;

//TargetTile
	Parts* target_tile = new Parts();
	target_tile->mesh_ = dxe::Mesh::CreatePlaneMV({ obj_square->getSize().x - 10,obj_square->getSize().z - 10,0 });
	target_tile->mesh_->setTexture(dxe::Texture::CreateFromFile("graphics/tile/target_circle_red.png"));
	target_tile->ofs_pos_ = { 0,3,0 };
	target_tile->ofs_rot_ = tnl::Quaternion::RotationAxis({ 1, 0, 0 }, tnl::ToRadian(90));
	target_tile->mesh_->setAlpha(1.0);
	target_tile->mesh_->setBlendMode(obj_square->dxlib_blend_mode_);
	target_tile->is_render_ = true;
	obj_square->parts_[TargetTile] = target_tile;

	//obj_square->rot_ =  tnl::Quaternion::RotationAxis({ 1, 0, 0 }, tnl::ToRadian(90));
	
	obj_square->Update(0);
	return obj_square;

}

void ObjSquare::Update(float delta_time) {
	
	GameObject::Update(delta_time);
	//ObjSquareの始点x,z
	begin_pos_ = {
		pos_.x - (DXE_WINDOW_WIDTH / 10) * 8 / 10 / 2,0,
		pos_.z + (DXE_WINDOW_HEIGHT / 10) * 8 / 10 / 2
	};

	//ObjSquareの終点x,z
	end_pos_ = {
		pos_.x + (DXE_WINDOW_WIDTH / 10) * 8 / 10 / 2,0,
		pos_.z - (DXE_WINDOW_HEIGHT / 10) * 8 / 10 / 2
	};

	

	if (this->parts_[CandidateTile]->is_render_) {

		//this->parts_[CandidateTile]->ofs_rot_ *= tnl::Quaternion::RotationAxis({ 0, 1, 0 }, tnl::ToRadian(1));


	}

	if (this->parts_[TargetTile]->is_render_) {

		//this->parts_[TargetTile]->ofs_rot_ = tnl::Quaternion::RotationAxis({ 1, 0, 0 }, tnl::ToRadian(80));
		//this->parts_[TargetTile]->ofs_rot_ *= tnl::Quaternion::RotationAxis({ 0, 1, 0 }, tnl::ToRadian(-1));
		
		//const float PI = 3.14159265;

		//time_ += delta_time;

		//alpha_ = (std::sin(time_ * frequency_ * PI) + 1.0) / 2.0;
		//parts_[TargetTile]->mesh_->setAlpha(alpha_);



	}

	if (is_flashing_) {

		const float PI = 3.14159265;

		time_ += delta_time;

		alpha_ = (std::sin(time_ * frequency_ * PI) + 1.0) / 2.0;
		parts_[RangeTile]->mesh_->setAlpha(alpha_);

	}


	//GameObject::Update(delta_time);
}