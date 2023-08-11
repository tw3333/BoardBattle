#include "gm_scene_battle.h"
#include "../gm_object_manager.h"

#include "../gm_slime_behavior_strategy.h"
#include <queue>

#include <random>     // for std::default_random_engine and std::uniform_int_distribution
#include <algorithm>  // for std::shuffle
#include <chrono>     // for std::chrono::system_clock
#include <vector>     // for std::vector
#include <numeric> 

void SceneBattle::Initialzie() {
//---
	camera_ = new SceneBattleCamera();

	sound_mgr_.PlayBattleBGM(1);

//---
	card_play_= new CardPlay();

	//Board�̍쐬

	board_ = new Board();
	board_->Create(); //Square��10x10�쐬
	board_->SetCamera(camera_);

	//Unit�̍쐬
	party_[0] = new UnitAlly(allydata_mgr_->GetAllyDataAtID(1), 5, 1);
	party_[1] = new UnitAlly(allydata_mgr_->GetAllyDataAtID(2), 5, 2);
	party_[2] = new UnitAlly(allydata_mgr_->GetAllyDataAtID(3), 5, 3);

	for (int i = 0; i < 3; ++i) {
		party_[i]->SetBaseDeck(cmgr_.GetDebugDeck());
		party_[i]->SetUseDeck(cmgr_.GetDebugDeck());
		party_[i]->AssignSerialNumberToUseDeck();
		party_[i]->ShuffleUseDeck();

	}

	party_[0]->SetTauntValue(500);
	party_units_.push_back(party_[0]);
	party_units_.push_back(party_[1]);
	party_units_.push_back(party_[2]);


	unit_enemy_ = new UnitEnemy(enemydata_mgr_->GetEnemyDataAtID(1), 5, 5);
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

	//UI�̍쐬
	select_square_ = new SelectSquare(board_->getBoardSquares());


	ui_mediator_ = new UISceneBattleMediator();
	ui_mediator_->SetScene(this);
	ui_mediator_->SetSequence(&phase_);
	
	ui_action_buttons_ = new UIPlayerActionButtons(w1*2,h1*7 + (h1 * 1 / 2),w1*2 - w1*1/2,h1*2 + (h1 * 1 / 2));
	ui_action_buttons_->SetMediator(ui_mediator_);
	ui_action_buttons_->SetMediators();

	//ui_card_ = new UICard(w1*7, h1 * 7 + (h1/2), w1 * 1 + (w1/2/2/2), h1 * 2 + (h1 / 2));
	//ui_card_->SetCardPtr(cmgr_.GetDebugDeck()[0]);
	ui_card_hand_ = new UICardHand(ui_action_buttons_->GetEndPosX(), h1 * 7 + (h1 / 2), 0, 0);
	//ui_card_hand_->Update(0);
	
	ui_turn_ally_state_ = new UITurnAllyState(0, h1 * 7 + (h1 * 1 / 2), w1 * 2, h1 * 2 + (h1 * 1 / 2));
	ui_turn_ally_state_->SetUnitAlly(turn_ally_);
	ui_turn_ally_state_->Update(0);

	ui_notice_target_box_ = new UINoticeTargetBox(w1 * 4, h1 * 1 - 15, w1 * 2, h1 * 1 / 2);

	ui_unit_state_view_ = new UIUnitStateView(0,0);

	ui_turn_view_ = new UITurnView(w1*4,0,w1*2,h1*1/2,all_units_);

	board_->Update(0);

	anim_mgr_.GetDebugAnim()->setCurrentAnim("none");
	


	//card_play_->SetCameraToCardEffectAnim(camera_);


}

void SceneBattle::Update(float delta_time) {
	phase_.update(delta_time);
	
	GetMousePoint(&debug_mp_x,&debug_mp_y);
	msv_ = tnl::Input::GetMousePosition(); 
	board_->Update(delta_time);
	select_square_->Update(delta_time, camera_);

	ui_turn_ally_state_->SetUnitAlly(turn_ally_);

	party_[0]->GetObj()->Update(delta_time);
	party_[1]->GetObj()->Update(delta_time);
	party_[2]->GetObj()->Update(delta_time);
	unit_enemy_->GetObj()->Update(delta_time);

	obj_target_circle_->Update(delta_time);

	//card_play_->SetCameraToCardEffectAnim(camera_);
	//card_play_->Update(delta_time);

	//UI
	ui_action_buttons_->Update(delta_time);
	ui_turn_view_->Update(delta_time);

	ui_turn_ally_state_->Update(delta_time);
	ui_unit_state_view_->Update(delta_time);
	ui_unit_state_view_->UpdateSelectSquare(select_square_->GetSelectSquare());

	//ui_card_->Update(delta_time);
	ui_card_hand_->SetTurnAlly(turn_ally_);
	ui_card_hand_->Update(delta_time);

	anim_mgr_.GetDebugAnim()->SetCamera(camera_);
	anim_mgr_.GetDebugAnim()->Update(delta_time);

	
	

	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_W)) {
		anim_mgr_.GetDebugAnim()->setCurrentAnim("debug_anim");
	
		anim_mgr_.GetDebugAnim()->getCurrentAnimSeekUnit()->jumpSeekRate(0);

		anim_mgr_.GetDebugAnim()->getCurrentAnimSeekUnit()->play();
	}

	//phase_.update(delta_time);
}

