#include "gm_object_manager.h"



//ObjSquareÇçÏê¨ÇµÇƒpool
void ObjectManager::CreateObjSquares() {

	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {

			obj_squares_[i][j] = ObjSquare::Create();

		}

	}



	obj_move_select_flame_ = ObjMoveSelectFlame::Create();
}

void ObjectManager::CreateDebugCardAnimSprites() {


	//ç≈í·Ç≈Ç‡100ÉRïKóvÇæÇ∆Ç¢Ç§Ç±Ç∆Ç…Ç»ÇÈÇ™ÇªÇÍÇÕÇ«Ç§Ç©
	//
	for (int i = 0; i < 100; ++i) {
		debug_card_anim_sprites_.push_back(std::make_shared<AnimSprite3D>());
	}

	for (auto &anim : debug_card_anim_sprites_) {


		anim->regist(100,100,"debug_anim","graphics/effect/anim_shild.png",tnl::SeekUnit::ePlayMode::REPEAT,2.0,10,192,0,2);


	}




}

void ObjectManager::CreateObjBattleStateIcon(std::vector<std::shared_ptr<dxe::Texture>> texture) {

	obj_battle_state_icon_ = ObjBattleStateIcon::Create();


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



	ObjEnemy* obj_enemy1 = ObjEnemy::CreateEnemy(1,"graphics/unit/enemy/adoption/test_slime_battle.png");
	ObjEnemy* obj_enemy2 = ObjEnemy::CreateEnemy(2, "graphics/unit/enemy/adoption/mummy_battle.png");
	ObjEnemy* obj_enemy3 = ObjEnemy::CreateEnemy(3, "graphics/unit/enemy/adoption/pen_battle.png");
	ObjEnemy* obj_enemy4 = ObjEnemy::CreateEnemy(4, "graphics/unit/enemy/adoption/crow_battle.png");
	ObjEnemy* obj_enemy5 = ObjEnemy::CreateEnemy(5, "graphics/unit/enemy/adoption/magipon_battle.png");
	ObjEnemy* obj_enemy6 = ObjEnemy::CreateEnemy(6, "graphics/unit/enemy/adoption/candle_battle.png");
	ObjEnemy* obj_enemy7 = ObjEnemy::CreateEnemy(7, "graphics/unit/enemy/adoption/heallulu_battle.png");
	ObjEnemy* obj_enemy8 = ObjEnemy::CreateEnemy(8, "graphics/unit/enemy/adoption/attacklulu_battle.png");
	ObjEnemy* obj_enemy9 = ObjEnemy::CreateEnemy(9, "graphics/unit/enemy/adoption/golem_battle.png");
	ObjEnemy* obj_enemy10 = ObjEnemy::CreateEnemy(10, "graphics/unit/enemy/adoption/lizard_battle.png");
	ObjEnemy* obj_enemy11 = ObjEnemy::CreateEnemy(11, "graphics/unit/enemy/adoption/dragon_battle.png");

	obj_enemies_.push_back(obj_enemy1);
	obj_enemies_.push_back(obj_enemy2);
	obj_enemies_.push_back(obj_enemy3);
	obj_enemies_.push_back(obj_enemy4);
	obj_enemies_.push_back(obj_enemy5);
	obj_enemies_.push_back(obj_enemy6);
	obj_enemies_.push_back(obj_enemy7);
	obj_enemies_.push_back(obj_enemy8);
	obj_enemies_.push_back(obj_enemy9);
	obj_enemies_.push_back(obj_enemy10);
	obj_enemies_.push_back(obj_enemy11);

}



