#pragma once
#include "program/game/gm_unit.h"

//memo
//Board��̃I�u�W�F�N�g���쐬����Factory�N���X

class BoardObject {
public:
	
	BoardObject() {};
	virtual ~BoardObject() {}

	virtual void Update();
	virtual void Render();


private:





};
