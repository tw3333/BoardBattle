#include "gm_scene_battle.h"
#include "../gm_object_manager.h"

void SceneBattle::Initialzie() {
	
	camera_ = new SceneBattleCamera();
	//camera_->rot_ *= tnl::Quaternion::RotationAxis({ 1, 0, 0 }, tnl::ToRadian(54));
//debug


	sprite_ = new AnimSprite3D(camera_);
	sprite_->regist(80, 80, "walk_front", "graphics/effect/anim_shild.png",
		tnl::SeekUnit::ePlayMode::REPEAT, 1.0f, 10, 240, 0,2);
	sprite_->setCurrentAnim("walk_front");
	sprite_->pos_ = {300,30,300};

//-----

	party_[0] = new UnitAlly(1,allydata_mgr_->getAllyDataAtID(1), 0, 0);
	party_[1] = new UnitAlly(2, allydata_mgr_->getAllyDataAtID(2), 0, 1);
	party_[2] = new UnitAlly(3, allydata_mgr_->getAllyDataAtID(3), 0, 2);
	turn_unit_ = party_[0];

	unit_enemy_ = new UnitEnemy(9, enemydata_mgr_->GetEnemyDataAtID(9),5,5);
	
	all_units_.push_back(party_[0]);
	all_units_.push_back(party_[1]);
	all_units_.push_back(party_[2]);
	all_units_.push_back(unit_enemy_);




	board_ = new Board();
	board_->Create();
	board_->SetCamera(camera_);
	board_->SetParty(party_);
	board_->Update(0);

	select_square_ = new SelectSquare(board_->getBoardSquares());

	phase_player_action_move_ = 
		new PhasePlayerActionMove(party_[0], select_square_, board_->getBoardSquares());
	phase_unit_speed_cal_ = new PhaseUnitSpeedCal(all_units_,turn_ally_,turn_enemy_);
	phase_turn_ally_ = new PhaseTurnAlly();

	InitialTurnCal();

	//ChangeBattlePhase(phase_player_action_move_);

	player_action_move_ = new PlayerActionMove(board_->getBoardSquares());

	ui_mediator_ = new UISceneBattleMediator();


	ui_action_buttons_ = new UIPlayerActionButtons(w1*2,h1*7 + (h1 * 1 / 2),w1*2,h1*2 + (h1 * 1 / 2));
	ui_action_buttons_->SetMediator(ui_mediator_);
	ui_action_buttons_->SetMediators();

	ui_card_ = new UICard(w1*7, h1 * 7 + (h1/2), w1 * 1 + (w1/2/2/2), h1 * 2 + (h1 / 2));
	
	ui_turn_ally_state_ = new UITurnAllyState(0, h1 * 7 + (h1 * 1 / 2), w1 * 2, h1 * 2 + (h1 * 1 / 2));
	ui_turn_ally_state_->SetUnitAlly(turn_ally_);
	ui_turn_ally_state_->Update(0);

	//cmgr_ = cmgr_->GetInstance();
	//cmgr_->MakeDebugCard();
	


}

void SceneBattle::Update(float delta_time) {

	GetMousePoint(&debug_mp_x,&debug_mp_y);
	
	current_phase_->UpdateExecute(delta_time);

	party_[0]->getObj()->Update(delta_time);
	party_[1]->getObj()->Update(delta_time);
	party_[2]->getObj()->Update(delta_time);
	unit_enemy_->GetObj()->Update(delta_time);

	obj_target_circle_->Update(delta_time);

	sprite_->Update(delta_time);

	//UI
	ui_action_buttons_->Update(delta_time);
	//ui_hp_bar_->Update(delta_time);
	//ui_card_cost_->Update(delta_time);
	//ui_move_cost_->Update(delta_time);
	ui_turn_ally_state_->Update(delta_time);

	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_U)) {

		if (!is_draw_debug_layout_) {
			is_draw_debug_layout_ = true;
		}
		else if (is_draw_debug_layout_) {
			is_draw_debug_layout_ = false;
		}
		
		party_[0]->DecreaseCurrentHp(20);
		party_[0]->DecreaseCurrentCardCost(1);
	}

	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_D)) {

		party_[0]->DecreaseCurrentHp(20);
		party_[0]->DecreaseCurrentCardCost(1);
	}
	
	board_->Update(delta_time);
	select_square_->Update(delta_time,camera_);
	player_action_move_->Update(delta_time);

	ui_card_->Update(delta_time);

}

