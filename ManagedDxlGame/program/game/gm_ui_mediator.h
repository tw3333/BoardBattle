#pragma once
#include <string>
#include "gm_ui_component.h"

class UIComponent;

class UIMediator {
public:

	virtual void notify(UIComponent* sender, std::string event) const = 0;

private:

};