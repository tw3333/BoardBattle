#pragma once
#include "gm_object_ally.h"
#include "gm_object_enemy.h"
#include "gm_object_square.h"
#include "gm_object_move_select_flame.h"

#include "gm_enemydata_manager.h"

//memo
//�}�W�b�N�X�^�e�B�b�N��p���č쐬
//Singleton�݌v

class ObjectManager {
public:

	static ObjectManager& GetInstance() {

		static ObjectManager instance_;
		return instance_;

	}



	//�R�s�[�R���X�g���N�^�폜
	ObjectManager(const ObjectManager&) = delete;
	ObjectManager& operator=(const ObjectManager&) = delete;
	//���[�u�R���X�g���N�^�폜
	ObjectManager(ObjectManager&&) = delete;
	ObjectManager& operator=(ObjectManager&&) = delete;

	//memberfunction
	void CreateObjAllys();
	ObjAlly* GetObjAllyAtID(int id){ 
		for (auto oa : obj_allys_) {
			if (oa->GetObjAllyID() == id) { return oa; }
		}
		return nullptr;
	}

	std::shared_ptr<ObjAlly> GetObjAllyAtIndex(int index) const {
		if (index < 0 || index >= obj_allies_.size()) {
			return nullptr;
		}
		return obj_allies_[index];
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
	
	//GetInstance�ȊO�ł̐����h�~
	ObjectManager() = default;
	~ObjectManager() = default;

	//membervariable
	//std::vector<Shared<ObjAlly>> obj_allys_;
	std::vector<ObjAlly*> obj_allys_;
	std::vector<ObjEnemy*> obj_enemies_;

	std::vector<std::shared_ptr<ObjAlly>> obj_allies_;


	EnemyDataManager* emgr_ = EnemyDataManager::GetInstance();

	ObjSquare* obj_square_ = nullptr;

	ObjSquare* obj_squares_[10][10];

	ObjMoveSelectFlame* obj_move_select_flame_;

};