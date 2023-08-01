#pragma once
#include "gm_ui_component.h"
#include "gm_font_manager.h"


class Card;

class UICard : public UIComponent {
public:

	UICard(int posx, int posy, int width, int height)
	:pos_x_(posx), pos_y_(posy), width_(width), height_(height)
	{}
	~UICard(){}

	void Update(float delta_time) override;
	void Render() override;
	void SetIsRender(bool flag) { is_render_ = flag; }
	bool GetIsRender() { return is_render_; }
	void SetIsCardUp(bool flag) { card_up_ = flag; }
	bool GetIsCardUp() { return card_up_; }
	void SetPos(int pos_x, int pos_y) { pos_x_ = pos_x; pos_y_ = pos_y; }
	int GetStartPosX() { return pos_x_; }
	int GetEndPosX() { return pos_x_ + width_; }
	bool IsMouseInside(int mx, int my);
	
	void SetCardPtr(std::shared_ptr<Card> card_ptr) { card_ptr_ = card_ptr; }
	std::shared_ptr<Card> GetCardPtr() { return card_ptr_; }

	std::vector<std::string> SplitCardExplanation(std::string explanation, size_t n);

	int debug_cnt_ = 0;
	int debug_txt_y_ = 0;

private:

	std::shared_ptr<Card> card_ptr_ = nullptr; //UICardに格納するCardのインスタンス

	
	bool is_render_ = false;


	int pos_x_;
	int pos_y_;
	int width_;
	int height_;
	int pre_pos_y_ = pos_y_; //規定位置
	int card_up_pos_y_ = pos_y_ - 30; //カードが上がった時の位置

	//float pos_x_;
	//float pos_y_;
	//float width_;
	//float height_;
	//float pre_pos_y_ = pos_y_; //規定位置
	//float card_up_pos_y_ = pos_y_ - 30; //カードが上がった時の位置



	bool card_up_ = false;

	int w1_ = width_ / 10;
	int h1_ = height_ / 10;

	std::string debug_text_ = "デバック用";
	std::string debug_text2_ = "カードです";

	std::vector<std::string> split_explanation_;

	FontManager& font_mgr_ = FontManager::GetInstance();

	int debug_graph_ = LoadGraph("graphics/card/c1/bleeding-heart.png");

	//ColorCode
	int	color_ground_work_ = GetColor(211,204,196);
	int color_black_ = GetColor(0,0,0);
	int color_effect_back_ = GetColor(83,61,49);
	int color_cardname_back_ = GetColor(129,58,57);
	int color_cardname_flame_ = GetColor(67,45,37);
	int color_orange_ = GetColor(255, 165, 0);

};