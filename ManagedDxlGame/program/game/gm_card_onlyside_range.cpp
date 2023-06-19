#include "gm_card_onlyside_range.h"

#include "gm_unit_ally.h"
#include "gm_unit_enemy.h"
#include "gm_board.h"
#include "gm_card.h"


void OnlySideRange::Range(Card* card, UnitAlly* act_ally, Board* board)
{

	int ally_row = act_ally->GetBoardPos().row;
	int ally_col = act_ally->GetBoardPos().col;


	if (side_ == Side::Left) {

		for (int i = 0; i < range_size_; ++i) {
			
			if (ally_row - i < 0) { break; }

			for (auto pu : board->GetPartyUnits()) {

			

				if (pu->GetBoardPos().row == ally_row - i) {
					card->AddRangeAllyUnits(pu);
				}

			}

			for (auto eu : board->GetEnemyUnits()) {

				if (eu->GetBoardPos().row == ally_row -1) {
					card->AddRangeEnemyUnits(eu);
				}

			}
		}


	}
	else if (side_ == Side::Right) {

		for (int i = 0; i < range_size_; ++i) {

			if (ally_row + i > 9) { break; }

			for (auto pu : board->GetPartyUnits()) {
				if (pu->GetBoardPos().row == ally_row + i) {
					card->AddRangeAllyUnits(pu);
				}
			}

			for (auto eu : board->GetEnemyUnits()) {
				if (eu->GetBoardPos().row == ally_row + i) {
					card->AddRangeEnemyUnits(eu);
				}
			}
		}

	}
	else if (side_ == Side::Up) {

		for (int i = 0; i < range_size_; ++i) {

			if (ally_col - i < 0) { break; }

			for (auto pu : board->GetPartyUnits()) {
				if (pu->GetBoardPos().col == ally_col - i) {
					card->AddRangeAllyUnits(pu);
				}
			}

			for (auto eu : board->GetEnemyUnits()) {
				if (eu->GetBoardPos().col == ally_col - i) {
					card->AddRangeEnemyUnits(eu);
				}
			}
		}

	}
	else if (side_ == Side::Down) {

		for (int i = 0; i < range_size_; ++i) {

			if (ally_col + i > 9) { break; }

			for (auto pu : board->GetPartyUnits()) {
				if (pu->GetBoardPos().col == ally_col + i) {
					card->AddRangeAllyUnits(pu);
				}
			}

			for (auto eu : board->GetEnemyUnits()) {
				if (eu->GetBoardPos().col == ally_col + i) {
					card->AddRangeEnemyUnits(eu);
				}
			}
		}

	}




}