void SceneBattle::Render() {

	camera_->Update();
	//DrawExtendGraph(0,0,DXE_WINDOW_WIDTH,DXE_WINDOW_HEIGHT,back_,false);
	DrawDebugLayOut(true);
	//DrawStringEx(0, 0, -1, "SceneBattle");

	party_[0]->GetObj()->Render(camera_);
	party_[1]->GetObj()->Render(camera_);
	party_[2]->GetObj()->Render(camera_);
	unit_enemy_->GetObj()->Render(camera_);

	board_->Render(camera_);
	select_square_->Render(camera_);

	obj_target_circle_->Render(camera_);

	//UI
	ui_action_buttons_->Render();
	ui_turn_ally_state_->Render();
	ui_unit_state_view_->Render();
	ui_turn_view_->Render();
	ui_notice_target_box_->Render();
	//ui_card_->Render();
	ui_card_hand_->Render();

	card_play_->Render(camera_);

	anim_mgr_.GetDebugAnim()->Render(camera_);

	ui_notice_target_box_->Render();
}


//=====�����o�֐��Q====================================================================

void SceneBattle::DrawDebugLayOut(bool is_draw) {

	DrawStringEx(w1*8,0,-1,"camera.pos.x:%f",camera_->pos_.x);
	DrawStringEx(w1 * 8, 20, -1, "camera.pos.y:%f", camera_->pos_.y);
	DrawStringEx(w1 * 8, 40, -1, "camera.pos.z:%f", camera_->pos_.z);
	DrawStringEx(w1*8,60,-1,"MouseX:%d", debug_mp_x);
	DrawStringEx(w1 * 8, 80, -1, "MouseY:%d", debug_mp_y);
	DrawStringEx(w1*8,100,-1,"selectsquare[%d][%d]",select_square_->GetSelectSquareRow(),select_square_->GetSelectSquareCol());

	DrawStringEx(w1*8,120,-1,"party1decknum:%d",party_[0]->GetUseDeck().size());
	DrawStringEx(w1 * 8, 140, -1, "party2decknum:%d", party_[1]->GetUseDeck().size());
	DrawStringEx(w1 * 8, 160, -1, "party3decknum:%d", party_[2]->GetUseDeck().size());

	DrawStringEx(w1 * 8, 180, -1, "party1handnum:%d", party_[0]->GetHand().size());
	DrawStringEx(w1 * 8, 200, -1, "party2handnum:%d", party_[1]->GetHand().size());
	DrawStringEx(w1 * 8, 220, -1, "party3handnum:%d", party_[2]->GetHand().size());


	//DrawStringEx(w1 * 8, 100, -1, "square[5][5]:beginposX:%f",square_->getObj()->getBeginPos().x);
	//DrawStringEx(w1 * 8, 120, -1, "selectSquare[%d][%d]",ss_->getSelectSquareRow(),ss_->getSelectSquareCol());

		for (int i = 0; i < 10; ++i) {
			DrawLine(0, h1 + h1 * i, DXE_WINDOW_WIDTH, h1 + h1 * i, -1);
			DrawLine(w1 + w1 * i, 0, w1 + w1 * i, DXE_WINDOW_HEIGHT, -1);
		}
	

	//DrawGridGround(camera_, 50, 20);

	//Board�̃O���b�g��
	for (int i = 0; i <= 10; ++i) {

		float mas_x = (w1 * 8) / 10;
		float mas_z = (h1 * 8) / 10;

		DrawLine3D({0,0,0 + (mas_z * i)}, {float(w1 * 8),0,0 + (mas_z * i)}, gray_);
		DrawLine3D({0 + (mas_x * i),0,0}, {0 + (mas_x * i),0,(float)(h1 * 8)}, gray_);
	}

}

