#pragma once
#include <memory>

#include "gm_object_ally.h"
#include "gm_object_enemy.h"
#include "gm_object_square.h"
#include "gm_object_move_select_flame.h"
#include "gm_object_battle_state_icon.h"
#include "gm_anim_sprite3d.h"


#include "gm_texture_manager.h"

//memo
//マジックスタティックを用いて作成
//Singleton設計

class ObjectManager {
public:

	static ObjectManager& GetInstance() {

		static ObjectManager instance_;
		return instance_;

	}



	//コピーコンストラクタ削除
	ObjectManager(const ObjectManager&) = delete;
	ObjectManager& operator=(const ObjectManager&) = delete;
	//ムーブコンストラクタ削除
	ObjectManager(ObjectManager&&) = delete;
	ObjectManager& operator=(ObjectManager&&) = delete;

	//memberfunction
	void CreateObjAllys();
	ObjAlly* GetObjAllyAtID(int id){ 
		for (auto oa : obj_allies_) {
			if (oa->GetObjAllyID() == id) { return oa; }
		}
		return nullptr;
	}


	void CreateObjEnemies();
	ObjEnemy* GetObjEnemyAtID(int id){
		for (auto oe : obj_enemies_) {
			if (oe->GetObjEnemyId() == id) { return oe; }
		}
		return nullptr;
	}

	void CreateObjSquares();
	ObjMoveSelectFlame* GetObjMoveSelectFlame() { return obj_move_select_flame_; }
	ObjSquare* GetSquaresAtIndex(int row, int col) { return obj_squares_[row][col]; }

	void CreateDebugCardAnimSprites();
	std::vector<std::shared_ptr<AnimSprite3D>> GetDebugCardAnimSprites() { return debug_card_anim_sprites_; }

	void CreateObjBattleStateIcon(std::vector<std::shared_ptr<dxe::Texture>> texture);

	std::shared_ptr<ObjBattleStateIcon>& GetObjBattleStateIcon() { return obj_battle_state_icon_; }
	
private:
	
	//GetInstance以外での生成防止
	ObjectManager() = default;
	~ObjectManager() = default;


	std::vector<ObjAlly*> obj_allies_;
	std::vector<ObjEnemy*> obj_enemies_;

	std::vector<std::shared_ptr<AnimSprite3D>> card_anim_sprites_;
	std::vector<std::shared_ptr<AnimSprite3D>> debug_card_anim_sprites_;




	ObjSquare* obj_square_ = nullptr;

	ObjSquare* obj_squares_[10][10];

	ObjMoveSelectFlame* obj_move_select_flame_;

	std::shared_ptr<ObjBattleStateIcon> obj_battle_state_icon_;

};