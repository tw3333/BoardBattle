#pragma once
#include "../dxlib_ext/dxlib_ext.h"

class UIComponent {
public:


	virtual ~UIComponent(){}

	virtual void Update(float delta_time) = 0;
	virtual void Render() = 0;


};