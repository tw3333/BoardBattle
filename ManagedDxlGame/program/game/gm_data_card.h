#pragma once
#include <string>
#include "../dxlib_ext/dxlib_ext.h"

//memo
//各カードのデータを表すクラス
class CardEffect;
class CardRange;
class CardTarget;



class CardData {
public:

	CardData(int card_id,int poss_ally_id, int card_cost, std::string name, std::string card_explanation, std::string texture_path,std::string anim_name)
	:card_id_(card_id), poss_ally_id_(poss_ally_id), card_cost_(card_cost), card_name_(name), card_explanation_(card_explanation)
	, card_texture_(dxe::Texture::CreateFromFile(texture_path)),card_anim_name_(anim_name)
	{}
	~CardData(){}

	int GetCardID() { return card_id_; }
	int GetPossAllyID() { return poss_ally_id_; }
	int GetCardCost() { return card_cost_; }
	std::string GetCardName() { return card_name_; }
	std::string GetCardExplanation() { return card_explanation_; }
	std::shared_ptr<dxe::Texture> GetCardTexture() const { return card_texture_; }
	
	std::vector<std::shared_ptr<CardEffect>> GetCardEffectList() { return card_effect_list_; }
	std::vector<std::shared_ptr<CardRange>> GetCardRangeList() { return card_range_list_; }
	std::vector<std::shared_ptr<CardTarget>> GetCardTargetList() { return card_target_list_; }

	void AddCardEffect(std::shared_ptr<CardEffect> card_effect) {
		card_effect_list_.push_back(card_effect);
	}
	void AddCardRange(std::shared_ptr<CardRange> card_range) {
		card_range_list_.push_back(card_range);
	}

	void AddCardTarget(std::shared_ptr<CardTarget> card_target) {
		card_target_list_.push_back(card_target);
	}

	std::string debug_anim_name_ = "debug_anim";

	std::string GetCardAnimName() { return card_anim_name_; }


private:

	int card_id_;
	int card_cost_;
	int poss_ally_id_; //カードを所持できる味方のID
	std::string card_name_;
	std::string card_explanation_; //カードの効果文
	std::shared_ptr <dxe::Texture> card_texture_;
	std::vector<std::string> split_explanation_; //カードの効果文を分割したもの

	std::string card_anim_name_; //カードのアニメーション名
	
		
	std::vector<std::shared_ptr<CardEffect>> card_effect_list_;
	std::vector<std::shared_ptr<CardRange>> card_range_list_;
	std::vector<std::shared_ptr<CardTarget>> card_target_list_;


};