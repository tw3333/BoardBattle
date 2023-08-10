#include "gm_font_manager.h"

void FontManager::CreateFontData() {

	card_name_font_ = CreateFontToHandle(NULL, 15, 10);
	card_cost_font_ = CreateFontToHandle(NULL,20,20);
	card_explanation_font_ = CreateFontToHandle(NULL, 15, 1);
	notice_target_num_font_ = CreateFontToHandle(NULL, 30, 20);
	


}
