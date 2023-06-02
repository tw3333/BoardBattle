#include "gm_scene_battle.h"
#include "../gm_object_manager.h"

void SceneBattle::Initialzie() {
	
	camera_ = new SceneBattleCamera();
	//camera_->rot_ *= tnl::Quaternion::RotationAxis({ 1, 0, 0 }, tnl::ToRadian(54));
	
	//debug_board_obj_ = dxe::Mesh::CreatePlane({ (float)w1*8,(float)h1*8,0 });
	//debug_board_obj_->setTexture(dxe::Texture::CreateFromFile("graphics/512.bmp"));
	//debug_board_obj_->rot_ = tnl::Quaternion::RotationAxis({ 1, 0, 0 }, tnl::ToRadian(90));
	//debug_board_obj_->pos_ = { (float)w1*8/2,0,(float)h1*8/2};
	
	

	unit_ally_ = new UnitAlly(1,allydata_mgr_->getAllyDataAtID(1), 5, 5);
	unit_ally2_ = new UnitAlly(2,allydata_mgr_->getAllyDataAtID(1), 6, 5);
	obj_target_circle_->pos_ = unit_ally2_->getObj()->pos_;
	obj_target_circle_->pos_.z += 1;

	sprite_ = new AnimSprite3D(camera_);
	sprite_->regist(80, 80, "walk_front", "graphics/effect/anim_shild.png",
		tnl::SeekUnit::ePlayMode::REPEAT, 1.0f, 10, 240, 0,2);
	sprite_->setCurrentAnim("walk_front");
	sprite_->pos_ = {300,30,300};



	obj_board_ = ObjBoard::Create();
	//obj_ally_ = ObjAlly::Create(allydata_mgr_->getAllyDataAtID(1));
	//obj_ally_->pos_ = { 100,50,200 };

	//unit_ally_ = new UnitAlly(allydata_mgr_->getAllyDataAtID(1),5,5);
	//unit_ally_->setBoardPos(5,5);

	//square_ = new Square(5,5);

	//square_->
	
	board_ = new Board();
	board_->Create();
	ss_ = new SelectSquare(board_->getBoardSquares());

	//for (int i = 0; i < 10; ++i) {
	//	for (int j = 0; j < 10; ++j) {
	//		all_square_.push_back(new Square(i,j));

	//	}
	//}
	ui_mediator_ = new UISceneBattleMediator();
	ui_mediator_->SetSequence(&seq_);

	ui_action_buttons_ = new UIPlayerActionButtons(w1*2,h1*8,w1*2,h1*2);
	ui_action_buttons_->SetMediator(ui_mediator_);
	ui_action_buttons_->SetMediators();



	cmgr_ = cmgr_->GetInstance();
	cmgr_->MakeDebugCard();
	


}

void SceneBattle::Update(float delta_time) {

	GetMousePoint(&debug_mp_x,&debug_mp_y);
	seq_.update(delta_time);


	//unit_ally_->getObj()->Update(delta_time);
	obj_board_->Update(delta_time);
	//obj_ally_->Update(delta_time);
	//unit_ally_->Update();
	unit_ally_->getObj()->Update(delta_time);
	unit_ally2_->getObj()->Update(delta_time);
	//square_->getObj()->Update(delta_time);

	board_->Update(delta_time);
	ss_->Update(delta_time,camera_);

	obj_target_circle_->Update(delta_time);

	sprite_->Update(delta_time);
	//for (auto al : all_square_) { al->getObj()->Update(delta_time); }

	//UI
	ui_action_buttons_->Update(delta_time);

	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_U)) {

		if (!is_draw_debug_layout_) {
			is_draw_debug_layout_ = true;
		}
		else if (is_draw_debug_layout_) {
			is_draw_debug_layout_ = false;
		}

	}

	//Phase
	



}

