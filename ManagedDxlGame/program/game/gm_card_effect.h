#pragma once
#include <vector>

#include "gm_data_board.h"
#include "gm_anim_manager.h"

class Unit;
class Board;


class CardEffect {
public:

	CardEffect(int card_id, int ref_num) : card_id_(card_id), effect_ref_num_(ref_num) {}
	virtual ~CardEffect(){}

	//virtual CardEffect* CreateClone() = 0;
	//virtual void InitCardEffect() = 0;

	virtual void Effect(std::vector<Unit*> untis) = 0;
	//virtual void ExcuteEffect(std::vector<EffectBoardPos> effect_board_pos) = 0;
	virtual void EffectExcute(std::vector<SquarePos> target_square_pos, Board* board) = 0; //効果の実行
	
	virtual bool CanEffectExcute(std::vector<SquarePos> target_square_pos, Board* board) = 0; //効果が実行できるか判定

	virtual bool CanEffectExcuteFromRange(std::vector<SquarePos> range_suqare, Board* board) = 0;
	virtual bool CanEffectExcuteFromTarget() = 0;
	

	//int effect_ref_num_ = 0;
	int GetCardID() { return card_id_; }
	int GetEffectRefNum() { return effect_ref_num_; }

protected:

	int card_id_ = 0; //効果を持つカードのID
	int effect_ref_num_ = 0; //CardTargetとの参照番号

	AnimManager& anim_mgr_ = AnimManager::GetInstance();


};