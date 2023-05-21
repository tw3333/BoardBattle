#include "gm_ui_panel.h"

void UIPanel::Update(float delta_time) {


}

void UIPanel::Render() {

	if (graph_handle_) {

		DrawExtendGraph(x_,y_,x_ + width_, y_ + height_ ,graph_handle_,false);

		
	}
	else if (graph_handle_) {

		DrawBox(x_,y_, x_ + width_, y_ + height_, -1 ,true);

	}



}