void SceneBattle::Render() {

	camera_->Update();
	DrawDebugLayOut(is_draw_debug_layout_);
	DrawStringEx(0, 0, -1, "SceneBattle");

	party_[0]->getObj()->Render(camera_);
	party_[1]->getObj()->Render(camera_);
	party_[2]->getObj()->Render(camera_);
	unit_enemy_->GetObj()->Render(camera_);

	board_->Render(camera_);
	current_phase_->RenderExecute(camera_);

	//UI
	ui_action_buttons_->Render();
	//ui_hp_bar_->Render();
	//ui_card_cost_->Render();
	//ui_move_cost_->Render();
	ui_turn_ally_state_->Render();

	//test領域
	sprite_->Render(camera_);
	obj_target_circle_->Render(camera_);

	
	//CardView cardview(cmgr_->getCardDateAtIndex(1));
	//cardview.Render(w1*8,h1*7);


	ui_card_->Render();
}


//=====メンバ関数群====================================================================

void SceneBattle::DrawDebugLayOut(bool is_draw) {

	DrawStringEx(w1*8,0,-1,"camera.pos.x:%f",camera_->pos_.x);
	DrawStringEx(w1 * 8, 20, -1, "camera.pos.y:%f", camera_->pos_.y);
	DrawStringEx(w1 * 8, 40, -1, "camera.pos.z:%f", camera_->pos_.z);
	DrawStringEx(w1*8,60,-1,"MouseX:%d", debug_mp_x);
	DrawStringEx(w1 * 8, 80, -1, "MouseY:%d", debug_mp_y);
	DrawStringEx(w1*8,100,-1,"selectsquare[%d][%d]",select_square_->GetSelectSquareRow(),select_square_->GetSelectSquareCol());
	//DrawStringEx(w1 * 8, 100, -1, "square[5][5]:beginposX:%f",square_->getObj()->getBeginPos().x);
	//DrawStringEx(w1 * 8, 120, -1, "selectSquare[%d][%d]",ss_->getSelectSquareRow(),ss_->getSelectSquareCol());

	if (is_draw) {
		for (int i = 0; i < 10; ++i) {
			DrawLine(0, h1 + h1 * i, DXE_WINDOW_WIDTH, h1 + h1 * i, -1);
			DrawLine(w1 + w1 * i, 0, w1 + w1 * i, DXE_WINDOW_HEIGHT, -1);
		}
	}

	//DrawGridGround(camera_, 50, 20);

	//Boardのグリット線
	for (int i = 0; i <= 10; ++i) {

		float mas_x = (w1 * 8) / 10;
		float mas_z = (h1 * 8) / 10;

		DrawLine3D({0,0,0 + (mas_z * i)}, {float(w1 * 8),0,0 + (mas_z * i)}, gray_);
		DrawLine3D({0 + (mas_x * i),0,0}, {0 + (mas_x * i),0,(float)(h1 * 8)}, gray_);
	}

}



void SceneBattle::InitialTurnCal() {

	//素早さ順に降順ソート
	std::sort(all_units_.begin(), all_units_.end(),[](Unit* a, Unit* b) {
			return a->GetSpeed() > b->GetSpeed();
	});

	turn_unit_ = all_units_.front();


	if (turn_unit_->GetUnitType() == UnitType::Ally) {
		turn_ally_ = static_cast<UnitAlly*>(turn_unit_);
		ChangeBattlePhase(phase_turn_ally_);

	}
	else if (turn_unit_->GetUnitType() == UnitType::Enemy) {
		turn_enemy_ = static_cast<UnitEnemy*>(turn_unit_);
	}


	
}

void SceneBattle::ChangeBattlePhase(BattlePhase* new_phase) {

	if (current_phase_) {
		current_phase_->EndPhase();
	}
	current_phase_ = new_phase;
	if (current_phase_) {
		current_phase_->BeginPhase();
	}

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