#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include "gm_ui_mediator.h"

//memo
//ŠeUIComponent‚ÌU‚é•‘‚¢‚ÌÀ‘•‚ÍMediator‚É‚ÄÀ‘•
//UI‚ÌŠî’êƒNƒ‰ƒX


class UIComponent {
public:


	virtual ~UIComponent() { }

	virtual void Update(float delta_time) = 0;
	virtual void Render() = 0;

	
	void SetMediator(UIMediator* mediator) { mediator_= mediator; }

protected:

	UIMediator* mediator_ = nullptr;

};