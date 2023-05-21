#include "gm_ui_panel.h"

void UIPanel::Update(float delta_time) {


}

void UIPanel::Render() {

	if (img_handle_) {

		DrawExtendGraph(x_,y_,x2_,y2_,img_handle_,false);

		
	}
	else if (!img_handle_) {

		DrawBox(x_,y_,x2_,y2_,-1,true);

	}



}