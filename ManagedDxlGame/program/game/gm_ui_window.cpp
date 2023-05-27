#include "gm_ui_window.h"

void UIWindow::AddComponent(UIComponent* component) {

	ui_parts_.emplace_back(component);


}

void UIWindow::Update(float delta_time) {

	if(is_opened) {
		for (auto ui : ui_parts_) { ui->Update(delta_time); }
	}

}

void UIWindow::Render() {

	if (is_opened) {
		for (auto ui : ui_parts_) { ui->Render(); }
	}

}