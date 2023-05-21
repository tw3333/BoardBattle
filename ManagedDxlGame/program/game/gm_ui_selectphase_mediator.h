#pragma once
#include "gm_ui_mediator.h"
#include <vector>
#include <memory>

//memo
//SceneSelectPhase‚É‘Î‰ž‚µ‚½AConcreteMediatorƒNƒ‰ƒX


class UISelectPhaseMediator : public UIMediator {
public:

	UISelectPhaseMediator() {}
	~UISelectPhaseMediator(){}



	void SetMediators() { 
		for (auto uc : ui_components_) { uc->setMediator(this); } 
	}
	void Notify(UIComponent* sender, std::string event) const override;


private:

	std::vector<UIComponent*> ui_components_;



};
