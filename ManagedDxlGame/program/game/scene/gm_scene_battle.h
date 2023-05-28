#pragma once
#include "gm_scene_base.h"

#include "../gm_scene_manager.h"
#include "../gm_card_manager.h"
#include "../gm_allydata_manager.h"
#include "../gm_scene_battle_camera.h"
#include "../gm_object_manager.h"

#include "../gm_ui_cardview.h"

#include "../gm_object.h"
#include "../gm_object_board.h"
#include "../gm_object_ally.h"

#include "../gm_unit_ally.h"

#include "../gm_square.h"
#include "../gm_board.h"
#include "../gm_select_square.h"
#include "../gm_anim_sprite3d.h"

//memo
//�퓬�V�[����Scene�N���X

class SceneBattle : public SceneBase {
public:

	SceneBattle() {}
	~SceneBattle() {}

	void Initialzie() override;
	void Update(float delta_time) override;
	void Render() override;

	//�����o�֐�
	void DrawDebugLayOut(bool is_draw);


private:
	
	int w1 = DXE_WINDOW_WIDTH / 10;
	int h1 = DXE_WINDOW_HEIGHT / 10;

	//�����o�ϐ�
	//pointer
	SceneBattleCamera* camera_ = nullptr;
	//CardView* cardview_ = nullptr;
	CardManager* cmgr_ = nullptr;
	AllyDataManager* allydata_mgr_ = AllyDataManager::GetInstance();
	ObjBoard* obj_board_ = nullptr;
	ObjAlly* obj_ally_ = nullptr;
	
	UnitAlly* unit_ally_ = nullptr;
	UnitAlly*  unit_ally2_ = nullptr;

	Square* square_ = nullptr;
	Board* board_ = nullptr;
	SelectSquare* ss_ = nullptr;
	AnimSprite3D* sprite_ = nullptr;

	std::vector<Square*> all_square_;
	
	dxe::Mesh* debug_board_obj_ = nullptr;

	ObjectManager& omgr_ = ObjectManager::GetInstance();

	//bool
	bool is_draw_debug_layout_ = false;

	//colorcode
	int red_ = GetColor(255, 0, 0);
	int gray_ = GetColor(128,128,128);

	//debug�ɂ����ϐ�
	int debug_mp_x = 0;
	int debug_mp_y = 0;
};