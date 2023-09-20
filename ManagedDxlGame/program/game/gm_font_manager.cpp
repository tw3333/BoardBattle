#include "gm_font_manager.h"

void FontManager::CreateFontData() {

	card_name_font_ = CreateFontToHandle(NULL, 18, 10);
	card_cost_font_ = CreateFontToHandle(NULL,25,25);
	card_explanation_font_ = CreateFontToHandle(NULL, 15, 1);
	notice_target_num_font_ = CreateFontToHandle(NULL, 30, 20);
	


}
