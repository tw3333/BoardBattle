#include "gm_scene_battle.h"
#include "../gm_object_manager.h"

#include "../gm_slime_behavior_strategy.h"
#include <queue>

#include <random>     // for std::default_random_engine and std::uniform_int_distribution
#include <algorithm>  // for std::shuffle
#include <chrono>     // for std::chrono::system_clock
#include <vector>     // for std::vector
#include <numeric> 

#include "../gm_card_target.h"
#include "gm_scene_battle_result.h"
#include "gm_scene_selectphase.h"
#include "../gm_data_battle_state.h"


void SceneBattle::Initialzie() {
//---
	camera_ = new SceneBattleCamera();

	sound_mgr_.PlayBattleBGM(1);

//---



	std::setlocale(LC_ALL, "ja_JP.shiftjis");
	card_play_= new CardPlay();

	//Board�̍쐬

	board_ = new Board();
	board_->Create(); //Square��10x10�쐬
	board_->SetCamera(camera_);

	//Unit�̍쐬
	party_[0] = new UnitAlly(allydata_mgr_.GetAllyDataAtID(1), 5, 1);
	party_[1] = new UnitAlly(allydata_mgr_.GetAllyDataAtID(2), 5, 2);
	party_[2] = new UnitAlly(allydata_mgr_.GetAllyDataAtID(3), 5, 3);
	
	//board_->SetPartyUnits(allydata_mgr_.GetPartyPickAllyData());

	for (int i = 0; i < 3; ++i) {
		//party_[i]->SetBaseDeck(cmgr_.GetDebugDeck());
		//party_[i]->SetUseDeck(cmgr_.GetDebugDeck());
		party_[i]->SetBaseDeck(cmgr_.GetAllCard());
		party_[i]->SetUseDeck(cmgr_.GetAllCard());


		party_[i]->AssignSerialNumberToUseDeck();
		party_[i]->ShuffleUseDeck();
	}

	party_[0]->SetTauntValue(500);
	party_units_.push_back(party_[0]);
	party_units_.push_back(party_[1]);
	party_units_.push_back(party_[2]);

	party_units_[0]->AddShieldValue(20);
	//party_units_[0]->AddBattleState(BattleState(State::Blood,3,3));
	//party_units_[0]->AddBattleState(BattleState(State::Stun, 3, 3));
	//party_units_[0]->AddBattleState(BattleState(State::Snare, 3, 3));




	unit_enemy_ = new UnitEnemy(enemydata_mgr_->GetEnemyDataAtID(1), 5, 5);
	enemy_units_.push_back(unit_enemy_);

	enemy_units_[0]->AddShieldValue(20);
	//enemy_units_[0]->AddBattleState(BattleState(State::Blood, 3, 3));
	//enemy_units_[0]->AddBattleState(BattleState(State::Stun, 3, 3));
	//enemy_units_[0]->AddBattleState(BattleState(State::Snare, 3, 3));


	all_units_.reserve(party_units_.size() + enemy_units_.size());
	all_units_.insert(all_units_.end(), party_units_.begin(), party_units_.end());
	all_units_.insert(all_units_.end(), enemy_units_.begin(), enemy_units_.end());

	board_->SetParty(party_);
	board_->SetPartyUnits(party_units_);
	board_->SetEnemyUnits(enemy_units_);
	board_->SetAllUnits(all_units_);

	board_->SetPartyUnitsInBoard(party_units_);
	board_->SetEnemyUnitsInBoard(enemy_units_);
	board_->SetAllUnitsInBoard(all_units_);



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

	ui_unit_state_view_ = new UIUnitStateView(w1*2,h1*1 + h1*1 /2 ,select_square_);
	ui_unit_state_view_->SetAllyBoxUpperLeftPos(10,10);
	ui_unit_state_view_->SetEnemyBoxUpperLeftPos((w1*8) - 10, 10);

	ui_turn_view_ = new UITurnView(w1*4,0,w1*2,h1*1/2,all_units_);

	board_->Update(0);

	//anim_mgr_.GetDebugAnim()->SetCamera(camera_);
	//anim_mgr_.GetDebugAnim()->setCurrentAnim("none");
	////anim_mgr_.GetDebugAnim()->pos_ = unit_enemy_->GetObj()->pos_;


	////card_play_->SetCameraToCardEffectAnim(camera_);
	//int cnt = 0;
	//int cnt2 = 0;
	//for (auto& anim : anim_mgr_.GetAnim()) {
	//	anim->SetBillBoardCamera(camera_);
	//	anim->setCurrentAnim("debug_anim");

	//	anim->SetObjPosToSquarePos(cnt,cnt2);
	//	cnt++;
	//	if (cnt > 9) {
	//		cnt = 0;
	//		cnt2++;
	//	}

	//	if (cnt2 > 0) {
	//		cnt2 = 0;
	//	}
	//}

	//anim_mgr_.GetDebugAnim()->setCurrentAnim("debug_anim");

	battle_media_player_ = new BattleMediaPlayer();
	battle_media_player_->SetAnim(camera_, anim_mgr_.GetAnim());

	obj_mgr_.GetObjBattleStateIcon()->pos_ = unit_enemy_->GetObj()->pos_;
	obj_mgr_.GetObjBattleStateIcon()->pos_.y = unit_enemy_->GetObj()->pos_.y + 180;

	obj_mgr_.GetObjBattleStateIcon()->SetIsRender(true);


}

