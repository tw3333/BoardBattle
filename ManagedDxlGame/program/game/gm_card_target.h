#pragma once
#include <vector>

#include "gm_data_board.h"

//memo
//カードの対象を格納するクラス

enum class TARGETTYPE {
	InRange,
	Specify,
	None //初期化用
};

enum class TOTARGET {
	Ally,
	Enemy,
	Square, //マス指定
	CanMoveSqure, //移動できるマス指定
	Self, //自身を指定
	All, //各Unitに
	None //初期化用
};

class Unit;
class Board;

//memo
//範囲指定だった場合、target_numは0で設定する
//対象指定はその数で

class CardTarget {
public:

	CardTarget(int card_id,int ref_num, TARGETTYPE target_type, TOTARGET to_target, int target_num = 0) {
		card_id_ = card_id;
		target_ref_num_ = ref_num;
		target_type_ = target_type;
		to_target_ = to_target;
		target_num_ = target_num;
	}
	~CardTarget() { for (auto a : target_units_) { delete a; } }


	TARGETTYPE GetTargetType() { return target_type_; }
	TOTARGET GetToTarget() { return to_target_; }
	int GetTargetNum() { return target_num_; }
	bool GetIsSpecified() { return is_specified_; }
	void SetIsSpecified(bool is_specified) { is_specified_ = is_specified; }

	bool GetIsDetermined() { return is_determined_; }
	void SetIsDetermined(bool is_determined) { is_determined_ = is_determined; }


	int GetCardID() { return card_id_; }
	int GetTargetRefNum() { return target_ref_num_; }

	std::vector<Unit*>& GetTargetUnits() { return target_units_; }
	void SetTargetUnits(std::vector<Unit*> target_units) { target_units_ = target_units; }
	void AddTargetUnit(Unit* target_unit) { target_units_.push_back(target_unit); }

	void SetTargetSquaresPos(std::vector<SquarePos> target_squares_pos) { target_squares_pos_ = target_squares_pos; }
	std::vector<SquarePos>& GetTargetSquaresPos() { return target_squares_pos_; }
	void AddTargetSquarePos(SquarePos target_square_pos) { target_squares_pos_.push_back(target_square_pos); }
	void AddTargetSquarePoses(std::vector<SquarePos> target_square_poses) { target_squares_pos_.insert(target_squares_pos_.end(), target_square_poses.begin(), target_square_poses.end()); }

	bool IsTargetInRange(std::vector<SquarePos> range, Board* board);
	void ResetTargetSquarePos() { if (!target_squares_pos_.empty()) { target_squares_pos_.clear(); } }

	

private:

	int card_id_ = 0; //対応するカードのID

	TARGETTYPE target_type_ = TARGETTYPE::None;
	TOTARGET to_target_ = TOTARGET::None;
	
	bool is_specified_ = false;
	bool is_determined_ = false; //Targetが決定したかどうか

	int target_num_ = 0;
	int target_ref_num_ = 0; //CardEffectとの照合番号


	std::vector<Unit*> target_units_;
	std::vector<SquarePos> target_squares_pos_; //効果を発動するマス目,各Unitの座標
};