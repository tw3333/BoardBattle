#pragma once
#include <string>
#include "../dxlib_ext/dxlib_ext.h"



//memo
//�e�J�[�h�̃f�[�^��\���N���X
class CardEffect;
class CardRange;

enum class TargetType {
	SpecifyTarget, //�Ώێw��
	SpecifyRange, //�͈͎w��
	AllRange, //�˒������ׂĂ��w���
};


class CardData {
public:

	CardData(int card_id, int card_cost, TargetType target_type, int target_num, std::string name, std::string card_explanation, std::string texture_path)
	:card_id_(card_id), card_cost_(card_cost), card_name_(name), card_explanation_(card_explanation)
	, card_texture_(dxe::Texture::CreateFromFile(texture_path))
	{}
	~CardData(){}

	int GetCardID() { return card_id_; }
	int GetCardCost() { return card_cost_; }
	bool GetIsSpecifyTarget() { return is_specify_target_; }
	int GetTargetNum() { return target_num_; }
	
	std::string GetCardName() { return card_name_; }
	std::string GetCardExplanation() { return card_explanation_; }

	
	std::shared_ptr<dxe::Texture> GetCardTexture() const { return card_texture_; }
	
	std::vector<std::shared_ptr<CardEffect>>GetCardEffectList() {
		return card_effect_list_;
	}
	std::vector<std::shared_ptr<CardRange>> GetCardRangeList() {
		return card_range_list_;
	}

	void AddCardEffect(std::shared_ptr<CardEffect> card_effect) {
		card_effect_list_.push_back(card_effect);
	}
	void AddCardRange(std::shared_ptr<CardRange> card_range) {
		card_range_list_.push_back(card_range);
	}

	std::vector<CardEffect*> debug_card_effect_list_;
	std::vector<CardRange*> debug_card_range_list_;

	CardRange* card_range_ = nullptr;
	std::string debug_anim_name_ = "debug_anim";

	TargetType GetTargetType() { return target_type_; }

private:

	int card_id_;
	int card_cost_;

	bool is_specify_target_ = false; //�w��^�[�Q�b�g���ǂ���
	TargetType target_type_;
	int target_num_ = 0;


	
	std::string card_name_;
	std::string card_explanation_; //�J�[�h�̌��ʕ�
	std::vector<std::string> split_explanation_; //�J�[�h�̌��ʕ��𕪊���������
	
	

	std::shared_ptr <dxe::Texture> card_texture_;

	
	std::vector<std::shared_ptr	<CardEffect>> card_effect_list_;
	std::vector<std::shared_ptr <CardRange>> card_range_list_;
};