void SceneBattle::Update(float delta_time) {
	
	phase_.update(delta_time);
	camera_->Update();

	GetMousePoint(&debug_mp_x,&debug_mp_y);
	msv_ = tnl::Input::GetMousePosition(); 
	board_->Update(delta_time);
	select_square_->Update(delta_time, camera_);

	ui_turn_ally_state_->SetUnitAlly(turn_ally_);

	//TODO:�����͂̂���Unit��Update�ɓ���
	//party_[0]->GetObj()->Update(delta_time);
	//party_[1]->GetObj()->Update(delta_time);
	//party_[2]->GetObj()->Update(delta_time);
	//unit_enemy_->GetObj()->Update(delta_time);
	//for (auto pu : party_units_) { pu->Update(delta_time); }
	//for (auto eu : enemy_units_) { eu->Update(delta_time); }

	for (auto au : all_units_) { au->Update(delta_time); }
	BattleResultJudgment(board_);


	obj_target_circle_->Update(delta_time);

	//card_play_->SetCameraToCardEffectAnim(camera_);
	//card_play_->Update(delta_time);

	//UI
	ui_action_buttons_->Update(delta_time);
	ui_turn_view_->Update(delta_time);
	ui_turn_ally_state_->Update(delta_time);
	ui_unit_state_view_->Update(delta_time);
	ui_unit_state_view_->Update(delta_time);

	//ui_card_->Update(delta_time);
	ui_card_hand_->SetTurnAlly(turn_ally_);
	ui_card_hand_->Update(delta_time);


	//anim_mgr_.GetDebugAnim()->Update(delta_time);
	//for (auto anim : anim_mgr_.GetAnim()) {
	//	anim->Update(delta_time);
	//}
	//
	//if (tnl::Input::IsKeyDownTrigger(eKeys::KB_D)) {
	//	anim_mgr_.GetDebugAnim()->setCurrentAnim("debug_anim");
	//}

	//if (tnl::Input::IsKeyDownTrigger(eKeys::KB_W)) {
	//
	//	anim_mgr_.GetDebugAnim()->getCurrentAnimSeekUnit()->restart();
	//	//anim_mgr_.GetDebugAnim()->getCurrentAnimSeekUnit()->jumpSeekRate(0.0);
	//	sound_mgr_.PlayAllyDamagedVoice(1);
	//}

	battle_media_player_->Update(delta_time);
	obj_mgr_.GetObjBattleStateIcon()->Update(delta_time);
	phase_.update(delta_time);
}

void SceneBattle::Render() {

	//camera_->Update();
	//DrawExtendGraph(0,0,DXE_WINDOW_WIDTH,DXE_WINDOW_HEIGHT,back_,false);
	DrawDebugLayOut(true);

	board_->Render(camera_);
	select_square_->Render(camera_);

	obj_target_circle_->Render(camera_);

	//UI
	ui_turn_ally_state_->Render();
	ui_unit_state_view_->Render();
	ui_turn_view_->Render();
	ui_notice_target_box_->Render();
	//ui_card_->Render();
	ui_card_hand_->Render();
	ui_action_buttons_->Render();
	ui_notice_target_box_->Render();
	//card_play_->Render(camera_);

	for (auto anim : anim_mgr_.GetAnim()) {
		anim->Render(camera_);
	}

	battle_media_player_->Render(camera_);
	obj_mgr_.GetObjBattleStateIcon()->Render(camera_);

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



	//if (anim_mgr_.GetDebugAnim()->getCurrentAnimSeekUnit()->GetIsPlaying()) {
	//	DrawStringEx(w1 * 8, 240, -1, "Anim���I");
	//}
	//else {
	//	DrawStringEx(w1 * 8, 240, -1, "Anim������Ȃ���I");
	//}
	if (turn_enemy_) {

		DrawStringEx(w1 * 8, 260, -1, "�X���C���ړ�pos:row[%d],col[%d]", turn_enemy_->GetEnemyData()->GetEnemyMove()->final_pos_.row, turn_enemy_->GetEnemyData()->GetEnemyMove()->final_pos_.col);
		DrawStringEx(w1 * 8, 280, -1, "targetpos:row[%d],col[%d]", turn_enemy_->GetEnemyData()->GetEnemyMove()->target_pos_.row, turn_enemy_->GetEnemyData()->GetEnemyMove()->target_pos_.col);
		DrawStringEx(w1 * 8, 300, -1, "currentpos:row[%d],col[%d]", turn_enemy_->GetEnemyData()->GetEnemyMove()->current_pos_.row, turn_enemy_->GetEnemyData()->GetEnemyMove()->current_pos_.col);
		DrawStringEx(w1 * 8, 320, -1, "enemymovecost[%d]",turn_enemy_->GetCurrentMoveCost());
		DrawStringEx(w1 * 8, 340, -1, "moveroutesize[%d]", turn_enemy_->GetEnemyData()->GetEnemyMove()->move_route_.size());

		for (int i = 0; i < turn_enemy_->GetEnemyData()->GetEnemyMove()->move_route_.size(); ++i) {
			DrawStringEx(w1 * 8, 360 + (i * 20) , -1, "Square:row[%d]col[%d]", turn_enemy_->GetEnemyData()->GetEnemyMove()->move_route_[i].row, turn_enemy_->GetEnemyData()->GetEnemyMove()->move_route_[i].col);
		}
	}

	if (battle_media_player_->GetIsMediaPlaying()) {
		DrawStringEx(w1 * 8, 380, -1, "BattleMedia�Đ���!");
	}






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

void SceneBattle::BattleResultJudgment(Board* board) {

	if (board->GetPartyUnitsInBoard().empty()) {

		//GameOver����

	}
	else if (board->GetEnemyUnitsInBoard().empty()) {

		//SceneBattleResult�֐���
		smgr_->ChengeScene(new SceneBattleResult());

	}

}

//�ePhase�̎���=======================================================================================================
//0.�퓬�J�n���̃^�[������
bool SceneBattle::PhaseInitialTurnCal(const float delta_time) {

	//�f�������ɍ~���\�[�g
	std::sort(all_units_.begin(), all_units_.end(), [](Unit* a, Unit* b) {
		return a->GetSpeed() > b->GetSpeed();
	});

	turn_unit_ = all_units_.front();

	if (turn_unit_) {

		//turn_unit���L���X�g�B�Ή�����Phase�Ɉڍs
		if (turn_unit_->GetUnitType() == UnitType::Ally) {
			turn_ally_ = static_cast<UnitAlly*>(turn_unit_);
			turn_enemy_ = nullptr;

			phase_.change(&SceneBattle::PhaseAllyTurn);

		}
		else if (turn_unit_->GetUnitType() == UnitType::Enemy) {
			turn_enemy_ = static_cast<UnitEnemy*>(turn_unit_);
			turn_ally_ = nullptr;

			phase_.change(&SceneBattle::PhaseEnemyTurn);
		}

	}


	return true;
}


//1.�^�[������
bool SceneBattle::TurnCal(const float delta_time) {

	DrawStringEx(500,0,-1,"TurnCal");

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

	if (turn_unit_) {
		if (turn_unit_->GetUnitType() == UnitType::Ally) {
			turn_ally_ = static_cast<UnitAlly*>(turn_unit_);


			turn_ally_->SetIsTurn(true);

			phase_.change(&SceneBattle::PhaseBattleStateProcAtStartOfTurn);
		}
		else if (turn_unit_->GetUnitType() == UnitType::Enemy) {
			turn_enemy_ = static_cast<UnitEnemy*>(turn_unit_);
	
			turn_enemy_->SetIsTurn(true);

			phase_.change(&SceneBattle::PhaseBattleStateProcAtStartOfTurn);
		}
	}

	return true;
}


//1.2�SUnit���s�������烊�Z�b�g
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

			//pu->SetCurrentMoveCost(pu->GetMaxMoveCost());
			
			//Turn���o�߂��邽�т�Card�R�X�g��������(Max15)
			if (pu->GetMaxCardCost() < 15) {
				pu->SetMaxCardCost(pu->GetMaxCardCost() + 1);
			}

			//�e�R�X�g�̃��Z�b�g
			pu->SetCurrentMoveCost(pu->GetMaxMoveCost());
			pu->SetCurrentCardCost(pu->GetMaxCardCost());

		}

		for (auto eu : enemy_units_) {
			eu->SetCurrentMoveCost(eu->GetCurrentMoveCost());

		}

	}

	reset_acted_ = false;
	phase_.change(&SceneBattle::TurnCal);
	return true;
}


