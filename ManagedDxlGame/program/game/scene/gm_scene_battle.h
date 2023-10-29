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
#include "../gm_texture_manager.h"

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
#include "../gm_ui_notice.h"

#include "../gm_object.h"
#include "../gm_object_board.h"
#include "../gm_object_ally.h"
#include "../gm_object_target_circle.h"

#include "../gm_unit_ally.h"
#include "../gm_unit_enemy.h"

#include "../gm_square.h"
#include "../gm_board.h"
#include "../gm_card_play.h"

#include "../gm_battle_media_player.h"



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
	~SceneBattle() { }

	void Initialzie() override;
	void Update(float delta_time) override;
	void Render() override;
	void DeletePtr(); //このシーンの持つptrをdeleteする

	//メンバ関数
	void DrawDebugLayOut(bool is_draw);


	void InitialTurnCal();
	void BattleResultJudgment(Board* board);

	//
	tnl::Sequence<SceneBattle> phase_ = tnl::Sequence<SceneBattle>(this, &SceneBattle::TurnCal); //Phaseの管理用Sequence


	//---各Phase
	bool PhaseInitialTurnCal(const float delta_time); //scene初期化時のターン決め
	bool TurnCal(const float delta_time); //1.ターン決め
	bool ResetActedCal(const float delta_time);
	bool PhaseAllyTurn(const float delta_time); //2
	bool PhaseEnemyTurn(const float delta_time); //2
	bool PhaseEnemyMove(const float delta_time);
	bool PhaseEnemyAct(const float delta_time);
	bool PhaseDrawCard(const float delta_time);
	bool PhasePlayerActionMove(const float delta_time); //3.1
	bool PhasePlayerActionCard(const float delta_time); //3.2
	bool PhasePlayerActionTurnEnd(const float delta_time);
	bool PhaseBattleStateProcAtStartOfTurn(const float delta_time); //ターン開始時BattleStateの処理
	bool PhaseAnimBattleStateStartOfTurnProc(const float delta_time); //BattleStateAnimを順番に再生するための処理Phase
	bool PhaseAnimBattleStateStartOfTurn(const float delta_time); //BattleStateのアニメーション処理
	bool PhaseBattleStateProcAtEndOfTurn(const float delta_time); //ターン終了時BattleStateの処理
	bool PhaseAnimBattleStateInTurn(const float delta_time); //各Unitのturn中のBattleStateAnimの再生処理
	bool PhaseSpecifyPlayCardTarget(const float delta_time);
	bool PhaseSpecifyTargetProc(const float delta_time);
	bool PhaseCanExcutePlayCardProc(const float delta_time);
	bool PhaseExecutePlayCard(const float delta_time);
	bool PhasePlayerActionTool(const float delta_time);
	bool PhaseDelay(const float delta_time); //Phase移行時にDelayを入れる用
	bool PhaseDebug(const float delta_time); 
	//---

	std::array<std::array<int, 10>, 10> GetReachableSquares(UnitAlly* unit);
	void UpdateRender(std::array<std::array<int, 10>, 10> reachable, UnitAlly* unit);



private:
	
	//レイアウト用変数
	int w1 = DXE_WINDOW_WIDTH / 10; 
	int h1 = DXE_WINDOW_HEIGHT / 10;

	//
	int turn_count_ = 0; //ターン数
	bool reset_acted_ = false; //ターン終了時にactedをリセットするかどうかのフラグ
	float delay_timer_ = 0.0; //PhaseDelay用タイマー

	//ptr
	Board* board_ = nullptr;
	SelectSquare* select_square_ = nullptr;
	CardPlay* card_play_ = nullptr;
	BattleMediaPlayer* battle_media_player_ = nullptr;
	SceneBattleCamera* camera_ = nullptr; //カメラ
	ObjBoard* obj_board_ = nullptr;
	ObjAlly* obj_ally_ = nullptr;
	UnitAlly* unit_ally_ = nullptr;
	UnitAlly*  unit_ally2_ = nullptr;
	UnitAlly* party_[3];
	UnitEnemy* unit_enemy_ = nullptr;
	Unit* turn_unit_ = nullptr; //ターン決め用
	UnitAlly* turn_ally_ = nullptr; //turnが回ってきたally
	UnitEnemy* turn_enemy_ = nullptr; //turnが回ってきたenemy
	
	std::vector <UnitAlly*> party_units_;
	std::vector<UnitEnemy*> enemy_units_;
	std::vector<Unit*> all_units_;

	tnl::Vector3 msv_; //mouseの座標取得変数

	//mgrインスタンス
	SceneManager* smgr_ = SceneManager::GetInstance(); //p
	CardManager& cmgr_ = CardManager::GetInstance();
	AnimManager& anim_mgr_ = AnimManager::GetInstance();
	SoundManager& sound_mgr_ = SoundManager::GetInstance();
	ObjectManager& obj_mgr_ = ObjectManager::GetInstance();
	TextureManager& texture_mgr_ = TextureManager::GetInstance();
	AllyDataManager& allydata_mgr_ = AllyDataManager::GetInstane();
	ObjectManager& omgr_ = ObjectManager::GetInstance();	
	EnemyDataManager* enemydata_mgr_ = EnemyDataManager::GetInstance(); //p


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
	UIUnitStateView* ui_unit_state_view_ = nullptr;
	UINoticeTargetBox* ui_notice_target_box_ = nullptr;
	UINotice* ui_notice_ = nullptr;

	//bool
	bool is_draw_debug_layout_ = false;
	//colorcode
	int red_ = GetColor(255, 0, 0);
	int gray_ = GetColor(128,128,128);

	//debugにつかう変数
	int debug_mp_x = 0;
	int debug_mp_y = 0;

};