#include "gm_scene_battle.h"

void SceneBattle::Initialzie() {

	camera_ = new SceneBattleCamera();
	//camera_->rot_ *= tnl::Quaternion::RotationAxis({ 1, 0, 0 }, tnl::ToRadian(54));
	



	debug_board_obj_ = dxe::Mesh::CreatePlane({ (float)w1*8,(float)h1*8,0 });
	debug_board_obj_->setTexture(dxe::Texture::CreateFromFile("graphics/512.bmp"));
	debug_board_obj_->rot_ = tnl::Quaternion::RotationAxis({ 1, 0, 0 }, tnl::ToRadian(90));
	debug_board_obj_->pos_ = { (float)w1*8/2,0,(float)h1*8/2};
	

	cmgr_ = cmgr_->GetInstance();
	cmgr_->MakeDebugCard();
	

}

void SceneBattle::Update(float delta_time) {

	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_U)) {

		if (!is_draw_debug_layout_) {
			is_draw_debug_layout_ = true;
		}
		else if (is_draw_debug_layout_) {
			is_draw_debug_layout_ = false;
		}

		

	}

	if (tnl::Input::IsKeyDown(eKeys::KB_W)) {
		//camera_->pos_ += tnl::Vector3::TransformCoord({ 0, 1,  0 }, camera_->rot_);
		camera_->pos_.z += 1;
	}
	if (tnl::Input::IsKeyDown(eKeys::KB_S)) {
		//camera_->pos_ += tnl::Vector3::TransformCoord({ 0, -1, 0 }, camera_->rot_);
		camera_->pos_.z += -1;
	}

	if (tnl::Input::IsKeyDown(eKeys::KB_Q)) {
		//camera_->pos_ += tnl::Vector3::TransformCoord({ 0, 0,  1 }, camera_->rot_);
		camera_->pos_.y += 1;
	}
	if (tnl::Input::IsKeyDown(eKeys::KB_E)) {
		//camera_->pos_ += tnl::Vector3::TransformCoord({ 0, 0, -1 }, camera_->rot_);
		camera_->pos_.y -= 1;
	}

	if (tnl::Input::IsKeyDown(eKeys::KB_R)) {

		camera_->rot_ *= tnl::Quaternion::RotationAxis({ 1, 0, 0 }, tnl::ToRadian(1));
	}

	if (tnl::Input::IsKeyDown(eKeys::KB_F)) {
		camera_->rot_ *= tnl::Quaternion::RotationAxis({ 1, 0, 0 }, tnl::ToRadian(-1));
	}



}

void SceneBattle::Render() {

	camera_->Update();
	debug_board_obj_->render(camera_);
	
	DrawStringEx(0,0,-1,"SceneBattle");



	//test領域
	CardView cardview(cmgr_->getCardDateAtIndex(1));
	cardview.Render(w1*8,h1*7);



	DrawDebugLayOut(is_draw_debug_layout_);
	




	//DrawBox(0,0,1280,720,0,true);

}


//=====メンバ関数群====================================================================

void SceneBattle::DrawDebugLayOut(bool is_draw) {

	DrawStringEx(w1*8,0,-1,"camera.pos.x:%f",camera_->pos_.x);
	DrawStringEx(w1 * 8, 20, -1, "camera.pos.y:%f", camera_->pos_.y);
	DrawStringEx(w1 * 8, 40, -1, "camera.pos.z:%f", camera_->pos_.z);

	if (is_draw) {
		for (int i = 0; i < 10; ++i) {
			DrawLine(0, h1 + h1 * i, DXE_WINDOW_WIDTH, h1 + h1 * i, -1);
			DrawLine(w1 + w1 * i, 0, w1 + w1 * i, DXE_WINDOW_HEIGHT, -1);
		}
	}

	DrawGridGround(camera_, 50, 20);

	//Boardのグリット線
	for (int i = 0; i <= 10; ++i) {

		float mas_x = (w1 * 8) / 10;
		float mas_z = (h1 * 8) / 10;

		DrawLine3D({0,0,0 + (mas_z * i)}, {float(w1 * 8),0,0 + (mas_z * i)}, red_);
		DrawLine3D({0 + (mas_x * i),0,0}, {0 + (mas_x * i),0,(float)(h1 * 8)}, red_);




	}

}