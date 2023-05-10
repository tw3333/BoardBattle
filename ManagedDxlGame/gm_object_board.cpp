#include "gm_object_board.h"

ObjBoard* ObjBoard::Create() {

	ObjBoard* obj_board = new ObjBoard();
	obj_board->parts_.resize(PartsMax);


	Parts* board = new Parts();
	board->mesh_ = dxe::Mesh::CreatePlaneMV({size_w_,size_h_,0 });
	board->mesh_->setTexture(dxe::Texture::CreateFromFile("graphics/512.bmp"));
	board->ofs_rot_ = tnl::Quaternion::RotationAxis({ 1, 0, 0 }, tnl::ToRadian(90));
	obj_board->parts_[Board] = board;



	return obj_board;
}

void ObjBoard::Update(float delta_time) {



}

//void ObjBoard::Render(dxe::Camera* camera) {
//
//	
//
//
//
//
//}