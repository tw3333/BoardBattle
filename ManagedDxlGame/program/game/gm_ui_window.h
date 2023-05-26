#pragma once
#include "gm_ui_component.h"

//memo
//UIをWindow単位で配置できるようにするクラス


class UIWindow : public UIComponent {
public:

	UIWindow() {}
	~UIWindow() {
		for (auto ui : ui_parts_) { delete ui; }
	}

	void Update(float delta_time) override;
	void Render() override;


	void AddComponent(UIComponent* component);
	void Open() { is_opened = true; };
	void Close() { is_opened = false; };

	//getter
	std::vector<UIComponent*> getUIParts() { return ui_parts_; }


private:

	
	bool is_opened;

	std::vector<UIComponent*> ui_parts_;


};