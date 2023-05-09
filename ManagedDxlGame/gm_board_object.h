#pragma once
#include "program/game/gm_unit.h"

//memo
//Board上のオブジェクトを作成するFactoryクラス

class BoardObject {
public:
	
	BoardObject() {};
	virtual ~BoardObject() {}

	virtual void Update();
	virtual void Render();


private:





};
