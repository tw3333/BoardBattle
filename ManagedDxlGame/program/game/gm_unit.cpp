#include "gm_unit.h"

void Unit::DecreaseBattleStateTurn() {

	//�eState�̃^�[�������炷(1)
	for (auto &state : state_) {

		if (state.GetIsAddTurn()) {
			continue;
		}
		else {

			if (state.GetTurnCount() > 0) {

				if (state.GetIsAddTurn()) {
					continue;
				}
				else {
					state.DecreaseTurnCount(1);
				}

			}

		}

	}

	//turn��0��BattleState�͍폜
	state_.erase(std::remove_if(state_.begin(), state_.end(),
		[](BattleState& state) { return state.GetTurnCount() == 0; }), state_.end());

}

bool Unit::IsBattleStateAllProcedStartOfTurn()
{
	if (state_.empty()) {
		return true;
	}
	else if (!state_.empty()) {
		
		for (auto& state : state_) {

			if (!state.GetIsProc()) {
				return false;
			}

		}

	}

	return true;
}

void Unit::ResetAllBattleStateProced() {

	if (!state_.empty()) {

		for (auto& state : state_) {
			state.SetIsProc(false);	
		}

	}

}
