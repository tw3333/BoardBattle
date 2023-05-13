#include "gm_object_square.h"

ObjSquare* ObjSquare::Create() {

	ObjSquare* obj_square = new ObjSquare();
	obj_square->parts_.resize(PartsMax);

	Parts* base_square = new Parts();
	base_square->mesh_ = dxe::Mesh::CreatePlaneMV({obj_square->getSquareSize().w,obj_square->getSquareSize().h,0});
	base_square->mesh_->setTexture(dxe::Texture::CreateFromFile("graphics/tile/test_tile.png"));
	base_square->mesh_->pos_ = {0,1,0};
	base_square->ofs_rot_ = tnl::Quaternion::RotationAxis({ 1, 0, 0 }, tnl::ToRadian(90));
	
	obj_square->parts_[BaseSquare] = base_square;

	obj_square->Update(0);
	return obj_square;

}

void ObjSquare::Update(float delta_time) {

	GameObject::Update(delta_time);
}