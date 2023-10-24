#pragma once
#include "gm_ui_component.h"
#include "../dxlib_ext/dxlib_ext.h"
#include "gm_unit.h"



class UITurnIcon : public UIComponent {
public:

	UITurnIcon(dxe::Camera* camera){
		camera_ = camera;
	}

	~UITurnIcon() { 
		delete camera_; 
		delete turn_unit_
	}

	void Update(float delta_time) override;
	void Render() override;

	void SetISRender(bool is_render) { is_render_ = is_render; }
	bool GetIsRender() { return is_render_; }
	

private:

	dxe::Camera* camera_ = nullptr; //Obj用カメラポインタ

	bool is_render_ = false;

	Unit* turn_unit_ = nullptr;




};