//�ePhase�̎���=======================================================================================================
//�퓬�J�n���̃^�[������
bool SceneBattle::PhaseInitialTurnCal(const float delta_time) {

	//�f�������ɍ~���\�[�g
	std::sort(all_units_.begin(), all_units_.end(), [](Unit* a, Unit* b) {
		return a->GetSpeed() > b->GetSpeed();
	});

	turn_unit_ = all_units_.front();

	//turn_unit���L���X�g�B�Ή�����Phase�Ɉڍs
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


//
bool SceneBattle::TurnCal(const float delta_time) {

	turn_count_ += 1;
	turn_unit_ = nullptr;

	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {

			board_->getBoardSquare(i, j)->getObj()->parts_[ObjSquare::RangeTile]->is_render_ = false;

		}
	}
	
	
	//�f�������ɍ~���\�[�g
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
			continue;  // nullptr�̗v�f���X�L�b�v����
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

	ui_card_hand_->SetAllyHand(turn_ally_->GetHand());

	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_0)) {
		phase_.change(&SceneBattle::PhaseDebug);

	}


	return true;
}

//�G�̃^�[������
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


//Move����
bool SceneBattle::PhasePlayerActionMove(const float delta_time) {
	
	DrawStringEx(500,0,-1,"PhasePlayerActionMove");
	
	// �ړ���̃}�X���擾
	int target_row = select_square_->GetSelectSquareRow();
	int target_col = select_square_->GetSelectSquareCol();

	int ally_row = turn_ally_->GetBoardPos().row;
	int ally_col = turn_ally_->GetBoardPos().col;

	board_->getBoardSquare(ally_row,ally_col)->getObj()->parts_[ObjSquare::RangeTile]->is_render_ = false;

	// �ړ��\�Ȕ͈͂��擾
	std::array<std::array<int, 10>, 10> reachable = GetReachableSquares(turn_ally_);

	//�ړ��R�X�g���`�F�b�N
	int move_cost = turn_ally_->GetCurrentMoveCost();

	if (!select_square_->IsSelectFlameOutOfBoard(msv_)) {

		if (tnl::Input::IsMouseTrigger(eMouseTrigger::IN_LEFT)) {

			// �ړ��悪�ړ��\�Ȕ͈͓��ł��邩�`�F�b�N
			if (reachable[target_row][target_col] != -1) {

				//�ړ��R�X�g�����ɂȂ�Ȃ����`�F�b�N
				if (move_cost > 0) {

					turn_ally_->SetBoardPos(target_row, target_col);

					move_cost -= reachable[target_row][target_col];  // �ړ��R�X�g�����炷
					turn_ally_->SetCurrentMoveCost(move_cost);  // �ړ��R�X�g���X�V
						
				}

			}

		}

	}


	// �ړ��\�͈͂��Čv�Z
	reachable = GetReachableSquares(turn_ally_);
	// �ړ��\�͈͂̕`����X�V
	UpdateRender(reachable, turn_ally_);
	
	return true;
}

//Card��I������i�K�̏���
bool SceneBattle::PhasePlayerActionCard(const float delta_time) {
	
	DrawStringEx(500, 0, -1, "PhasePlayerActionCard");
	

	card_play_->SetSelectUICard(ui_card_hand_->GetSelectUICard());
	card_play_->SetTurnAlly(turn_ally_);


	card_play_->RenderSelectCardRange(turn_ally_, board_);
	card_play_->UpdateSelectCardGetUnitInRange(turn_ally_, all_units_);

	if (ui_card_hand_->GetSelectUICard()) {

		if (tnl::Input::IsMouseTrigger(eMouseTrigger::IN_LEFT)) {

			

			card_play_->SetPlayCard(ui_card_hand_->GetSelectUICard()->GetCardPtr());
			
			ui_card_hand_->SetEnableSelectCard(false);
			phase_.change(&SceneBattle::PhaseSpecifyPlayCardTarget);
		}


	}


	card_play_->EffectExecute();
	
	//if (tnl::Input::IsMouseTrigger(eMouseTrigger::IN_LEFT)) {
	//	turn_ally_->GetHand().erase(turn_ally_->GetHand().begin() + 1);
	//}


	return true;
}

