#pragma once
#include "gm_scene_base.h"

#include "../gm_scene_manager.h"
#include "../gm_card_manager.h"
#include "../gm_allydata_manager.h"
#include "../gm_enemydata_manager.h"
#include "../gm_scene_battle_camera.h"
#include "../gm_object_manager.h"
#include "../gm_anim_manager.h"
#include "../gm_sound_manager.h"

#include "../gm_ui_card.h"
#include "../gm_ui_card_hand.h"
#include "../gm_ui_cardview.h"
#include "../gm_ui_player_action_buttons.h"
#include "../gm_ui_scene_battle_mediator.h"
#include "../gm_ui_hp_bar.h"
#include "../gm_ui_card_cost.h"
#include "../gm_ui_move_cost.h"
#include "../gm_ui_turn_ally_state.h"
#include "../gm_ui_turn_view.h"
#include "../gm_ui_unit_state_view.h"
#include "../gm_ui_notice_target_box.h"

#include "../gm_object.h"
#include "../gm_object_board.h"
#include "../gm_object_ally.h"
#include "../gm_object_target_circle.h"

#include "../gm_unit_ally.h"
#include "../gm_unit_enemy.h"

#include "../gm_square.h"
#include "../gm_board.h"
#include "../gm_card_play.h"




//#include "../gm_enemy_behavior_strategy.h"
//#include "../gm_slime_behavior_strategy.h"

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


	void InitialTurnCal();
	void BattleResultJudgment(Board* board);

	//
	tnl::Sequence<SceneBattle> phase_ = tnl::Sequence<SceneBattle>(this, &SceneBattle::TurnCal);



	bool PhaseInitialTurnCal(const float delta_time);
	bool TurnCal(const float delta_time);
	bool ResetActedCal(const float delta_time);
	bool PhaseAllyTurn(const float delta_time);
	bool PhaseEnemyTurn(const float delta_time);
	bool PhaseBattleEffectProc(const float delta_time);


	bool PhasePlayerActionMove(const float delta_time);
	
	bool PhasePlayerActionCard(const float delta_time);
	bool PhaseDrawCard(const float delta_time);

	bool PhaseSpecifyPlayCardTarget(const float delta_time);
	bool PhaseSpecifyTargetProc(const float delta_time);
	bool PhaseCanExcutePlayCardProc(const float delta_time);
	bool PhaseExecutePlayCard(const float delta_time);

	bool PhasePlayerActionTool(const float delta_time);
	bool PhasePlayerActionTurnEnd(const float delta_time);
	bool PhaseDebug(const float delta_time);

	std::array<std::array<int, 10>, 10> GetReachableSquares(UnitAlly* unit);
	void UpdateRender(std::array<std::array<int, 10>, 10> reachable, UnitAlly* unit);



private:

	const int dx_[4] = { 0, 1, 0, -1 };
	const int dy_[4] = { 1, 0, -1, 0 };
	
	int w1 = DXE_WINDOW_WIDTH / 10;
	int h1 = DXE_WINDOW_HEIGHT / 10;

	//int
	int turn_count_ = 0;
	bool reset_acted_ = false;

	tnl::Vector3 msv_; //mouseの座標取得変数

	//メンバ変数
	//pointer
	SceneBattleCamera* camera_ = nullptr;
	//CardView* cardview_ = nullptr;
	//mgrインスタンス
	SceneManager* smgr_ = SceneManager::GetInstance();
	CardManager& cmgr_ = CardManager::GetInstance();
	AnimManager& anim_mgr_ = AnimManager::GetInstance();
	SoundManager& sound_mgr_ = SoundManager::GetInstance();


	AllyDataManager& allydata_mgr_ = AllyDataManager::GetInstane();


	EnemyDataManager* enemydata_mgr_ = EnemyDataManager::GetInstance();

	ObjBoard* obj_board_ = nullptr;
	ObjAlly* obj_ally_ = nullptr;
	ObjTargetCircle* obj_target_circle_ = ObjTargetCircle::Create(ObjTargetCircle::TextureColor::Red);
	
	UnitAlly* unit_ally_ = nullptr;
	UnitAlly*  unit_ally2_ = nullptr;
	UnitAlly* party_[3];
	UnitEnemy* unit_enemy_ = nullptr;


	Unit* turn_unit_ = nullptr; //ターン決め用
	std::vector <UnitAlly*> party_units_;
	std::vector<UnitEnemy*> enemy_units_;
	std::vector<Unit*> all_units_;


	UnitAlly* turn_ally_ = nullptr; //turnが回ってきたally
	UnitEnemy* turn_enemy_ = nullptr;

	//EnemyAction* enemy_action_ = nullptr;


	Square* square_ = nullptr;
	Board* board_ = nullptr;

	std::shared_ptr<Square> square_s_ = nullptr;
	std::shared_ptr<Board> board_s_ = nullptr;


	SelectSquare* select_square_ = nullptr;
	CardPlay* card_play_ = nullptr;

	//BattlePhase

	//PhasePlayerActionMove* phase_player_action_move_ = nullptr;

	AnimSprite3D* sprite_ = nullptr;

	std::vector<Square*> all_square_;
	
	dxe::Mesh* debug_board_obj_ = nullptr;

	ObjectManager& omgr_ = ObjectManager::GetInstance();

	//UITurnView用の画像ハンドル配列
	std::vector<Unit*> active_units_;



	//UI
	UIPlayerActionButtons* ui_action_buttons_ = nullptr;
	UISceneBattleMediator* ui_mediator_ = nullptr;
	UIHpBar* ui_hp_bar_ = nullptr;
	UICardCost* ui_card_cost_ = nullptr;
	UIMoveCost* ui_move_cost_ = nullptr;
	UITurnAllyState* ui_turn_ally_state_ = nullptr;
	UICard* ui_card_ = nullptr;
	UICardHand* ui_card_hand_ = nullptr;
	UITurnView* ui_turn_view_ = nullptr;
	UIUnitStateView* ui_unit_state_view_ = nullptr;
	UINoticeTargetBox* ui_notice_target_box_ = nullptr;



	//bool
	bool is_draw_debug_layout_ = false;
	bool is_enemy_action_ = false;

	//colorcode
	int red_ = GetColor(255, 0, 0);
	int gray_ = GetColor(128,128,128);

	//debugにつかう変数
	int debug_mp_x = 0;
	int debug_mp_y = 0;

	int back_ = LoadGraph("graphics/background/back_forest.jpg");
};