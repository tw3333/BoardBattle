#include "gm_unit.h"

bool Unit::IsBattleStateProcStartOfTurn()
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
