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

	void MoveRange(UnitAlly* unit);
	void CrearMoveRange();
	void SetTurnUnitAlly(UnitAlly* turn_ally) { turn_ally_ = turn_ally; }
	void ExploreMoveRange(UnitAlly* unit, int cur_row, int cur_col, int remaining_cost);

	std::array<std::array<int, 10>, 10> GetReachableSquares(UnitAlly* unit);
	void UpdateRender(std::array<std::array<int, 10>, 10> reachable,UnitAlly* unit);
private:

	ObjectManager& omgr_ = ObjectManager::GetInstance();

	ObjMoveSelectFlame* flame_ = omgr_.GetObjMoveSelectFlame();
	UnitAlly* turn_ally_ = nullptr;
	SelectSquare* select_square_ = nullptr;

	std::array<std::array<Square*, 10>, 10> board_squares_;


	const int dx_[4] = { 0, 1, 0, -1 };
	const int dy_[4] = { 1, 0, -1, 0 };

	//SelectSquareƒNƒ‰ƒX‚©‚çŽæ“¾
	int select_square_row_ = 0;
	int select_square_col_ = 0;

};