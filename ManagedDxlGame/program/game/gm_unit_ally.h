#pragma once
#include "gm_unit.h"
#include "gm_object_ally.h"
#include "gm_data_ally.h"
#include "gm_object_manager.h"
#include "gm_card.h"


//memo
//盤面上のUnitとしてのAllyを表すクラス
//AllyDataクラスのポインタを渡して作成


class UnitAlly : public Unit {
public:

	UnitAlly(AllyData* ally_data, int row, int col) {
	
		ally_data_ = ally_data;
		
		max_hp_ = ally_data_->GetHp();
		current_hp_ = max_hp_;
		
		max_card_cost_ = ally_data_->GetCost();
		current_card_cost_ = max_card_cost_;
		
		max_move_cost_ = ally_data_->GetMoveCost();
		current_move_cost_ = max_move_cost_;

		speed_ = ally_data_->GetSpeed();

		obj_ = ally_data->GetObj();
		
		SetBoardPos(row, col);

		obj_->Update(0);

	}
	~UnitAlly(){}

	UnitType GetUnitType() const override { return UnitType::Ally; }
	void Update();
	//void InitializeBoardAndObjPos(int row, int col);

	//setter
	//void setBoardPos(int row, int col) { 
	//	board_pos_.row = row;
	//	board_pos_.col = col;
	//}

	void SetBoardPos(int row, int col);
	BoardPos GetBoardPos() { return board_pos_; }

	//getter
	AllyData* GetAllyData() { return ally_data_; }
	ObjAlly* GetObj() {
		if (!obj_) {
			DrawStringEx(500,0,-1,"ID%dのObjがないよ",ally_data_->GetAllyDataID());
		
		}

		return obj_; 
	
	}
	void SetObj(ObjAlly* obj) { obj_ = obj; }

	int GetMaxHp() { return max_hp_; }
	int GetCurrentHp() { return current_hp_; }
	int GetMaxCardCost() { return max_card_cost_;}
	int GetCurrentCardCost() { return current_card_cost_; }
	int GetMaxMoveCost() { return max_move_cost_; }
	int GetCurrentMoveCost() { return current_move_cost_; }
	void SetCurrentMoveCost(int cost) { current_move_cost_ = cost; }
	int GetSpeed() { return speed_; }

	void SetCurrentHp(int value) { current_hp_ = value; }
	
	void DecreaseCurrentHp(int value) {
		current_hp_ = (std::max)(0, current_hp_ - value);
	}
	void IncreareCurrentHp(int value) {
		current_hp_ = (std::min)(max_hp_, current_hp_ + value);
	}

	void DecreaseCurrentCardCost(int value) {
		current_card_cost_ = (std::max)(0, current_card_cost_ - value);
	}
	
	void SetBaseDeck(std::vector<std::shared_ptr<Card>> deck) { base_deck_ = deck; }
	std::vector<std::shared_ptr<Card>> GetUseDeck() { return use_deck_; }
	std::vector<std::shared_ptr<Card>> GetHand() { return hand_; }



	int GetTauntValue() { return taunt_value_; }
	void SetTauntValue(int value) { taunt_value_ = value; }
	int GetShieldValue() { return shield_value_; }
	void SetShieldValue(int value) { shield_value_ = value; }

	//Card
	void SetIsDrewInitCard(bool flag) { is_drew_init_card_ = flag; }
	bool GetIsDrewInitCard() { return is_drew_init_card_; }


private:

	

	AllyData* ally_data_ = nullptr;
	ObjAlly* obj_ = nullptr;

	//ステータス
	int max_hp_;
	int current_hp_;

	int max_card_cost_;
	int current_card_cost_;

	int max_move_cost_;
	int current_move_cost_;

	//状態

	
	//Card
	bool is_drew_init_card_ = false; //初期カードを引いたかどうか
	std::vector<Card*> deck_; //デッキ
	//std::vector<Card*> hand_; //手札

	std::vector<std::shared_ptr<Card>> base_deck_; //デッキの元
	std::vector<std::shared_ptr<Card>> use_deck_ = base_deck_; //実際に使用するデッキ
	std::vector<std::shared_ptr<Card>> hand_; //手札





	//補正値
	int taunt_value_ = 0; //タウント値
	//int shield_value_ = 0; //シールド値

};
