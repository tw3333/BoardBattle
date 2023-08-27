#include "gm_card_renge_self.h"

#include "gm_board.h"
#include "gm_unit.h"
#include "gm_unit_ally.h"


void CardRangeSelf::DisplayRange(UnitAlly* act_ally, Board* board)
{
	//actallyのいる位置を射程に
	board->getBoardSquares()[act_ally->GetUnitSquarePos().row][act_ally->GetUnitSquarePos().col]->SetRenderRangeTile(true);
	board->getBoardSquares()[act_ally->GetUnitSquarePos().row][act_ally->GetUnitSquarePos().col]->SetRenderCandidateTile(true);
	board->getBoardSquares()[act_ally->GetUnitSquarePos().row][act_ally->GetUnitSquarePos().col]->SetRenderTargetTile(true);



}

std::vector<Unit*> CardRangeSelf::GetUnitInRange(UnitAlly* act_ally, std::vector<Unit*> all_units)
{
	std::vector<Unit*> units_in_range;
	
	is_unit_in_range_ = true;
	
	
	units_in_range.push_back(act_ally);
	return units_in_range;

}

std::vector<SquarePos> CardRangeSelf::GetRangeSquarePos(SquarePos axis_pos)
{
	std::vector<SquarePos> range_square_pos;
	
	range_square_pos.push_back(axis_pos);

	return range_square_pos;
}
