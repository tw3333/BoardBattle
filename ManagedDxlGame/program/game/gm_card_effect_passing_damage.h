#pragma once
#include "gm_card_effect.h"


//memo
//�n���ꂽ�}�X�ڂɈړ��A���̒ʉ߂����}�X�ڂɂ���Unit�Ƀ_���[�W��^����
//���̎d�l���ƓG�Ƀ_���[�W��^���邱�Ƃ����ł��Ȃ��Ȃ�
//�܂�A����͓���̃J�[�h�Ɉˑ����Ă�������ɂ��܂��Ă���
//a



class CardEffectPassingDamage : public CardEffect {
public:

	CardEffectPassingDamage(int card_id, int ref_num,int damage) : CardEffect(card_id, ref_num) {
		damage_ = damage;
	}
	~CardEffectPassingDamage() {}

	void Effect(std::vector<Unit*> untis) override;
	void EffectExcute(std::vector<SquarePos> target_square_pos, Board* board) override;
	bool CanEffectExcute(std::vector<SquarePos> target_square_pos, Board* board) override;



private:

	int damage_ = 0;

};