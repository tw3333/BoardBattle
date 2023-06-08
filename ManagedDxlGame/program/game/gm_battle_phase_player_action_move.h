#pragma once
#include "gm_battle_phase.h"

#include <array>
#include "gm_object_manager.h"
#include "gm_square.h"
#include "gm_unit_ally.h"

#include "gm_select_square.h"


class PhasePlayerActionMove : public BattlePhase {
public:

	PhasePlayerActionMove(UnitAlly* turn_ally,SelectSquare* select_square, const std::array<std::array<Square*, 10>, 10> board_squares)
	:turn_ally_(turn_ally), select_square_(select_square), board_squares_(board_squares) 
	{}
	~PhasePlayerActionMove(){}


	void BeginPhase() override;
	void EndPhase() override;

	bool UpdateExecute(float delta_time) override;
	bool RenderExecute(dxe::Camera* camera) override;

	//member
	void SetSelectSquare(int row, int col) { 
		select_square_row_ = row;
		select_square_col_ = col;
	}

	void DisplayMoveRange(UnitAlly* unit);
	void CrearMoveRange();
	void SetTurnUnitAlly(UnitAlly* turn_ally) { turn_ally_ = turn_ally; }


private:

	ObjectManager& omgr_ = ObjectManager::GetInstance();

	ObjMoveSelectFlame* flame_ = omgr_.GetObjMoveSelectFlame();
	UnitAlly* turn_ally_ = nullptr;
	SelectSquare* select_square_ = nullptr;
	std::array<std::array<Square*, 10>, 10> board_squares_;


	//SelectSquareƒNƒ‰ƒX‚©‚çŽæ“¾
	int select_square_row_ = 0;
	int select_square_col_ = 0;

};