//2.�^�[���J�n����BattleState����
bool SceneBattle::PhaseBattleStateProcAtStartOfTurn(const float delta_time) {

	DrawStringEx(500,0,-1,"PhaseBattleStateProcAtStartOfTurn");

	bool is_proc_finished = true;

	Unit* proc_unit = nullptr;
	//�eUnit�̏����p
	UnitAlly* proc_ally = nullptr; 
	UnitEnemy* proc_enemy = nullptr;

	if (turn_ally_ && turn_ally_->GetIsTurn()) {
		proc_unit = turn_ally_;
		proc_ally = dynamic_cast<UnitAlly*>(proc_unit);
	}
	else if (turn_enemy_ && turn_enemy_->GetIsTurn()) {
		proc_unit = turn_enemy_;
		proc_enemy = dynamic_cast<UnitEnemy*>(proc_unit);
	}

	if (proc_unit) {

		//�Ȃ������炻�̂܂܊eTurn��
		if (proc_unit->GetBattleState().empty()) {

			if (proc_unit->GetUnitType() == UnitType::Ally) {
				phase_.change(&SceneBattle::PhaseAllyTurn);
			}
			else if (proc_unit->GetUnitType() == UnitType::Enemy) {
				phase_.change(&SceneBattle::PhaseEnemyTurn);
			}

		}
		else if (!proc_unit->GetBattleState().empty()) { //������r�炻�������

			for (auto& state : proc_unit->GetBattleState()) {

				if (!state.GetIsProc()) {

					//State���L�̏���
					if (state.GetState() == State::Blood) {

						proc_unit->DecreaseDirectCurrentHp(state.GetValue());
						state.SetIsProc(true);
						state.SetIsAddTurn(false);

						//Anim������
						battle_media_player_->SetAnimBattleState(State::Blood);
						phase_.change(&SceneBattle::PhaseAnimBattleStateStartOfTurn);
					}
					else if (state.GetState() == State::AddCardCost) {

						if (proc_unit->GetUnitType() == UnitType::Ally) {
							proc_ally->AddCurrentCardCost(state.GetValue());
						}
						else {
							//�����o�O�邩���i�v���؁j
							continue;
						}

					}
					else if (state.GetState() == State::AddMoveCost) {

						if (proc_unit->GetUnitType() == UnitType::Ally) {
							proc_ally->AddCurrentMoveCost(state.GetValue());
						}
						else {
							continue;
						}

					}
					else if (state.GetState() == State::Snare) {
						proc_unit->SetIsSnareTurn(true);
					}
					else if (state.GetState() == State::Stun) {
						proc_unit->SetIsStunTurn(true);
					}

					//State���ʂ̏���
					state.SetIsProc(true);
					state.SetIsAddTurn(false);

				}
			}

			//�S�Ă�State�̏����������������`�F�b�N
			for (auto state : proc_unit->GetBattleState()) {
				if (!state.GetIsProc()) {
					is_proc_finished = false;
				}
			}

			//����������������Phase�ڍs
			if (is_proc_finished) {
				if (proc_unit->GetUnitType() == UnitType::Ally) {
					phase_.change(&SceneBattle::PhaseAllyTurn);
				}
				else if (proc_unit->GetUnitType() == UnitType::Enemy) {
					phase_.change(&SceneBattle::PhaseEnemyTurn);
				}
			}
		}

	}

	return true;
}


