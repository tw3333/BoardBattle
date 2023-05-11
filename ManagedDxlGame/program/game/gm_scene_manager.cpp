#include "gm_scene_manager.h"

#include "scene/gm_scene_battle.h"
#include "scene/gm_scene_load.h"

SceneManager* SceneManager::instance_ = nullptr;

//コンストラクタ
SceneManager::SceneManager() {
	
	scene_now_ = new SceneLoad();
	scene_now_->Initialzie();
	img_black_ = LoadGraph("graphics/512.bmp");

	SetBackgroundColor(32,32,32);

}

//デストラクタ
SceneManager::~SceneManager() {
	if (scene_now_) { delete scene_now_;  }
	if (scene_next_) { delete scene_next_; }
}

//SceneManagerインスタンス取得
SceneManager* SceneManager::GetInstance() {
	if (!instance_) {
		instance_ = new SceneManager();
	}
	return instance_;
}

//SceneManagerのインスタンス破棄
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

bool SceneManager::seqSceneInTransition(const float delta_time)
{
	if (sequence_.isStart()) {
		scene_transition_time_ = 0;
	}
	
	scene_transition_time_ += delta_time;

	scene_transition_alpha_ = 1.0f - (scene_transition_time_ / SCENE_TRANSITION_FIX_TIME);

	if (scene_transition_time_ > SCENE_TRANSITION_FIX_TIME) {
		sequence_.change(&SceneManager::seqGameProcess);
	}
	
	return true;
}

bool SceneManager::seqGameProcess(const float delta_time)
{
	scene_now_->Update(delta_time);
	return true;
}

bool SceneManager::seqSceneOutTransition(const float delta_time)
{
	if (sequence_.isStart()) {
		scene_transition_time_ = 0;
	}
	scene_transition_time_ += delta_time;
	scene_transition_alpha_ = (scene_transition_time_ / SCENE_TRANSITION_FIX_TIME);

	if (scene_transition_time_ > SCENE_TRANSITION_FIX_TIME) {
		delete scene_now_;
		scene_now_ = scene_next_;
		scene_now_->Initialzie();
		scene_next_ = nullptr;
		sequence_.change(&SceneManager::seqSceneInTransition);
	}
	return true;
}

void SceneManager::Update(float delta_time) {
	sequence_.update(delta_time);
	scene_now_->Render();

	int col = static_cast<int>(255.0f * scene_transition_alpha_);
	if (0 >= col) return;
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, col);
	DrawExtendGraph(0, 0, DXE_WINDOW_WIDTH, DXE_WINDOW_HEIGHT, img_black_, false);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}