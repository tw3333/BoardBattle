#include "gm_object_board.h"

ObjBoard* ObjBoard::Create() {

	ObjBoard* obj_board = new ObjBoard();
	obj_board->parts_.resize(PartsMax);


	Parts* board = new Parts();
	board->mesh_ = dxe::Mesh::CreatePlaneMV({(float)(DXE_WINDOW_WIDTH /10) *8,(float)(DXE_WINDOW_HEIGHT/10)*8,0});
	board->mesh_->setTexture(dxe::Texture::CreateFromFile("graphics/512.bmp"));
	board->ofs_rot_ = tnl::Quaternion::RotationAxis({ 1, 0, 0 }, tnl::ToRadian(90));
	//board->ofs_pos_ = { (float)DXE_WINDOW_WIDTH / 10 * 8 / 2,0,(float)DXE_WINDOW_HEIGHT / 10 * 8 / 2 };

	obj_board->parts_[Board] = board;

	//obj_board->pos_ = { (float)DXE_WINDOW_WIDTH / 10 * 8 /2,0,(float)DXE_WINDOW_HEIGHT / 10 * 8 /2 };


	obj_board->Update(0);
	return obj_board;
}

void ObjBoard::Update(float delta_time) {

	pos_ = { (float)DXE_WINDOW_WIDTH / 10 * 8 / 2,0,(float)DXE_WINDOW_HEIGHT / 10 * 8 / 2 };
	GameObject::Update(delta_time);

}

