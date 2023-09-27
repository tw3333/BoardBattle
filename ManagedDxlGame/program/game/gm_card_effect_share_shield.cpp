#include "gm_card_effect_share_shield.h"

#include "gm_board.h"
#include "gm_unit.h"
#include "gm_unit_ally.h"
#include "gm_unit_enemy.h"

void CardEffectShareShield::Effect(std::vector<Unit*> units)
{
}

bool CardEffectShareShield::CanEffectExcute(std::vector<SquarePos> range_square_pos, Board* board) {

	int ally_cnt = 0;

	//”ÍˆÍ‚É‰½l–¡•û‚ª‚¢‚é‚©‚ð’²‚×‚é
	for (auto square : range_square_pos) {

		if (board->getBoardSquare(square.row, square.col)->GetAllyPtrInSquare()) {
			ally_cnt++;
		}

	}

	if (ally_cnt == 0) {
		return false;
	}



	for (auto ally : board->GetPartyUnitsInBoard()) {

		if (ally->GetIsTurn()) {

			for (auto &state : ally->GetBattleState()) {

				if (state.GetState() == State::Shield) {
					if (state.GetValue() == 0 || state.GetValue() < ally_cnt + 1) {
						return false;
					}
				}
			}
		}
	}

	return true;
}

void CardEffectShareShield::EffectExcute(std::vector<SquarePos> target_square_pos, Board* board) {

	//”ÍˆÍ‚É‰½l–¡•û‚ª‚¢‚é‚©‚ð’²‚×‚é
	int ally_cnt = 0;

	for (auto square : target_square_pos) {

		if (board->getBoardSquare(square.row, square.col)->GetAllyPtrInSquare()) {
			ally_cnt++;
		}

	}

	//•ª‚¯‚é
	int share_shield_value = 0;
	int remainder = 0;
	for (auto ally : board->GetPartyUnitsInBoard()) {

		if (ally->GetIsTurn()) {
		
			share_shield_value = ally->GetShieldValue() / ally_cnt;
			remainder = ally->GetShieldValue() % ally_cnt;

			ally->SetShieldValue(share_shield_value + remainder);

		}
	}

	for (auto square : target_square_pos) {

		if (board->getBoardSquare(square.row, square.col)->GetAllyPtrInSquare()) {

			board->getBoardSquare(square.row, square.col)->GetAllyPtrInSquare()->AddShieldValue(share_shield_value);

		}

	}

}
