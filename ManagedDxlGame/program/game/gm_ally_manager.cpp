#include "gm_ally_manager.h"

AllyManager* AllyManager::instance_ = nullptr;

AllyManager* AllyManager::GetInstance() {

	if (!instance_) { instance_ = new AllyManager(); }
	return instance_;

}

void AllyManager::Destory() {

	if (instance_) { 
		delete instance_; 
		instance_ = nullptr;
	}

}