//2.1�^�[���J�n����BattleState��Anim�Đ�
bool SceneBattle::PhaseAnimBattleStateStartOfTurn(const float delta_time) {

	DrawStringEx(500,0,-1,"PhaseAnimBattleStateStartOfTurn");

	if (turn_ally_ && turn_ally_->GetIsTurn()) {

		battle_media_player_->BattleStateMediaPlay(turn_ally_, battle_media_player_->GetAnimBattleState());

		//if (!battle_media_player_->GetIsMediaPlaying()) {
		//	battle_media_player_->SetAnimBattleState(State::None); //Anim�I�����Anim��None�ɖ߂�
		//	phase_.change(&SceneBattle::PhaseBattleStateProcAtStartOfTurn);
		//}
		battle_media_player_->SetAnimBattleState(State::None); //Anim�I�����Anim��None�ɖ߂�
		phase_.change(&SceneBattle::PhaseBattleStateProcAtStartOfTurn);



	}
	else if (turn_enemy_ && turn_enemy_->GetIsTurn()) {

		battle_media_player_->BattleStateMediaPlay(turn_enemy_, battle_media_player_->GetAnimBattleState());

		//if (!battle_media_player_->GetIsMediaPlaying()) {
		//	battle_media_player_->SetAnimBattleState(State::None); //Anim�I�����Anim��None�ɖ߂�
		//	phase_.change(&SceneBattle::PhaseBattleStateProcAtStartOfTurn);
		//}

		battle_media_player_->SetAnimBattleState(State::None); //Anim�I�����Anim��None�ɖ߂�
		phase_.change(&SceneBattle::PhaseBattleStateProcAtStartOfTurn);


	}


	return true;
}


//3.1 Ally�̃^�[��
bool SceneBattle::PhaseAllyTurn(const float delta_time)
{

	DrawStringEx(500,0,-1,"PhaseTurnAlly");
	ui_mediator_->SetIsPlayerActionButtonEnabled(true);

	ui_card_hand_->SetTurnAlly(turn_ally_);


	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_0)) {
		phase_.change(&SceneBattle::PhaseDebug);

	}


	return true;
}


//3.2 Enemy�̃^�[��
bool SceneBattle::PhaseEnemyTurn(const float delta_time) {
	
	DrawStringEx(500, 0, -1, "PhaseTurnEnemy");

	//Move
	if (turn_enemy_->GetIsSnareTurn() && !turn_enemy_->GetIsMoved()) {
		turn_enemy_->SetIsMoved(true);
		//Phase�ڍs
		battle_media_player_->SetAnimBattleState(State::Stun);
		phase_.change(&SceneBattle::PhaseAnimBattleStateInTurn);

	}
	else if (!turn_enemy_->GetIsSnareTurn() && !turn_enemy_->GetIsMoved()) {
		turn_enemy_->SetIsMoved(true);
		turn_enemy_->Move(board_);
	}

	//Act
	if (turn_enemy_->GetIsMoved()) {

		if (turn_enemy_->GetIsStunTurn() && !turn_enemy_->GetIsEnemyActed()) {
			turn_enemy_->SetIsEnemyActed(true);
			//Phase�ڍs
			battle_media_player_->SetAnimBattleState(State::Stun);
			phase_.change(&SceneBattle::PhaseAnimBattleStateInTurn);

		}
		else if (!turn_enemy_->GetIsSnareTurn() && !turn_enemy_->GetIsEnemyActed()) {
			turn_enemy_->SetIsEnemyActed(true);
			turn_enemy_->Act(board_);
		}

	}

	//Turn�I������
	if (turn_enemy_->GetIsMoved() && turn_enemy_->GetIsEnemyActed()) {
		
		turn_enemy_->SetIsMoved(false);
		turn_enemy_->SetIsEnemyActed(false);

		turn_enemy_->SetIsStunTurn(false);
		turn_enemy_->SetIsSnareTurn(false);

		turn_enemy_->SetIsTurn(false);
		turn_enemy_->SetIsActed(true);
		turn_enemy_->DecreaseBattleStateTurn();

		phase_.change(&SceneBattle::ResetActedCal);
	}

	return true;
}


//�^�[���I������BattleState����(�g�p���ĂȂ�)
bool SceneBattle::PhaseBattleStateProcAtEndOfTurn(const float delta_time) {

	Unit* proc_unit = nullptr;
	
	if (turn_ally_ && turn_ally_->GetIsTurn()) {
		proc_unit = turn_ally_;
	}
	else if (turn_enemy_ && turn_enemy_->GetIsTurn()) {
		proc_unit = turn_enemy_;
	}

	if (proc_unit) {
		proc_unit->DecreaseBattleStateTurn();
		//Phase�ڍs

	}

	
	return true;
}


