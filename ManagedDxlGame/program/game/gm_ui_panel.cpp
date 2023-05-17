#include "gm_ui_panel.h"

void UIPanel::Update(float delta_time) {


}

void UIPanel::Render() {

	if (img_handle_ != 0) {

		DrawExtendGraph(x_,y_,x2_,y2_,img_handle_,-1);

		
	}



}