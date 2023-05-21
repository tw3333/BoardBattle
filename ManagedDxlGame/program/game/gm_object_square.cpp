#include "gm_object_square.h"
#include "../dxlib_ext/dxlib_ext_texture.h"

ObjSquare* ObjSquare::Create() {

	ObjSquare* obj_square = new ObjSquare();
	obj_square->parts_.resize(PartsMax);

	//dxe::Texture tex = dxe::Texture::CreateFromFile("graphics/tile/test_tile.png");
	


	Parts* base_square = new Parts();
	base_square->mesh_ = dxe::Mesh::CreatePlaneMV({obj_square->getSize().x,obj_square->getSize().z,0});
	base_square->mesh_->setTexture(dxe::Texture::CreateFromFile("graphics/tile/test_tile.png"));
	base_square->ofs_pos_ = { 0,1,0 };
	base_square->ofs_rot_ = tnl::Quaternion::RotationAxis({ 1, 0, 0 }, tnl::ToRadian(90));
	//base_square->mesh_->setAlpha(obj_square->alpha_);
	//base_square->mesh_->setBlendMode(obj_square->dxlib_blend_mode_);


	obj_square->parts_[BaseSquare] = base_square;

	obj_square->Update(0);
	return obj_square;

}

void ObjSquare::Update(float delta_time) {

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


	GameObject::Update(delta_time);
}