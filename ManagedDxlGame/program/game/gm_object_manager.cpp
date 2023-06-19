#include "gm_object_manager.h"




//ObjSquare‚ğì¬‚µ‚Äpool
void ObjectManager::CreateObjSquares() {

	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {

			obj_squares_[i][j] = ObjSquare::Create();

		}

	}



	obj_move_select_flame_ = ObjMoveSelectFlame::Create();
}


void ObjectManager::CreateObjAllys() {

	ObjAlly* obj_ally = new ObjAlly();

	//ID:1
	ObjAlly* obj_ally1 = obj_ally->CreateAlly("graphics/unit/enemy/1486010403.png");
	obj_ally1->SetObjAllyID(1);

	//ID:2
	ObjAlly* obj_ally2 = obj_ally->CreateAlly("graphics/unit/ally/c2_board_img.png");
	obj_ally2->SetObjAllyID(2);

	//ID:3
	ObjAlly* obj_ally3 = obj_ally->CreateAlly("graphics/unit/ally/c3_board_img.png");
	obj_ally3->SetObjAllyID(3);

	//ID:4
	ObjAlly* obj_ally4 = obj_ally->CreateAlly("graphics/unit/ally/c4_board_img.png");
	obj_ally4->SetObjAllyID(4);

	obj_allys_.push_back(obj_ally1);
	obj_allys_.push_back(obj_ally2);
	obj_allys_.push_back(obj_ally3);
	obj_allys_.push_back(obj_ally4);

	delete obj_ally;
}

void ObjectManager::CreateObjEnemies() {

	for (int i = 1; i <= 10; ++i) {

		ObjEnemy* obj_enemy = ObjEnemy::Create(emgr_->GetEnemyDataAtID(i));
		obj_enemy->SetObjEnemyID(i);
		obj_enemies_.push_back(obj_enemy);

	}

}



