#include "gm_object_move_select_flame.h"

ObjMoveSelectFlame* ObjMoveSelectFlame::Create() {
	
	ObjMoveSelectFlame* obj = new ObjMoveSelectFlame();
	obj->parts_.resize(PartsMax);
	
//
	Parts* move_select_flame = new Parts();
	move_select_flame->mesh_ = dxe::Mesh::CreatePlaneMV(
		{ obj->getSquareSize().w,obj->getSquareSize().h,0 });
	move_select_flame->mesh_->setTexture(dxe::Texture::CreateFromFile("graphics/tile/move_select_flame.png"));
	move_select_flame->ofs_pos_ = { 0,2,0 };
	move_select_flame->ofs_rot_ = tnl::Quaternion::RotationAxis({ 1, 0, 0 }, tnl::ToRadian(90));

	obj->parts_[MoveSelectFlame] = move_select_flame;

	obj->Update(0);
	return obj;

}
