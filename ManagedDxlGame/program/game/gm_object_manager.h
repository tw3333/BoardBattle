#pragma once
#include "gm_object_ally.h"

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
			if (oa->GetObjAllyID() == id) {
				return oa;
			}

		}
		return nullptr;
	}

private:
	
	//GetInstance�ȊO�ł̐����h�~
	ObjectManager() = default;
	~ObjectManager() = default;

	//membervariable
	//std::vector<Shared<ObjAlly>> obj_allys_;
	std::vector<ObjAlly*> obj_allys_;


};