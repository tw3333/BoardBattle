#pragma once
#include "gm_ui_component.h"
#include "gm_unit_ally.h"

//memo
//���W�Ƃ��̑傫������l�p�`
//���l�߂ŃJ�[�h�R�X�g���Z�ŕ\��


class UICardCost : public UIComponent {
public:

	UICardCost() {}
	~UICardCost() { delete unit_ally_; }


	void Update(float delta_time) override;
	void Render() override;



private:

	UnitAlly* unit_ally_ = nullptr;

	int x_;
	int y_;

	int width_;
	int height_;



};