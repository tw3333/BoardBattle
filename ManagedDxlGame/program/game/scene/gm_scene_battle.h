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
//�퓬�V�[����Scene�N���X



class SceneBattle : public SceneBase {
public:

	SceneBattle() {}
	~SceneBattle() { }

	void Initialzie() override;
	void Update(float delta_time) override;
	void Render() override;
	void DeletePtr(); //���̃V�[���̎���ptr��delete����

	//�����o�֐�
	void DrawDebugLayOut(bool is_draw);


	void InitialTurnCal();
	void BattleResultJudgment(Board* board);

	//
	tnl::Sequence<SceneBattle> phase_ = tnl::Sequence<SceneBattle>(this, &SceneBattle::TurnCal); //Phase�̊Ǘ��pSequence


	//---�ePhase
	bool PhaseInitialTurnCal(const float delta_time); //scene���������̃^�[������
	bool TurnCal(const float delta_time); //1.�^�[������
	bool ResetActedCal(const float delta_time);
	bool PhaseAllyTurn(const float delta_time); //2
	bool PhaseEnemyTurn(const float delta_time); //2
	bool PhaseEnemyMove(const float delta_time);
	bool PhaseEnemyAct(const float delta_time);
	bool PhaseDrawCard(const float delta_time);
	bool PhasePlayerActionMove(const float delta_time); //3.1
	bool PhasePlayerActionCard(const float delta_time); //3.2
	bool PhasePlayerActionTurnEnd(const float delta_time);
	bool PhaseBattleStateProcAtStartOfTurn(const float delta_time); //�^�[���J�n��BattleState�̏���
	bool PhaseAnimBattleStateStartOfTurnProc(const float delta_time); //BattleStateAnim�����ԂɍĐ����邽�߂̏���Phase
	bool PhaseAnimBattleStateStartOfTurn(const float delta_time); //BattleState�̃A�j���[�V��������
	bool PhaseBattleStateProcAtEndOfTurn(const float delta_time); //�^�[���I����BattleState�̏���
	bool PhaseAnimBattleStateInTurn(const float delta_time); //�eUnit��turn����BattleStateAnim�̍Đ�����
	bool PhaseSpecifyPlayCardTarget(const float delta_time);
	bool PhaseSpecifyTargetProc(const float delta_time);
	bool PhaseCanExcutePlayCardProc(const float delta_time);
	bool PhaseExecutePlayCard(const float delta_time);
	bool PhasePlayerActionTool(const float delta_time);
	bool PhaseDelay(const float delta_time); //Phase�ڍs����Delay������p
	bool PhaseDebug(const float delta_time); 
	//---

	std::array<std::array<int, 10>, 10> GetReachableSquares(UnitAlly* unit);
	void UpdateRender(std::array<std::array<int, 10>, 10> reachable, UnitAlly* unit);



private:
	
	//���C�A�E�g�p�ϐ�
	int w1 = DXE_WINDOW_WIDTH / 10; 
	int h1 = DXE_WINDOW_HEIGHT / 10;

	//
	int turn_count_ = 0; //�^�[����
	bool reset_acted_ = false; //�^�[���I������acted�����Z�b�g���邩�ǂ����̃t���O
	float delay_timer_ = 0.0; //PhaseDelay�p�^�C�}�[

	//ptr
	Board* board_ = nullptr;
	SelectSquare* select_square_ = nullptr;
	CardPlay* card_play_ = nullptr;
	BattleMediaPlayer* battle_media_player_ = nullptr;
	SceneBattleCamera* camera_ = nullptr; //�J����
	ObjBoard* obj_board_ = nullptr;
	ObjAlly* obj_ally_ = nullptr;
	UnitAlly* unit_ally_ = nullptr;
	UnitAlly*  unit_ally2_ = nullptr;
	UnitAlly* party_[3];
	UnitEnemy* unit_enemy_ = nullptr;
	Unit* turn_unit_ = nullptr; //�^�[�����ߗp
	UnitAlly* turn_ally_ = nullptr; //turn������Ă���ally
	UnitEnemy* turn_enemy_ = nullptr; //turn������Ă���enemy
	
	std::vector <UnitAlly*> party_units_;
	std::vector<UnitEnemy*> enemy_units_;
	std::vector<Unit*> all_units_;

	tnl::Vector3 msv_; //mouse�̍��W�擾�ϐ�

	//mgr�C���X�^���X
	SceneManager* smgr_ = SceneManager::GetInstance(); //p
	CardManager& cmgr_ = CardManager::GetInstance();
	AnimManager& anim_mgr_ = AnimManager::GetInstance();
	SoundManager& sound_mgr_ = SoundManager::GetInstance();
	ObjectManager& obj_mgr_ = ObjectManager::GetInstance();
	TextureManager& texture_mgr_ = TextureManager::GetInstance();
	AllyDataManager& allydata_mgr_ = AllyDataManager::GetInstane();
	ObjectManager& omgr_ = ObjectManager::GetInstance();	
	EnemyDataManager* enemydata_mgr_ = EnemyDataManager::GetInstance(); //p


	//UITurnView�p�̉摜�n���h���z��
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

	//debug�ɂ����ϐ�
	int debug_mp_x = 0;
	int debug_mp_y = 0;

};