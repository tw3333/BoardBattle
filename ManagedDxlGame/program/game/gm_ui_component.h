#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include "gm_ui_mediator.h"

//memo
//各UIComponentの振る舞いの実装はMediatorにて実装
//UIの基底クラス


class UIComponent {
public:


	virtual ~UIComponent() { delete mediator_; }

	virtual void Update(float delta_time) = 0;
	virtual void Render() = 0;

	
	void setMediator(UIMediator* mediator) { mediator_= mediator; }

protected:

	UIMediator* mediator_ = nullptr;

};