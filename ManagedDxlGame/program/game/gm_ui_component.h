#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include "gm_ui_mediator.h"

//memo
//ŠeUIComponent‚ÌU‚é•‘‚¢‚ÌÀ‘•‚ÍMediator‚É‚ÄÀ‘•
//UI‚ÌŠî’êƒNƒ‰ƒX


class UIComponent {
public:


	virtual ~UIComponent() { delete mediator_; }

	virtual void Update(float delta_time) = 0;
	virtual void Render() = 0;

	
	void SetMediator(UIMediator* mediator) { mediator_= mediator; }
	void SetIsEnabled(bool is_enabled) { is_enabled_ = is_enabled; }
	void SetNotifyTag(std::string tag_name) { notify_tag_ = tag_name; };

protected:

	UIMediator* mediator_ = nullptr;
	std::string notify_tag_;

	bool is_enabled_ = true;

};