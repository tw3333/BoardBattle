#include "gm_scene_battle.h"

void SceneBattle::Initialzie() {

	camera_ = new SceneBattleCamera();
	camera_->target_ = { (float)w1 * 8 / 2,0,(float)h1*8/2};
	//camera_->pos_ = { 0,680,-605 };
	camera_->pos_ = { (float)w1 * 8 / 2,680,-605 };
	
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
		camera_->pos_ += tnl::Vector3::TransformCoord({ 0, 1,  0 }, camera_->rot_);
	}
	if (tnl::Input::IsKeyDown(eKeys::KB_S)) {
		camera_->pos_ += tnl::Vector3::TransformCoord({ 0, -1, 0 }, camera_->rot_);
	}

	if (tnl::Input::IsKeyDown(eKeys::KB_Q)) {
		camera_->pos_ += tnl::Vector3::TransformCoord({ 0, 0,  1 }, camera_->rot_);
	}
	if (tnl::Input::IsKeyDown(eKeys::KB_E)) {
		camera_->pos_ += tnl::Vector3::TransformCoord({ 0, 0, -1 }, camera_->rot_);
	}

	if (tnl::Input::IsKeyDown(eKeys::KB_R)) {

		camera_->rot_ *= tnl::Quaternion::RotationAxis({ 1, 0, 0 }, tnl::ToRadian(1));
	}

	if (tnl::Input::IsKeyDown(eKeys::KB_F)) {
		camera_->rot_ *= tnl::Quaternion::RotationAxis({ 1, 0, 0 }, tnl::ToRadian(-1));
	}



}

void SceneBattle::Render() {

	camera_->update();
	debug_board_obj_->render(camera_);
	
	DrawStringEx(0,0,-1,"SceneBattle");



	//test—Ìˆæ
	CardView cardview(cmgr_->getCardDateAtIndex(1));
	cardview.Render(0,0);



	DrawDebugLayOut(is_draw_debug_layout_);
	




	//DrawBox(0,0,1280,720,0,true);

}


//=====ƒƒ“ƒoŠÖ”ŒQ====================================================================

void SceneBattle::DrawDebugLayOut(bool is_draw) {

	if (is_draw) {
		for (int i = 0; i < 10; ++i) {
			DrawLine(0, h1 + h1 * i, DXE_WINDOW_WIDTH, h1 + h1 * i, -1);
			DrawLine(w1 + w1 * i, 0, w1 + w1 * i, DXE_WINDOW_HEIGHT, -1);
		}
	}

	DrawGridGround(camera_, 50, 20);

}