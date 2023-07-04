#include "gm_scene_battle.h"
#include "../gm_object_manager.h"

#include "../gm_slime_behavior_strategy.h"
#include <queue>

void SceneBattle::Initialzie() {
//---
	camera_ = new SceneBattleCamera();

//---
	//Boardの作成
	board_ = new Board();
	board_->Create(); //Squareを10x10作成
	board_->SetCamera(camera_);

	//Unitの作成
	party_[0] = new UnitAlly(1, allydata_mgr_->getAllyDataAtID(1), 0, 0);
	party_[1] = new UnitAlly(2, allydata_mgr_->getAllyDataAtID(2), 0, 1);
	party_[2] = new UnitAlly(3, allydata_mgr_->getAllyDataAtID(3), 0, 2);
	party_[0]->SetTauntValue(500);
	party_units_.push_back(party_[0]);
	party_units_.push_back(party_[1]);
	party_units_.push_back(party_[2]);


	unit_enemy_ = new UnitEnemy(9, enemydata_mgr_->GetEnemyDataAtID(9), 5, 5);
	enemy_units_.push_back(unit_enemy_);

	all_units_.reserve(party_units_.size() + enemy_units_.size());
	all_units_.insert(all_units_.end(), party_units_.begin(), party_units_.end());
	all_units_.insert(all_units_.end(), enemy_units_.begin(), enemy_units_.end());

	board_->SetParty(party_);
	board_->SetPartyUnits(party_units_);
	board_->SetEnemyUnits(enemy_units_);
	board_->SetAllUnits(all_units_);

	EnemyBehaviorStrategy* newBehavior = new SlimeBehaviorStrategy();
	unit_enemy_->SetBehavior(newBehavior);
	

	obj_target_circle_->pos_ = board_->getBoardSquare(4,4)->getObj()->pos_;

	//UIの作成
	select_square_ = new SelectSquare(board_->getBoardSquares());

	ui_mediator_ = new UISceneBattleMediator();
	ui_mediator_->SetScene(this);
	ui_mediator_->SetSequence(&phase_);
	
	ui_action_buttons_ = new UIPlayerActionButtons(w1*2,h1*7 + (h1 * 1 / 2),w1*2 - w1*1/2,h1*2 + (h1 * 1 / 2));
	ui_action_buttons_->SetMediator(ui_mediator_);
	ui_action_buttons_->SetMediators();

	ui_card_ = new UICard(w1*7, h1 * 7 + (h1/2), w1 * 1 + (w1/2/2/2), h1 * 2 + (h1 / 2));
	
	ui_turn_ally_state_ = new UITurnAllyState(0, h1 * 7 + (h1 * 1 / 2), w1 * 2, h1 * 2 + (h1 * 1 / 2));
	ui_turn_ally_state_->SetUnitAlly(turn_ally_);
	ui_turn_ally_state_->Update(0);

	ui_turn_view_ = new UITurnView(w1*4,0,w1*2,h1*1/2,all_units_);

	board_->Update(0);
}

void SceneBattle::Update(float delta_time) {

	GetMousePoint(&debug_mp_x,&debug_mp_y);
	msv_ = tnl::Input::GetMousePosition(); 
	board_->Update(delta_time);
	select_square_->Update(delta_time, camera_);

	ui_turn_ally_state_->SetUnitAlly(turn_ally_);

	party_[0]->getObj()->Update(delta_time);
	party_[1]->getObj()->Update(delta_time);
	party_[2]->getObj()->Update(delta_time);
	unit_enemy_->GetObj()->Update(delta_time);

	obj_target_circle_->Update(delta_time);

	//UI
	ui_action_buttons_->Update(delta_time);
	ui_turn_view_->Update(delta_time);

	ui_turn_ally_state_->Update(delta_time);
	ui_card_->Update(delta_time);

	phase_.update(delta_time);

	
}

