#include "gm_board.h"
#include "gm_unit.h"
#include "gm_unit_ally.h"
#include "gm_unit_enemy.h"
#include "gm_select_square.h"


void Board::Create() {

	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
				
			board_squares_[i][j] = new Square(i,j,omgr_.GetSquaresAtIndex(i,j));
			
		}
	}

}

void Board::Update(float delta_time) {

	//Squareの状態を更新
	UpdateSquareState();

	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {

			board_squares_[i][j]->getObj()->Update(delta_time);

		}

	}

	

}


void Board::Render(dxe::Camera* camera) {
	
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {

			board_squares_[i][j]->getObj()->Render(camera);

		}
	}

	//Boardのグリット線
	for (int i = 0; i <= 10; ++i) {

		float mas_x = (w1 * 8) / 10;
		float mas_z = (h1 * 8) / 10;

		DrawLine3D({ 0,0,0 + (mas_z * i) }, { float(w1 * 8),0,0 + (mas_z * i) }, gray_);
		DrawLine3D({ 0 + (mas_x * i),0,0 }, { 0 + (mas_x * i),0,(float)(h1 * 8) }, gray_);
	}

}

void Board::UpdateCanMoveSquare() {

	//Unitのいる位置を移動禁止にする
	for (auto au: all_units_) {

		board_squares_[au->GetBoardPos().row][au->GetBoardPos().col]->SetIsCanMove(false);

	}

	
}

void Board::UpdateSquareState() {

	//全てリセット
	for (int row = 0; row < 10; ++row) {
		for (int col = 0; col < 10; ++col) {

			board_squares_[row][col]->SetAllyInSquare(false);
			board_squares_[row][col]->SetEnemyInSquare(false);
			board_squares_[row][col]->SetIsCanMove(true);

		}
	}

	//Unitのいる位置を移動禁止にする
	for (auto au : all_units_) {
		board_squares_[au->GetBoardPos().row][au->GetBoardPos().col]->SetIsCanMove(false);
	}
	//AllyとEnemyのいるSquareのフラグを更新
	for (auto pu : party_units_) {
		board_squares_[pu->GetBoardPos().row][pu->GetBoardPos().col]->SetAllyInSquare(true);
	}
	for (auto eu : enemy_units_) {
		board_squares_[eu->GetBoardPos().row][eu->GetBoardPos().col]->SetEnemyInSquare(true);
	}

}

bool Board::IsAdjacentAlly(UnitEnemy* unit_enemy, UnitAlly* unit_ally)
{
	int row_diff = std::abs(unit_enemy->GetBoardPos().row - unit_ally->GetBoardPos().row);
	int col_diff = std::abs(unit_enemy->GetBoardPos().col - unit_ally->GetBoardPos().col);

	return (row_diff <= 1 && col_diff <= 1); return false;
}

bool Board::IsAllyNearby(UnitEnemy* unit_enemy, std::vector<UnitAlly*> party)
{
	int enemy_row = unit_enemy->GetBoardPos().row;
	int enemy_col = unit_enemy->GetBoardPos().col;

	for (auto ally : party) {

		if (std::abs(enemy_row - ally->GetBoardPos().row) <= 1 && std::abs(enemy_col - ally->GetBoardPos().col) <= 1) {
			return true;
		}

	}

	return false;
}
