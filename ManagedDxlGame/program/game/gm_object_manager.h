#pragma once
#include "gm_object_ally.h"

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
		
		for (auto oa : obj_allys_) {
			if (oa->GetObjAllyID() == id) {
				return oa;
			}

		}
		return nullptr;
	}

private:
	
	//GetInstance以外での生成防止
	ObjectManager() = default;
	~ObjectManager() = default;

	//membervariable
	//std::vector<Shared<ObjAlly>> obj_allys_;
	std::vector<ObjAlly*> obj_allys_;


};