void SceneBattle::Render() {



	camera_->Update();
	//debug_board_obj_->render(camera_);
	obj_board_->Render(camera_);
	//obj_ally_->Render(camera_);
	
	unit_ally_->getObj()->Render(camera_);
	unit_ally2_->getObj()->Render(camera_);
	//square_->getObj()->Render(camera_);

	//for (auto al : all_square_) { al->getObj()->Render(camera_); }
	board_->Render(camera_);

	DrawStringEx(0,0,-1,"SceneBattle");

	DrawDebugLayOut(is_draw_debug_layout_);
	ss_->Render(camera_);

	sprite_->Render(camera_);

	obj_target_circle_->Render(camera_);

	//UI
	ui_action_buttons_->Render();

	//test領域
	CardView cardview(cmgr_->getCardDateAtIndex(1));
	cardview.Render(w1*8,h1*7);


	//DrawBox(0,0,1280,720,0,true);

}


//=====メンバ関数群====================================================================

void SceneBattle::DrawDebugLayOut(bool is_draw) {

	DrawStringEx(w1*8,0,-1,"camera.pos.x:%f",camera_->pos_.x);
	DrawStringEx(w1 * 8, 20, -1, "camera.pos.y:%f", camera_->pos_.y);
	DrawStringEx(w1 * 8, 40, -1, "camera.pos.z:%f", camera_->pos_.z);
	DrawStringEx(w1*8,60,-1,"MouseX:%d", debug_mp_x);
	DrawStringEx(w1 * 8, 80, -1, "MouseY:%d", debug_mp_y);
	//DrawStringEx(w1 * 8, 100, -1, "square[5][5]:beginposX:%f",square_->getObj()->getBeginPos().x);
	DrawStringEx(w1 * 8, 120, -1, "selectSquare[%d][%d]",ss_->getSelectSquareRow(),ss_->getSelectSquareCol());

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

		DrawLine3D({0,0,0 + (mas_z * i)}, {float(w1 * 8),0,0 + (mas_z * i)}, gray_);
		DrawLine3D({0 + (mas_x * i),0,0}, {0 + (mas_x * i),0,(float)(h1 * 8)}, gray_);




	}

}

bool SceneBattle::PhaseSetBattle(const float delta_time) {

	DrawStringEx(500,10,-1,"SetBattle");

	return true;
}

bool SceneBattle::PhaseCard(const float delta_time) {

	DrawStringEx(500,30,-1,"PhaseCard");

	return true;
}

bool SceneBattle::PhaseMove(const float delta_time) {

	DrawStringEx(500, 30, -1, "PhaseMove");

	return true;


}
bool SceneBattle::PhaseTool(const float delta_time) {

	DrawStringEx(500, 30, -1, "PhaseTool");

	return true;


}
bool SceneBattle::PhaseTurnEnd(const float delta_time) {

	DrawStringEx(500, 30, -1, "PhaseTurnEnd");

	return true;


}

//memo
//================================================
//カメラ操作
//if (tnl::Input::IsKeyDown(eKeys::KB_W)) {
//	//camera_->pos_ += tnl::Vector3::TransformCoord({ 0, 1,  0 }, camera_->rot_);
//	camera_->pos_.z += 1;
//}
//if (tnl::Input::IsKeyDown(eKeys::KB_S)) {
//	//camera_->pos_ += tnl::Vector3::TransformCoord({ 0, -1, 0 }, camera_->rot_);
//	camera_->pos_.z += -1;
//}
//
//if (tnl::Input::IsKeyDown(eKeys::KB_Q)) {
//	//camera_->pos_ += tnl::Vector3::TransformCoord({ 0, 0,  1 }, camera_->rot_);
//	camera_->pos_.y += 1;
//}
//if (tnl::Input::IsKeyDown(eKeys::KB_E)) {
//	//camera_->pos_ += tnl::Vector3::TransformCoord({ 0, 0, -1 }, camera_->rot_);
//	camera_->pos_.y -= 1;
//}
//
//if (tnl::Input::IsKeyDown(eKeys::KB_R)) {
//
//	camera_->rot_ *= tnl::Quaternion::RotationAxis({ 1, 0, 0 }, tnl::ToRadian(1));
//}
//
//if (tnl::Input::IsKeyDown(eKeys::KB_F)) {
//	camera_->rot_ *= tnl::Quaternion::RotationAxis({ 1, 0, 0 }, tnl::ToRadian(-1));
//}

//==================================================