#pragma once


//memo
//各Sceneクラスの基底クラス

class SceneBase {
public:
	SceneBase(){}
	virtual ~SceneBase(){}

	virtual void Initialzie() = 0;
	virtual void Update(float delta_time) {}
	virtual void Render(){}




private:

};