//�^�[������BattleStateAnim����
bool SceneBattle::PhaseAnimBattleStateInTurn(const float delta_time) {

	DrawStringEx(500,0,-1,"PhaseAnimBattleStateInTurn");

	if (turn_ally_ && turn_ally_->GetIsTurn()) {

		battle_media_player_->BattleStateMediaPlay(turn_ally_, battle_media_player_->GetAnimBattleState());
		if (!battle_media_player_->GetIsMediaPlaying()) {
			battle_media_player_->SetAnimBattleState(State::None);
			phase_.change(&SceneBattle::PhaseAllyTurn);
		}

	}
	else if (turn_enemy_ && turn_enemy_->GetIsTurn()) {

		battle_media_player_->BattleStateMediaPlay(turn_enemy_, battle_media_player_->GetAnimBattleState());
		if (!battle_media_player_->GetIsMediaPlaying()) {
			battle_media_player_->SetAnimBattleState(State::None);
			phase_.change(&SceneBattle::PhaseEnemyTurn);
		}
	}

	return true;
}


//3.1.1AllyActuonMove
bool SceneBattle::PhasePlayerActionMove(const float delta_time) {
	
	DrawStringEx(500,0,-1,"PhasePlayerActionMove");

	//�X�l�A�^�[���̏ꍇ�͈ړ��ł��Ȃ�
	if (turn_ally_->GetIsSnareTurn()) {
		battle_media_player_->SetAnimBattleState(State::Snare);
		phase_.change(&SceneBattle::PhaseAnimBattleStateInTurn);
	}
	else if (!turn_ally_->GetIsSnareTurn()) {

		// �ړ���̃}�X���擾
		int target_row = select_square_->GetSelectSquareRow();
		int target_col = select_square_->GetSelectSquareCol();

		int ally_row = turn_ally_->GetUnitSquarePos().row;
		int ally_col = turn_ally_->GetUnitSquarePos().col;

		board_->getBoardSquare(ally_row, ally_col)->getObj()->parts_[ObjSquare::RangeTile]->is_render_ = false;

		// �ړ��\�Ȕ͈͂��擾
		std::array<std::array<int, 10>, 10> reachable = GetReachableSquares(turn_ally_);

		//�ړ��R�X�g���`�F�b�N
		int move_cost = turn_ally_->GetCurrentMoveCost();

		if (select_square_->GetIsMouseInBoard()) {

			if (tnl::Input::IsMouseTrigger(eMouseTrigger::IN_LEFT)) {

				// �ړ��悪�ړ��\�Ȕ͈͓��ł��邩�`�F�b�N
				if (reachable[target_row][target_col] != -1) {

					//�ړ��R�X�g�����ɂȂ�Ȃ����`�F�b�N
					if (move_cost > 0) {

						turn_ally_->SetUnitSquarePos(target_row, target_col);

						move_cost -= reachable[target_row][target_col];  // �ړ��R�X�g�����炷
						turn_ally_->SetCurrentMoveCost(move_cost);  // �ړ��R�X�g���X�V

					}

				}

				//MoveSE�Đ�
				sound_mgr_.PlayAllyMoveSE();
			}

		}


		// �ړ��\�͈͂��Čv�Z
		reachable = GetReachableSquares(turn_ally_);
		// �ړ��\�͈͂̕`����X�V
		UpdateRender(reachable, turn_ally_);

	}
	

	return true;
}


