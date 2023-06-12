#pragma once
#include "gm_scene_base.h"

#include "../gm_scene_manager.h"
#include "../gm_card_manager.h"
#include "../gm_allydata_manager.h"
#include "../gm_enemydata_manager.h"
#include "../gm_scene_battle_camera.h"
#include "../gm_object_manager.h"

#include "../gm_ui_card.h"
#include "../gm_ui_cardview.h"
#include "../gm_ui_player_action_buttons.h"
#include "../gm_ui_scene_battle_mediator.h"
#include "../gm_ui_hp_bar.h"
#include "../gm_ui_card_cost.h"
#include "../gm_ui_move_cost.h"
#include "../gm_ui_turn_ally_state.h"

#include "../gm_object.h"
#include "../gm_object_board.h"
#include "../gm_object_ally.h"
#include "../gm_object_target_circle.h"

#include "../gm_unit_ally.h"
#include "../gm_unit_enemy.h"

#include "../gm_square.h"
#include "../gm_board.h"
#include "../gm_battle_phase.h"
#include "../gm_battle_phase_player_action_move.h"
#include "../gm_battle_player_action_move.h"

#include "../gm_select_square.h"
#include "../gm_anim_sprite3d.h"
//#include "../../library/tnl_sequence.h"

//memo
//戦闘シーンのSceneクラス



class SceneBattle : public SceneBase {
public:

	SceneBattle() {}
	~SceneBattle() {}

	void Initialzie() override;
	void Update(float delta_time) override;
	void Render() override;

	//メンバ関数
	void DrawDebugLayOut(bool is_draw);




	//Sequence
	tnl::Sequence<SceneBattle> seq_ =
		tnl::Sequence<SceneBattle>(this, &SceneBattle::PhaseAllyTurn);
	//tnl::Sequence<SceneBattle>* phase_;
	bool PhaseSetBattle(const float delta_time);

	bool PhaseTurnDeside(const float delta_time);

	bool PhaseActionCard(const float delta_time);
	bool PhaseActionMove(const float delta_time);
	bool PhaseActionTool(const float delta_time);
	bool PhaseActionTurnEnd(const float delta_time);
	bool PhaseAllyTurn(const float delta_time);
	bool PhaseEnemyTurn(const float delta_time);

	//BattlePhase
	void ChangeBattlePhase(BattlePhase* new_phase);

private:
	
	int w1 = DXE_WINDOW_WIDTH / 10;
	int h1 = DXE_WINDOW_HEIGHT / 10;

	//メンバ変数
	//pointer
	SceneBattleCamera* camera_ = nullptr;
	//CardView* cardview_ = nullptr;
	CardManager* cmgr_ = nullptr;
	AllyDataManager* allydata_mgr_ = AllyDataManager::GetInstance();
	EnemyDataManager* enemydata_mgr_ = EnemyDataManager::GetInstance();

	ObjBoard* obj_board_ = nullptr;
	ObjAlly* obj_ally_ = nullptr;
	ObjTargetCircle* obj_target_circle_ = ObjTargetCircle::Create(ObjTargetCircle::TextureColor::Red);
	
	UnitAlly* unit_ally_ = nullptr;
	UnitAlly*  unit_ally2_ = nullptr;
	UnitAlly* party_[3];
	UnitEnemy* unit_enemy_ = nullptr;


	Unit* turn_unit_ = nullptr; //ターン決め用
	UnitAlly* turn_ally_ = nullptr; //turnが回ってきたally


	Square* square_ = nullptr;
	Board* board_ = nullptr;
	SelectSquare* select_square_ = nullptr;
	BattlePhase* current_phase_ = nullptr;
	PhasePlayerActionMove* phase_player_action_move_ = nullptr;


	PlayerActionMove* player_action_move_ = nullptr;

	AnimSprite3D* sprite_ = nullptr;

	std::vector<Square*> all_square_;
	
	dxe::Mesh* debug_board_obj_ = nullptr;

	ObjectManager& omgr_ = ObjectManager::GetInstance();

	//UI
	UIPlayerActionButtons* ui_action_buttons_ = nullptr;
	UISceneBattleMediator* ui_mediator_ = nullptr;
	UIHpBar* ui_hp_bar_ = nullptr;
	UICardCost* ui_card_cost_ = nullptr;
	UIMoveCost* ui_move_cost_ = nullptr;
	UITurnAllyState* ui_turn_ally_state_ = nullptr;
	UICard* ui_card_ = nullptr;

	//bool
	bool is_draw_debug_layout_ = false;

	//colorcode
	int red_ = GetColor(255, 0, 0);
	int gray_ = GetColor(128,128,128);

	//debugにつかう変数
	int debug_mp_x = 0;
	int debug_mp_y = 0;


};