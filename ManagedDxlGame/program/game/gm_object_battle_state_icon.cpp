#include "gm_object_battle_state_icon.h"



void ObjBattleStateIcon::Update(float delta_time) {

	GameObject::Update(delta_time);
}

void ObjBattleStateIcon::Render(dxe::Camera* camera) {

	if (is_render_) {
		GameObject::Render(camera);
	}

}

//ObjBattleStateIcon* ObjBattleStateIcon::Create(std::vector<std::shared_ptr<dxe::Texture>>& battle_state_icon) {
//
//	auto obj = new ObjBattleStateIcon();
//	obj->SetBattleStateIcon(battle_state_icon);
//
//	obj->parts_.resize(PartsMax);
//	
//	Parts* icon = new Parts();
//	icon->mesh_ = dxe::Mesh::CreatePlane({50,50,0});
//	icon->mesh_->setTexture(battle_state_icon[0]);
//
//	icon->ofs_pos_ = {0,90,0};
//	
//	obj->parts_[Icon] = icon;
//
//	obj->Update(0);
//
//
//	return obj;
//}



std::shared_ptr<ObjBattleStateIcon> ObjBattleStateIcon::Create()
{
	auto obj = std::make_shared<ObjBattleStateIcon>();

	//Debug Texture
	obj->GetBattleStateIcon().push_back(dxe::Texture::CreateFromFile("graphics/ui/battlestate_icon/icon_blood.png"));

	obj->parts_.resize(PartsMax);

	Parts* icon = new Parts();
	icon->mesh_ = dxe::Mesh::CreatePlane({ 40,40,0 });
	icon->mesh_->setTexture(obj->GetBattleStateIcon()[0]);

	icon->ofs_pos_ = { -10,0,0 };
	icon->ofs_rot_ = tnl::Quaternion::RotationAxis({ 1,0,0 }, tnl::ToRadian(20));

	obj->parts_[Icon] = icon;
	obj->Update(0);


	return obj;
}

void ObjBattleStateIcon::SetIconTextute(BattleStateIcon battle_state_icon) {

	parts_[Icon]->mesh_->setTexture(battle_state_icon_[battle_state_icon]);


}

void ObjBattleStateIcon::SetObjPosToSquarePos(int row, int col) {

	int w1 = ((DXE_WINDOW_WIDTH / 10) * 8) / 10;
	int h1 = ((DXE_WINDOW_HEIGHT / 10) * 8) / 10;

	int board_w = (DXE_WINDOW_WIDTH / 10) * 8;
	int board_h = (DXE_WINDOW_HEIGHT / 10) * 8;

	this->pos_.y = 150;
	this->pos_.z = board_h - (h1 / 2) - (h1)*row + 15;
	this->pos_.x = (w1 / 2) + ((w1)*col);

	//���W�ɂ��pos.x�̒���
	if (col < 4) {
		this->pos_.x += 30;
	}


}