//3.1.2AllyActionCard
bool SceneBattle::PhasePlayerActionCard(const float delta_time) {
	
	DrawStringEx(500, 0, -1, "PhasePlayerActionCard");

	//�X�^���^�[���̏ꍇ�̓J�[�h���g�p�ł��Ȃ�
	if (turn_ally_->GetIsStunTurn()) {
		battle_media_player_->SetAnimBattleState(State::Stun);
		phase_.change(&SceneBattle::PhaseAnimBattleStateInTurn);
	}
	else if (!turn_ally_->GetIsStunTurn()) {

		card_play_->SetSelectUICard(ui_card_hand_->GetSelectUICard());
		card_play_->SetTurnAlly(turn_ally_);

		board_->ResetDisplayRangeTile();
		board_->ResetAllTile();

		//card_play_->RenderSelectCardRange(turn_ally_, board_);
		//card_play_->UpdateSelectCardGetUnitInRange(turn_ally_, all_units_);

		//card_play_->UpdateSelectCardRangeSquarePos(turn_ally_->GetUnitSquarePos());
		//board_->DisplayRangePosRangeTile(card_play_->GetCardRangeSquarePos());


		//UICard��I�����Ă��鎞
		if (ui_card_hand_->GetSelectUICard()) {

			//Card�̎˒��𓝍��A�i�[
			card_play_->UpdateSelectCardRangeSquarePos(turn_ally_->GetUnitSquarePos());

			//Card�̎˒��͈͂�\��
			//TODO:����TurnAlly���S��SelectSquare���S�ɂ��邩��I���ł���悤�ɂ���
			//��������ʂ�ł���܂�Ally���S�Ői�߂�
			board_->DisplayRangePosRangeTile(card_play_->GetCardRangeSquarePos());


			//�N���b�N��Card�����肵����
			if (tnl::Input::IsMouseTrigger(eMouseTrigger::IN_LEFT)) {

				if (!card_play_->IsSelectCardCostEnough()) {

					DrawStringEx(0, 400, -1, "�R�X�g������܂���");
					sound_mgr_.PlayUISE(2);
				}
				else if (!card_play_->IsSelectCardTargetInRange(board_)) {

					DrawStringEx(0, 400, -1, "�˒��ɑΏۂ����܂���");
					sound_mgr_.PlayUISE(2);
				}
				//else if (card_play_->IsSelectCardCostEnough() && card_play_->IsSelectCardTargetInRange(board_)) {
				//	
				//	card_play_->SetPlayCard(ui_card_hand_->GetSelectUICard()->GetCardPtr());
				//	ui_card_hand_->SetEnableSelectCard(false);
				//	phase_.change(&SceneBattle::PhaseSpecifyPlayCardTarget);

				//}
				else if (card_play_->IsSelectCardTargetInRange(board_)) {

					card_play_->SetPlayCard(ui_card_hand_->GetSelectUICard()->GetCardPtr());
					ui_card_hand_->SetEnableSelectCard(false);
					phase_.change(&SceneBattle::PhaseSpecifyPlayCardTarget);

				}
			}

		}
		else {

			//board_->ResetDisplayRangeTile();
			//board_->ResetAllTile();

		}

		if (tnl::Input::IsKeyDownTrigger(eKeys::KB_D)) {
			battle_media_player_->BattleStateMediaPlay(turn_ally_, State::Blood);
		}

	}
	

	//board_->ResetDisplayRangeTile();
	//board_->ResetAllTile();

	//card_play_->EffectExecute();
	
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

		if (turn_ally_->GetHand().size() == 10) { //10���ȏ�̏ꍇ�̓h���[���Ȃ�

			turn_ally_->SetIsDrew(true);
			phase_.change(&SceneBattle::PhasePlayerActionCard);
		}
		else if (turn_ally_->GetHand().size() < 10) { //10�������̏ꍇ�̓h���[����

			turn_ally_->AddCardToHand(turn_ally_->GetUseDeck().back());	
			turn_ally_->GetUseDeck().pop_back();
			turn_ally_->SetIsDrew(true);

			phase_.change(&SceneBattle::PhasePlayerActionCard);
		}


	}

	//�R�D�Ǝ�D����̏ꍇ�̂݁A�R�D�����ɖ߂�
	if (turn_ally_->GetUseDeck().empty() && turn_ally_->GetUseDeck().empty()) {

	}


	return true;
}

//�J�[�h��I��������A�^�[�Q�b�g��I������i�K�̏���
bool SceneBattle::PhaseSpecifyPlayCardTarget(const float delta_time) {



	for (auto ctl : card_play_->GetPlayCard()->GetCardData()->GetCardTargetList()) {

		//�͈͍U������
		if (ctl->GetTargetType() == TARGETTYPE::InRange && !ctl->GetIsDetermined()) {

			//Range���̊eTarget��Pos��CardTarget���Ɋi�[
			if (ctl->GetToTarget() == TOTARGET::Ally) {
					
				//ctl->SetTargetUnits(card_play_->ExtractUnitInRange(TOTARGET::Ally));
				ctl->AddTargetSquarePoses(card_play_->ExtractTargetSquarePosInRange(TOTARGET::Ally,board_));
				ctl->SetIsDetermined(true);

			}
			else if (ctl->GetToTarget() == TOTARGET::Enemy) {
				ctl->AddTargetSquarePoses(card_play_->ExtractTargetSquarePosInRange(TOTARGET::Enemy, board_));
				ctl->SetIsDetermined(true);
			}

		}

		//�Ώێw��U������
		if (ctl->GetTargetType() == TARGETTYPE::Specify && !ctl->GetIsDetermined()) {

			DrawStringEx(0,400,-1,"�I��");

			
			card_play_->SetCurrentCardTarget(ctl);
			phase_.change(&SceneBattle::PhaseSpecifyTargetProc);
		}

	}
	
	//�S�Ă̑Ώێw�肪�I�������A���s�t�F�[�Y��
	for (auto a : card_play_->GetPlayCard()->GetCardData()->GetCardTargetList()) {

		if (!a->GetIsDetermined()) {
			break;
		}
		else {
			phase_.change(&SceneBattle::PhaseExecutePlayCard);
		}
		
	}


	return true;
}

