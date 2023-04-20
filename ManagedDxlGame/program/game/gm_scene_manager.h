#pragma once
#include "../dxlib_ext/dxlib_ext.h"

class SceneBase;

class SceneManager {
public:

	//インスタンスの取得
	static SceneManager* GetInstance();
	//破棄
	static void Destroy();
	//更新
	void Update(float delta_time);

	//シーンの変更
	//arg1...Scenebaseを継承したクラスのインスタンス
	void ChengeScene(SceneBase* next);

private:

	SceneManager();
	~SceneManager();

	int img_black_;

	static SceneManager* instance_;


	// 画面遷移演出の時間
	const float SCENE_TRANSITION_FIX_TIME = 0.5f;
	float scene_transition_time_ = 0;
	float scene_transition_alpha_ = 1.0f;

	tnl::Sequence<SceneManager> sequence_ =
		tnl::Sequence<SceneManager>(this, &SceneManager::seqSceneInTransition);

	// 画面遷移( フェードインプロセス )
	bool seqSceneInTransition(const float delta_time);

	// ゲームプロセス
	bool seqGameProcess(const float delta_time);

	// 画面遷移( フェードアウトプロセス )
	bool seqSceneOutTransition(const float delta_time);

	// 現在のシーン
	SceneBase* scene_now_ = nullptr;
	// 予約シーン
	SceneBase* scene_next_ = nullptr;

};