void SceneBattle::Render() {

	camera_->Update();
	//DrawExtendGraph(0,0,DXE_WINDOW_WIDTH,DXE_WINDOW_HEIGHT,back_,false);
	DrawDebugLayOut(is_draw_debug_layout_);
	//DrawStringEx(0, 0, -1, "SceneBattle");

	party_[0]->getObj()->Render(camera_);
	party_[1]->getObj()->Render(camera_);
	party_[2]->getObj()->Render(camera_);
	unit_enemy_->GetObj()->Render(camera_);

	board_->Render(camera_);

	obj_target_circle_->Render(camera_);

	//UI
	ui_action_buttons_->Render();
	ui_turn_ally_state_->Render();
	ui_turn_view_->Render();
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

		for (int i = 0; i < 10; ++i) {
			DrawLine(0, h1 + h1 * i, DXE_WINDOW_WIDTH, h1 + h1 * i, -1);
			DrawLine(w1 + w1 * i, 0, w1 + w1 * i, DXE_WINDOW_HEIGHT, -1);
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

//各Phaseの実装=====================================================================================

void SceneBattle::InitialTurnCal() {

	turn_count_ += 1;

	//素早さ順に降順ソート
	std::sort(all_units_.begin(), all_units_.end(),[](Unit* a, Unit* b) {
			return a->GetSpeed() > b->GetSpeed();
	});

	turn_unit_ = all_units_.front();


	if (turn_unit_->GetUnitType() == UnitType::Ally) {
		turn_ally_ = static_cast<UnitAlly*>(turn_unit_);
		phase_.change(&SceneBattle::PhaseAllyTurn);

	}
	else if (turn_unit_->GetUnitType() == UnitType::Enemy) {
		turn_enemy_ = static_cast<UnitEnemy*>(turn_unit_);

		phase_.change(&SceneBattle::PhaseEnemyTurn);
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

bool SceneBattle::PhaseInitialTurnCal(const float delta_time) {

	//素早さ順に降順ソート
	std::sort(all_units_.begin(), all_units_.end(), [](Unit* a, Unit* b) {
		return a->GetSpeed() > b->GetSpeed();
	});

	turn_unit_ = all_units_.front();


	if (turn_unit_->GetUnitType() == UnitType::Ally) {
		turn_ally_ = static_cast<UnitAlly*>(turn_unit_);
		
		phase_.change(&SceneBattle::PhaseAllyTurn);
	}
	else if (turn_unit_->GetUnitType() == UnitType::Enemy) {
		turn_enemy_ = static_cast<UnitEnemy*>(turn_unit_);

		phase_.change(&SceneBattle::PhaseEnemyTurn);
	}



	return true;
}

bool SceneBattle::TurnCal(const float delta_time) {

	turn_count_ += 1;
	turn_unit_ = nullptr;

	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {

			board_->getBoardSquare(i, j)->getObj()->parts_[ObjSquare::RangeTile]->is_render_ = false;

		}
	}
	
	
	//素早さ順に降順ソート
	std::sort(all_units_.begin(), all_units_.end(), [](Unit* a, Unit* b) {
		return a->GetSpeed() > b->GetSpeed();
	});


	for (auto au : all_units_) {

		if (!au->GetIsActed() && !au->GetIsDead()) {
			active_units_.push_back(au);
			if (!turn_unit_ || au->GetSpeed() > turn_unit_->GetSpeed()) {
		
				turn_unit_ = au;

			}
		}
	}

	if (turn_unit_->GetUnitType() == UnitType::Ally) {
		turn_ally_ = static_cast<UnitAlly*>(turn_unit_);
		phase_.change(&SceneBattle::PhaseAllyTurn);
	}
	else if (turn_unit_->GetUnitType() == UnitType::Enemy) {
		turn_enemy_ = static_cast<UnitEnemy*>(turn_unit_);

		phase_.change(&SceneBattle::PhaseEnemyTurn);
	}

	return true;
}

bool SceneBattle::ResetActedCal(const float delta_time)
{
	DrawStringEx(0,500,-1,"ResetActedCal");
	active_units_.clear();

	bool all_acted = true;

	for (auto au : all_units_) {

		if (!au) {
			continue;  // nullptrの要素をスキップする
		}

		if (!au->GetIsActed()) {
			all_acted = false;
			break;
		}

	}

	if (all_acted) {
		for (auto au : all_units_) {
			if (au) {
				au->SetIsActed(false);
			}
		}

		for (auto pu : party_units_) {

			pu->SetCurrentMoveCost(pu->GetMaxMoveCost());

		}

		for (auto eu : enemy_units_) {
			eu->SetCurrentMoveCost(eu->GetCurrentMoveCost());

		}
	}

	reset_acted_ = false;
	phase_.change(&SceneBattle::TurnCal);
	return true;
}

bool SceneBattle::PhaseAllyTurn(const float delta_time)
{
	DrawStringEx(500,0,-1,"PhaseTurnAlly");
	ui_mediator_->SetIsPlayerActionButtonEnabled(true);

	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_0)) {
		phase_.change(&SceneBattle::PhaseDebug);

	}


	return true;
}

//敵のターン処理
bool SceneBattle::PhaseEnemyTurn(const float delta_time) {
	
	DrawStringEx(500, 0, -1, "PhaseTurnEnemy");

	turn_enemy_->Move(board_);
	turn_enemy_->Act(board_);

	turn_enemy_->SetIsActed(true);
	phase_.change(&SceneBattle::ResetActedCal);

	//if (tnl::Input::IsKeyDownTrigger(eKeys::KB_0)) {
	//	phase_.change(&SceneBattle::ResetActedCal);

	//}

	return true;
}

bool SceneBattle::PhasePlayerActionMove(const float delta_time) {
	
	DrawStringEx(500,0,-1,"PhasePlayerActionMove");
	
	// 移動先のマスを取得
	int target_row = select_square_->GetSelectSquareRow();
	int target_col = select_square_->GetSelectSquareCol();

	int ally_row = turn_ally_->GetBoardPos().row;
	int ally_col = turn_ally_->GetBoardPos().col;

	board_->getBoardSquare(ally_row,ally_col)->getObj()->parts_[ObjSquare::RangeTile]->is_render_ = false;

	// 移動可能な範囲を取得
	std::array<std::array<int, 10>, 10> reachable = GetReachableSquares(turn_ally_);

	//移動コストをチェック
	int move_cost = turn_ally_->GetCurrentMoveCost();

	if (!select_square_->IsSelectFlameOutOfBoard(msv_)) {

		if (tnl::Input::IsMouseTrigger(eMouseTrigger::IN_LEFT)) {

			// 移動先が移動可能な範囲内であるかチェック
			if (reachable[target_row][target_col] != -1) {

				//移動コストが負にならないかチェック
				if (move_cost > 0) {

					turn_ally_->SetBoardPos(target_row, target_col);

					move_cost -= reachable[target_row][target_col];  // 移動コストを減らす
					turn_ally_->SetCurrentMoveCost(move_cost);  // 移動コストを更新
						
				}

			}

		}

	}


	// 移動可能範囲を再計算
	reachable = GetReachableSquares(turn_ally_);
	// 移動可能範囲の描画を更新
	UpdateRender(reachable, turn_ally_);
	
	return true;
}

bool SceneBattle::PhasePlayerActionCard(const float delta_time) {
	
	DrawStringEx(500, 0, -1, "PhasePlayerActionCard");

	
	return true;
}

bool SceneBattle::PhasePlayerActionTool(const float delta_time) {
	
	DrawStringEx(500, 0, -1, "PhasePlayerActionTool");

	
	return true;
}

bool SceneBattle::PhasePlayerActionTurnEnd(const float delta_time) {
	
	DrawStringEx(500, 0, -1, "PhasePlayerActionTurnEnd");
	ui_mediator_->SetIsPlayerActionButtonEnabled(false);

	turn_ally_->SetIsActed(true);


	phase_.change(&SceneBattle::ResetActedCal);


	
	return true;
}

bool SceneBattle::PhaseDebug(const float delta_time) {

	DrawStringEx(500,0,-1,"PhaseDebug");



	return true;
}


std::array<std::array<int, 10>, 10> SceneBattle::GetReachableSquares(UnitAlly* unit) {

	// 移動元の位置を取得
	int ally_row = unit->GetBoardPos().row;
	int ally_col = unit->GetBoardPos().col;

	// 移動コストを取得
	int move_cost = unit->GetCurrentMoveCost();


	// 到達可能範囲を保存する二次元配列
	std::array<std::array<int, 10>, 10> reachable;
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			reachable[i][j] = -1; // 初期化
		}
	}

	if (move_cost <= 0) {
		return reachable;
	}

	// BFSで探索
	std::queue<std::pair<int, int>> que;
	que.push({ ally_row, ally_col }); // スタート位置をqueueに追加
	reachable[ally_row][ally_col] = 0; // スタート位置のコストは0

	const int dx_[4] = { 0, 1, 0, -1 };
	const int dy_[4] = { 1, 0, -1, 0 };

	while (!que.empty()) {
		auto current = que.front(); // 現在地点
		que.pop();

		for (int i = 0; i < 4; ++i) { // 4方向に対して探索
			int nx = current.first + dx_[i];
			int ny = current.second + dy_[i];

			// 移動可能範囲チェック
			if (nx < 0 || ny < 0 || nx >= 10 || ny >= 10) {
				continue;
			}

			// 移動可能範囲かつ未訪問かつ移動コスト以内なら探索
			if (reachable[nx][ny] == -1 && reachable[current.first][current.second] + 1 <= move_cost
				&& board_->getBoardSquare(nx,ny)->GetIsCanMove()) {
				reachable[nx][ny] = reachable[current.first][current.second] + 1;
				que.push({ nx, ny });
			}
		}
	}

	return reachable;
}

void SceneBattle::UpdateRender(std::array<std::array<int, 10>, 10> reachable, UnitAlly* unit)
{
	// 移動可能範囲の描画を更新
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			if ((i != unit->GetBoardPos().row || j != unit->GetBoardPos().col) && reachable[i][j] != -1) {
				board_->getBoardSquare(i,j)->getObj()->parts_[ObjSquare::RangeTile]->is_render_ = true;
			}
			else {

				board_->getBoardSquare(i,j)->getObj()->parts_[ObjSquare::RangeTile]->is_render_ = false;
			}
		}
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