bool SceneBattle::PhaseSpecifyTargetProc(const float delta_time)
{
	//memo TODO
	//���_��ɃJ�[�h�̌��ʂ��������邽�߂�Target�ɂ����̎w����֐��Ŏ���������
	//�u��΂ɓG2�̂Ɩ����P�̂��w�肵�Ȃ���΂����Ȃ��v�Ƃ������ʂ͌��i�K�Ŏ����ł��Ȃ��̂�
	//��������J�[�h���s�L������̍ۂɂ���𔻒�ł���悤�ɂ���΂����̂ł�
	//��CardTarget�ɐ�������̊֐�����������

	//�^�C���̃��Z�b�g
	board_->ResetRangeTile();

	int ally_cnt = 0;
	int enemy_cnt = 0;
	


	//�^�C���̕\������
	if (card_play_->GetCurrentCardTarget()->GetToTarget() == TOTARGET::Ally) {

		for (auto range_pos : card_play_->GetCardRangeSquarePos()) {
			//CandidateTile�̕\��
			if (board_->getBoardSquare(range_pos.row, range_pos.col)->GetAllyPtrInSquare()) {
				board_->getBoardSquare(range_pos.row, range_pos.col)->SetRenderCandidateTile(true);


				//TargetTile�̕\��
				if (select_square_->GetSelectSquarePos() == range_pos) {
					board_->getBoardSquare(range_pos.row, range_pos.col)->SetRenderTargetTile(true);

				}
			}
		}

	}
	else if (card_play_->GetCurrentCardTarget()->GetToTarget() == TOTARGET::Enemy) {

		for (auto range_pos : card_play_->GetCardRangeSquarePos()) {
			//CandidateTile�̕\��
			if (board_->getBoardSquare(range_pos.row, range_pos.col)->GetEnemyPtrInSquare()) {
				board_->getBoardSquare(range_pos.row, range_pos.col)->SetRenderCandidateTile(true);


				//TargetTile�̕\��
				if (select_square_->GetSelectSquarePos() == range_pos) {
					board_->getBoardSquare(range_pos.row, range_pos.col)->SetRenderTargetTile(true);

				}
			}
		}
	}
	else if (card_play_->GetCurrentCardTarget()->GetToTarget() == TOTARGET::Square) {

		for (auto range_pos : card_play_->GetCardRangeSquarePos()) {
			//CandidateTile�̕\��
			if (board_->getBoardSquare(range_pos.row, range_pos.col)->GetIsCanMove()) {
				board_->getBoardSquare(range_pos.row, range_pos.col)->SetRenderCandidateTile(true);


				//TargetTile�̕\��
				if (select_square_->GetSelectSquarePos() == range_pos) {
					board_->getBoardSquare(range_pos.row, range_pos.col)->SetRenderTargetTile(true);

				}
			}
		}

	}


	//�Ώێw�肳�ꂽ�^�C����\��
	//for (auto a : card_play_->GetCurrentCardTarget()->GetTargetUnits()) {
	//	board_->getBoardSquare(a->GetUnitSquarePos().row,a->GetUnitSquarePos().col)->SetRenderTargetTile(true);
	//}

	//�Ώێw�肳�ꂽ�^�C����\��
	if (!card_play_->GetCurrentCardTarget()->GetTargetSquaresPos().empty()) {

		for (auto target_pos : card_play_->GetCurrentCardTarget()->GetTargetSquaresPos()) {
			board_->getBoardSquare(target_pos.row, target_pos.col)->SetRenderTargetTile(true);
		}

	}

	//�w��Ώۂ̐����J�E���g
	for (auto a : card_play_->GetTotalUnitsInRange()) {

		if (a->GetUnitType() == UnitType::Ally) {

			ally_cnt++;
		}
		else if (a->GetUnitType() == UnitType::Enemy) {
			enemy_cnt++;
		}

	}

	//���N���b�N�Ŏw��
	if (tnl::Input::IsMouseTrigger(eMouseTrigger::IN_LEFT)) {

		if (card_play_->GetCurrentCardTarget()->GetToTarget() == TOTARGET::Ally) {
			//debug�p�c��
			//for (auto a : card_play_->GetTotalUnitsInRange()) {
			//	if (a == select_square_->GetSelectSquare()->GetUnitPtrInSquare() && a->GetUnitType() == UnitType::Ally) {
			//		card_play_->GetCurrentCardTarget()->GetTargetUnits().push_back(a);
			//	}
			//}

			for (auto range_pos : card_play_->GetCardRangeSquarePos()) {

				if (select_square_->GetSelectSquarePos() == range_pos && board_->getBoardSquare(range_pos.row, range_pos.col)->GetAllyPtrInSquare()) {

					card_play_->GetCurrentCardTarget()->AddTargetSquarePos(range_pos);
				}

			}

		}
		else if (card_play_->GetCurrentCardTarget()->GetToTarget() == TOTARGET::Enemy) {
			
			for (auto range_pos : card_play_->GetCardRangeSquarePos()) {

				if (select_square_->GetSelectSquarePos() == range_pos && board_->getBoardSquare(range_pos.row, range_pos.col)->GetEnemyPtrInSquare()) {

					card_play_->GetCurrentCardTarget()->AddTargetSquarePos(range_pos);
				}

			}
		}
		else if (card_play_->GetCurrentCardTarget()->GetToTarget() == TOTARGET::CanMoveSqure) {

			for (auto range_pos : card_play_->GetCardRangeSquarePos()) {

				if (select_square_->GetSelectSquarePos() == range_pos && board_->getBoardSquare(range_pos.row, range_pos.col)->GetIsCanMove()) {

					card_play_->GetCurrentCardTarget()->AddTargetSquarePos(range_pos);
				}

			}

		}

		sound_mgr_.PlayUISE(4);
	}

	//�E�N���b�N�Ŏw���������
	if (tnl::Input::IsMouseTrigger(eMouseTrigger::IN_RIGHT)) {
		//if (!card_play_->GetCurrentCardTarget()->GetTargetUnits().empty()) {
		//	card_play_->GetCurrentCardTarget()->GetTargetUnits().pop_back();
		//}
		if (!card_play_->GetCurrentCardTarget()->GetTargetSquaresPos().empty()) {
			card_play_->GetCurrentCardTarget()->GetTargetSquaresPos().pop_back();
		}
	}


	//�I������
	if (card_play_->GetCurrentCardTarget()->GetToTarget() == TOTARGET::Ally) {

		////�w��Ώې����w�����葽���ꍇ
		//if (card_play_->GetCurrentCardTarget()->GetTargetNum() > ally_cnt) {
		//	if (ally_cnt == card_play_->GetCurrentCardTarget()->GetTargetUnits().size()) {
		//		card_play_->GetCurrentCardTarget()->SetIsDetermined(true);
		//		phase_.change(&SceneBattle::PhaseSpecifyPlayCardTarget);
		//	}
		//}
		////�w��Ώې����w�萔��␔��菭�Ȃ��ꍇ	
		//else if (card_play_->GetCurrentCardTarget()->GetTargetNum() <= ally_cnt) { 

		//	if (card_play_->GetCurrentCardTarget()->GetTargetUnits().size() == card_play_->GetCurrentCardTarget()->GetTargetNum()) {

		//		card_play_->GetCurrentCardTarget()->SetIsDetermined(true);
		//		phase_.change(&SceneBattle::PhaseSpecifyPlayCardTarget);

		//	}
		//}

		//�w��Ώې����w�����葽���ꍇ
		if (card_play_->GetCurrentCardTarget()->GetTargetNum() > card_play_->GetInRangeTargetNum(TOTARGET::Ally,board_)) {
			if (card_play_->GetCurrentCardTarget()->GetTargetSquaresPos().size() == card_play_->GetInRangeTargetNum(TOTARGET::Ally, board_)) {
				card_play_->GetCurrentCardTarget()->SetIsDetermined(true);
				phase_.change(&SceneBattle::PhaseSpecifyPlayCardTarget);
			}
		}
		//�w��Ώې����w���␔��菭�Ȃ��ꍇ
		else if (card_play_->GetCurrentCardTarget()->GetTargetNum() <= card_play_->GetInRangeTargetNum(TOTARGET::Ally, board_)) {

			if (card_play_->GetCurrentCardTarget()->GetTargetSquaresPos().size() == card_play_->GetCurrentCardTarget()->GetTargetNum()) {
				card_play_->GetCurrentCardTarget()->SetIsDetermined(true);
				phase_.change(&SceneBattle::PhaseSpecifyPlayCardTarget);
			}
		}

	}
	else if (card_play_->GetCurrentCardTarget()->GetToTarget() == TOTARGET::Enemy) {

		//�w��Ώې����w�����葽���ꍇ
		if (card_play_->GetCurrentCardTarget()->GetTargetNum() > card_play_->GetInRangeTargetNum(TOTARGET::Enemy, board_)) {
			if (card_play_->GetCurrentCardTarget()->GetTargetSquaresPos().size() == card_play_->GetInRangeTargetNum(TOTARGET::Enemy, board_)) {
				card_play_->GetCurrentCardTarget()->SetIsDetermined(true);
				phase_.change(&SceneBattle::PhaseSpecifyPlayCardTarget);
			}
		}
		//�w��Ώې����w���␔��菭�Ȃ��ꍇ
		else if (card_play_->GetCurrentCardTarget()->GetTargetNum() <= card_play_->GetInRangeTargetNum(TOTARGET::Enemy, board_)) {

			if (card_play_->GetCurrentCardTarget()->GetTargetSquaresPos().size() == card_play_->GetCurrentCardTarget()->GetTargetNum()) {
				card_play_->GetCurrentCardTarget()->SetIsDetermined(true);
				phase_.change(&SceneBattle::PhaseSpecifyPlayCardTarget);
			}
		}

	}


	return true;
}


