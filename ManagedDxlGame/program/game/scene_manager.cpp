#include "scene_manager.h"

SceneManager* SceneManager::instance_ = nullptr;

//�R���X�g���N�^
SceneManager::SceneManager() {
	
	



}

//�f�X�g���N�^
SceneManager::~SceneManager() {
	if (scene_now_) { delete scene_now_;  }
	if (scene_next_) { delete scene_next_; }
}

//SceneManager�C���X�^���X�擾
SceneManager* SceneManager::GetInstance() {
	if (!instance_) {
		instance_ = new SceneManager();
	}
	return instance_;
}

//SceneManager�̃C���X�^���X�j��
void SceneManager::Destroy() {
	if (instance_) { 
		delete instance_; 
		instance_ = nullptr;
	}
}

void SceneManager::ChengeScene(SceneBase* next) {
	scene_next_ = next;
	sequence_.change(&SceneManager::seqSceneOutTransition);
}

