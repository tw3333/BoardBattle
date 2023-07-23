#pragma once
#include "gm_object_ally.h"
#include "gm_object_enemy.h"
#include "gm_object_square.h"
#include "gm_object_move_select_flame.h"


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

	
private:
	
	//GetInstance以外での生成防止
	ObjectManager() = default;
	~ObjectManager() = default;


	std::vector<ObjAlly*> obj_allies_;
	std::vector<ObjEnemy*> obj_enemies_;



	ObjSquare* obj_square_ = nullptr;

	ObjSquare* obj_squares_[10][10];

	ObjMoveSelectFlame* obj_move_select_flame_;

};