//Card���g���邩����B�ł��Ȃ�������w��܂Ŗ߂�
bool SceneBattle::PhaseCanExcutePlayCardProc(const float delta_time) {


	if (card_play_->CanPlayCardExecute(board_)) {
		phase_.change(&SceneBattle::PhaseExecutePlayCard);
	}
	else {
		phase_.change(&SceneBattle::PhaseSpecifyPlayCardTarget);
	}

	return true;
}


//PlayCard�����s
bool SceneBattle::PhaseExecutePlayCard(const float delta_time) {

	card_play_->PlayCardExecute(board_);
	battle_media_player_->CardMediaPlay(card_play_->GetPlayCard());
	card_play_->ResetPlayCardTargetSquarePos();
	card_play_->RemovePlayCardFromHand();
	

	//sound_mgr_.PlayCardSE(1);

	if (!battle_media_player_->GetIsMediaPlaying()) {

		card_play_->SetPlayCard(nullptr);
		ui_card_hand_->SetEnableSelectCard(true);
		sound_mgr_.PlayUISE(3);
		phase_.change(&SceneBattle::PhasePlayerActionCard);

	}

	return true;
}

bool SceneBattle::PhasePlayerActionTool(const float delta_time) {
	
	DrawStringEx(500, 0, -1, "PhasePlayerActionTool");

	
	return true;
}

bool SceneBattle::PhasePlayerActionTurnEnd(const float delta_time) {
	
	DrawStringEx(500, 0, -1, "PhasePlayerActionTurnEnd");
	ui_mediator_->SetIsPlayerActionButtonEnabled(false);



	//�eAlly��flag�ύX
	turn_ally_->SetIsTurn(false);
	turn_ally_->SetIsDrew(false);
    turn_ally_->SetIsActed(true);
	turn_ally_->SetIsStunTurn(false);
	turn_ally_->SetIsSnareTurn(false);

	turn_ally_->DecreaseBattleStateTurn();

	phase_.change(&SceneBattle::ResetActedCal);

	return true;
}

bool SceneBattle::PhaseDebug(const float delta_time) {

	DrawStringEx(500,0,-1,"PhaseDebug");



	return true;
}


std::array<std::array<int, 10>, 10> SceneBattle::GetReachableSquares(UnitAlly* unit) {

	// �ړ����̈ʒu���擾
	int ally_row = unit->GetUnitSquarePos().row;
	int ally_col = unit->GetUnitSquarePos().col;

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
			if ((i != unit->GetUnitSquarePos().row || j != unit->GetUnitSquarePos().col) && reachable[i][j] != -1) {
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