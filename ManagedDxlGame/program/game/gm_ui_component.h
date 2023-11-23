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

	
	void SetMediator(UIMediator* mediator) { mediator_= mediator; }
	void SetIsEnabled(bool is_enabled) { is_enabled_ = is_enabled; }
	void SetNotifyTag(std::string tag_name) { notify_tag_ = tag_name; }


protected:

	UIMediator* mediator_ = nullptr;
	std::string notify_tag_; //Notifyで使用する通知タグ

	bool is_enabled_ = true;

};