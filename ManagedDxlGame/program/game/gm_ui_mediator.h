#pragma once
#include <string>


class UIComponent;

class UIMediator {
public:

	virtual void Notify(UIComponent* sender, std::string tag_) = 0;


};