//PhasePlayerCard�ֈڍs����O�ɃJ�[�h�������ĂȂ�������A�������s��Phase
bool SceneBattle::PhaseDrawCard(const float delta_time) {

	DrawStringEx(500, 0, -1, "PhaseDrawCard");

	//�ŏ���5���h���[����
	if (!turn_ally_->GetIsDrewInitCard()) {

		std::vector<std::shared_ptr<Card>> to_remove; //�ړ��E�폜����J�[�h�p

		//turn_ally_->GetHand().insert(turn_ally_->GetHand().end(), turn_ally_->GetUseDeck().end() -5, turn_ally_->GetUseDeck().end());
		//turn_ally_->GetUseDeck().erase(turn_ally_->GetUseDeck().end() - 5, turn_ally_->GetUseDeck().end());
		
		int cnt = 0;

		for (int i = turn_ally_->GetUseDeck().size() -1; i >= 0; --i) {
			
			if (cnt < 5) {
				turn_ally_->AddCardToHand(turn_ally_->GetUseDeck()[i]);
				to_remove.push_back(turn_ally_->GetUseDeck()[i]);

			}
			cnt++;
		}

		for (auto& card : to_remove) {
			turn_ally_->GetUseDeck().erase(std::remove(turn_ally_->GetUseDeck().begin(), turn_ally_->GetUseDeck().end(), card), turn_ally_->GetUseDeck().end());
		}

		to_remove.clear();

		turn_ally_->SetIsDrewInitCard(true);
		turn_ally_->SetIsDrew(true);
		phase_.change(&SceneBattle::PhasePlayerActionCard);
	}

	//�P���h���[����
	if (turn_ally_->GetIsDrewInitCard() && !turn_ally_->GetIsDrew() && !turn_ally_->GetUseDeck().empty()) {

		
		turn_ally_->AddCardToHand(turn_ally_->GetUseDeck().back());
		turn_ally_->GetUseDeck().pop_back();

		turn_ally_->SetIsDrew(true);
	}

	phase_.change(&SceneBattle::PhasePlayerActionCard);
	return true;
}

bool SceneBattle::PhaseSpecifyPlayCardTarget(const float delta_time) {

	if (card_play_->GetPlayCard()->GetCardData()->GetTargetType() == TargetType::AllRange) {



	}








	return true;
}

bool SceneBattle::PhaseExecutePlayCard(const float delta_time)
{






	return true;
}

bool SceneBattle::PhasePlayerActionTool(const float delta_time) {
	
	DrawStringEx(500, 0, -1, "PhasePlayerActionTool");

	
	return true;
}

bool SceneBattle::PhasePlayerActionTurnEnd(const float delta_time) {
	
	DrawStringEx(500, 0, -1, "PhasePlayerActionTurnEnd");
	ui_mediator_->SetIsPlayerActionButtonEnabled(false);

	//�eAlly��flag���Z�b�g
	turn_ally_->SetIsDrew(false);

	turn_ally_->SetIsActed(true);

	phase_.change(&SceneBattle::ResetActedCal);

	return true;
}

bool SceneBattle::PhaseDebug(const float delta_time) {

	DrawStringEx(500,0,-1,"PhaseDebug");



	return true;
}


std::array<std::array<int, 10>, 10> SceneBattle::GetReachableSquares(UnitAlly* unit) {

	// �ړ����̈ʒu���擾
	int ally_row = unit->GetBoardPos().row;
	int ally_col = unit->GetBoardPos().col;

	// �ړ��R�X�g���擾
	int move_cost = unit->GetCurrentMoveCost();


	// ���B�\�͈͂�ۑ�����񎟌��z��
	std::array<std::array<int, 10>, 10> reachable;
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			reachable[i][j] = -1; // ������
		}
	}

	if (move_cost <= 0) {
		return reachable;
	}

	// BFS�ŒT��
	std::queue<std::pair<int, int>> que;
	que.push({ ally_row, ally_col }); // �X�^�[�g�ʒu��queue�ɒǉ�
	reachable[ally_row][ally_col] = 0; // �X�^�[�g�ʒu�̃R�X�g��0

	const int dx_[4] = { 0, 1, 0, -1 };
	const int dy_[4] = { 1, 0, -1, 0 };

	while (!que.empty()) {
		auto current = que.front(); // ���ݒn�_
		que.pop();

		for (int i = 0; i < 4; ++i) { // 4�����ɑ΂��ĒT��
			int nx = current.first + dx_[i];
			int ny = current.second + dy_[i];

			// �ړ��\�͈̓`�F�b�N
			if (nx < 0 || ny < 0 || nx >= 10 || ny >= 10) {
				continue;
			}

			// �ړ��\�͈͂����K�₩�ړ��R�X�g�ȓ��Ȃ�T��
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
	// �ړ��\�͈͂̕`����X�V
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
//�J��������
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