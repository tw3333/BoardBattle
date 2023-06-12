#pragma once
#include <string>
#include "../dxlib_ext/dxlib_ext.h"

//memo
//各カードのデータを表すクラス

class CardData {
public:

	CardData(int card_id, int card_cost, std::string name, std::string card_explanation, std::string texture_path)
	:card_id_(card_id), card_cost_(card_cost), card_name_(name), card_explanation_(card_explanation)
	, card_texture_(dxe::Texture::CreateFromFile(texture_path))
	{}
	~CardData(){}

	int GetCardID() { return card_id_; }
	int GetCardCost() { return card_cost_; }
	
	std::string GetCardName() { return card_name_; }
	std::string GetCardExplanation() { return card_explanation_; }

	std::shared_ptr<dxe::Texture> GetCardTexture() const { return card_texture_; }


private:

	int card_id_;
	int card_cost_;
	
	std::string card_name_;
	std::string card_explanation_; //カードの効果文

	std::shared_ptr <dxe::Texture> card_texture_;



};