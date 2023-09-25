#pragma once
#include "gm_ui_component.h"

#include "../dxlib_ext/dxlib_ext.h"
#include "gm_ui_card.h"
#include "gm_ui_button.h"
#include "gm_unit_ally.h"

class UIDeckEdit : public UIComponent {
public:

	UIDeckEdit() {
	
		back_button_ = std::make_shared<UIButton>();
	
	}
	~UIDeckEdit() {}

	void Initialzie();
	void Update(float delta_time) override;
	void Render() override;

	void SetDeckEditAlly(std::shared_ptr<AllyData> deck_edit_ally_data) { deck_edit_ally_data_ = deck_edit_ally_data; }
	void SetAllCardUI(std::vector<std::shared_ptr<UICard>> all_card_ui) { all_card_ui_ = all_card_ui; }
	void SetDeckCardUI(std::vector<std::shared_ptr<UICard>> deck_card_ui) { deck_card_ui_ = deck_card_ui; }

	void RenderChoiceCardUI(std::shared_ptr<Card> choice_card);


private:

	std::shared_ptr<AllyData> deck_edit_ally_data_ = nullptr;
	std::shared_ptr<Card> choice_card_ = nullptr;
	

	//UISize定数
	int h1 = DXE_WINDOW_HEIGHT / 10;
	int w1 = DXE_WINDOW_WIDTH / 10;
	int box_space_ = 10;
	//leftboxpos
	int leftbox_upper_left_x = 0 + box_space_;
	int leftbox_upper_left_y = 0 + box_space_ + h1*1;
	int leftbox_lower_right_x = w1*2 - box_space_;
	int	leftbox_lower_right_y = h1*10 - box_space_;
	//middleboxpos
	int middlebox_upper_left_x = w1*2 + box_space_;
	int middlebox_upper_left_y = 0 + box_space_;
	int middlebox_lower_right_x = w1*7 - box_space_;
	int	middlebox_lower_right_y = h1*10 - box_space_;
	//rightboxpos
	int rightbox_upper_left_x = w1*7 + box_space_;
	int rightbox_upper_left_y = 0 + box_space_;
	int rightbox_lower_right_x = w1*10 - box_space_;
	int	rightbox_lower_right_y = h1*10 - box_space_;


	//UIインスタンス
	std::shared_ptr<UIButton> back_button_ = nullptr;
	std::vector<std::shared_ptr<UICard>> all_card_ui_;
	std::vector<std::shared_ptr<UICard>> deck_card_ui_;


	//color
	int leftbox_color = GetColor(52, 53, 65);
	int middlebox_color = GetColor(52, 53, 65);
	int rightbox_color = GetColor(52, 53, 65);


};