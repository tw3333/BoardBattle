#include "gm_object_manager.h"




//ObjSquareを作成してpool
void ObjectManager::CreateObjSquares() {

	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {

			obj_squares_[i][j] = ObjSquare::Create();

		}

	}



	obj_move_select_flame_ = ObjMoveSelectFlame::Create();
}


void ObjectManager::CreateObjAllys() {

	//ID:1
	ObjAlly* obj_ally1 = ObjAlly::CreateAlly(1,"graphics/unit/ally/c1_battle.png");
	obj_ally1->SetObjAllyID(1);

	//ID:2
	ObjAlly* obj_ally2 = ObjAlly::CreateAlly(2,"graphics/unit/ally/c2_battle.png");
	obj_ally2->SetObjAllyID(2);

	//ID:3
	ObjAlly* obj_ally3 = ObjAlly::CreateAlly(3,"graphics/unit/ally/c3_battle.png");
	obj_ally3->SetObjAllyID(3);

	//ID:4
	ObjAlly* obj_ally4 = ObjAlly::CreateAlly(4,"graphics/unit/ally/c4_battle.png");
	obj_ally4->SetObjAllyID(4);

	obj_allies_.push_back(obj_ally1);
	obj_allies_.push_back(obj_ally2);
	obj_allies_.push_back(obj_ally3);
	obj_allies_.push_back(obj_ally4);


}

void ObjectManager::CreateObjEnemies() {

	for (int i = 1; i <= 10; ++i) {

		ObjEnemy* obj_enemy = ObjEnemy::Create(emgr_->GetEnemyDataAtID(i));
		obj_enemy->SetObjEnemyID(i);
		obj_enemies_.push_back(obj_enemy);

	}

}



