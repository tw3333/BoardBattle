#pragma once


//memo
//�eScene�N���X�̊��N���X

class SceneBase {
public:
	SceneBase(){}
	virtual ~SceneBase(){}

	virtual void Initialzie() = 0;
	virtual void Update(float delta_time) {}
	virtual void Render(){}




private:

};