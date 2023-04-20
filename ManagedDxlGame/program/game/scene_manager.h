#pragma once
#include "../dxlib_ext/dxlib_ext.h"

class SceneBase;

class SceneManager {
public:

	//�C���X�^���X�̎擾
	static SceneManager* GetInstance();
	//�j��
	static void Destroy();
	//�X�V
	void Update(float delta_time);

	//�V�[���̕ύX
	//arg1...Scenebase���p�������N���X�̃C���X�^���X
	void ChengeScene(SceneBase* next);

private:

	SceneManager();
	~SceneManager();

	int img_black_;

	static SceneManager* instance_;


	// ��ʑJ�ډ��o�̎���
	const float SCENE_TRANSITION_FIX_TIME = 0.5f;
	float scene_transition_time_ = 0;
	float scene_transition_alpha_ = 1.0f;

	tnl::Sequence<SceneManager> sequence_ =
		tnl::Sequence<SceneManager>(this, &SceneManager::seqSceneInTransition);

	// ��ʑJ��( �t�F�[�h�C���v���Z�X )
	bool seqSceneInTransition(const float delta_time);

	// �Q�[���v���Z�X
	bool seqGameProcess(const float delta_time);

	// ��ʑJ��( �t�F�[�h�A�E�g�v���Z�X )
	bool seqSceneOutTransition(const float delta_time);

	// ���݂̃V�[��
	SceneBase* scene_now_ = nullptr;
	// �\��V�[��
	SceneBase* scene_next_ = nullptr;

};