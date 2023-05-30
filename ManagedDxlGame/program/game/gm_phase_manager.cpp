#include "gm_phase_manager.h"

PhaseManager* PhaseManager::instance_ = nullptr;

PhaseManager* PhaseManager::GetInstance() {

	if (!instance_) { instance_ = new PhaseManager(); }
	return instance_;
}

void PhaseManager::Destory() {
	if (instance_) {
		delete instance_;
		instance_ = nullptr;
	}
}

