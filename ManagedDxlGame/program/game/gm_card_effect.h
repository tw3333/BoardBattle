#pragma once
#include <vector>

#include "gm_data_board.h"

class Unit;
class Board;


class CardEffect {
public:

	CardEffect(int ref_num) : effect_ref_num_(ref_num) {}
	virtual ~CardEffect(){}

	//virtual CardEffect* CreateClone() = 0;

	virtual void Effect(std::vector<Unit*> untis) = 0;
	//virtual void ExcuteEffect(std::vector<EffectBoardPos> effect_board_pos) = 0;
	virtual void EffectExcute(std::vector<SquarePos> target_square_pos, Board* board) = 0; //���ʂ̎��s
	virtual bool CanEffectExcute(std::vector<SquarePos> target_square_pos, Board* board) = 0; //���ʂ����s�ł��邩����

	

	//int effect_ref_num_ = 0;

	int GetEffectRefNum() { return effect_ref_num_; }

protected:

	int effect_ref_num_ = 0; //CardTarget�Ƃ̎Q�Ɣԍ�


};