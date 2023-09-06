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

	//Square�̏�Ԃ��X�V
	UpdateSquareState();
	UpdateUnitPtrInSquare();
	UpdateUnitsInBoard();

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

	//Board�̃O���b�g��
	for (int i = 0; i <= 10; ++i) {

		float mas_x = (w1 * 8) / 10;
		float mas_z = (h1 * 8) / 10;

		DrawLine3D({ 0,0,0 + (mas_z * i) }, { float(w1 * 8),0,0 + (mas_z * i) }, gray_);
		DrawLine3D({ 0 + (mas_x * i),0,0 }, { 0 + (mas_x * i),0,(float)(h1 * 8) }, gray_);
	}

	for (auto unit : party_units_in_board_) {
		unit->GetObj()->Render(camera);
	}

	for (auto unit : enemy_units_in_board_) {
		unit->GetObj()->Render(camera);
	}
}

//�n����Pos��RangeTile��\������
void Board::DisplayRangePosRangeTile(std::vector<SquarePos> range_square_pos) {

	for (auto pos : range_square_pos) {
		board_squares_[pos.row][pos.col]->SetRenderRangeTile(true);
	}

}

//board���RangeTile��S�Ĕ�\���ɂ���
void Board::ResetDisplayRangeTile() {

	for (int row = 0; row < 10; ++row) {
		for (int col = 0; col < 10; ++col) {

			board_squares_[row][col]->SetRenderRangeTile(false);

		}
	}


}

void Board::ResetDisPlayCandidateTile()
{
	for (int row = 0; row < 10; ++row) {
		for (int col = 0; col < 10; ++col) {

			board_squares_[row][col]->SetRenderCandidateTile(false);

		}
	}
}

void Board::ResetDisPlayTargetTile()
{
	for (int row = 0; row < 10; ++row) {
		for (int col = 0; col < 10; ++col) {

			board_squares_[row][col]->SetRenderTargetTile(false);

		}
	}


}

//�S�Ă�Tile�̕\�������Z�b�g����
void Board::ResetAllTile()
{
	ResetDisplayRangeTile();
	ResetDisPlayCandidateTile();
	ResetDisPlayTargetTile();
}

void Board::UpdateCanMoveSquare() {

	//Unit�̂���ʒu���ړ��֎~�ɂ���
	for (auto au: all_units_) {
		board_squares_[au->GetUnitSquarePos().row][au->GetUnitSquarePos().row]->SetIsCanMove(false);
	}

	
}

void Board::UpdateSquareState() {

	//�S�ă��Z�b�g
	for (int row = 0; row < 10; ++row) {
		for (int col = 0; col < 10; ++col) {

			board_squares_[row][col]->SetAllyInSquare(false);
			board_squares_[row][col]->SetEnemyInSquare(false);
			board_squares_[row][col]->SetIsCanMove(true);

		}
	}

	//Unit�̂���ʒu���ړ��֎~�ɂ���
	for (auto au : all_units_) {
		board_squares_[au->GetUnitSquarePos().row][au->GetUnitSquarePos().col]->SetIsCanMove(false);
	}
	//Ally��Enemy�̂���Square�̃t���O���X�V
	for (auto pu : party_units_) {
		board_squares_[pu->GetUnitSquarePos().row][pu->GetUnitSquarePos().col]->SetAllyInSquare(true);
	}
	for (auto eu : enemy_units_) {
		board_squares_[eu->GetUnitSquarePos().row][eu->GetUnitSquarePos().col]->SetEnemyInSquare(true);
	}

}

void Board::UpdateUnitPtrInSquare() {

	//Square�Ɋi�[���Ă���A�eUnit�̃|�C���^���X�V
	for (int row = 0; row < 10; ++row) {
		for (int col = 0; col < 10; ++col) {
			
			board_squares_[row][col]->SetUnitPtrInSquare(nullptr);
			board_squares_[row][col]->SetAllyPtrInSquare(nullptr);
			board_squares_[row][col]->SetEnemyPtrInSquare(nullptr);

		}
	}

	for (auto pu : party_units_) {
		board_squares_[pu->GetUnitSquarePos().row][pu->GetUnitSquarePos().col]->SetUnitPtrInSquare(pu);
		board_squares_[pu->GetUnitSquarePos().row][pu->GetUnitSquarePos().col]->SetAllyPtrInSquare(pu);


	}
	for (auto eu : enemy_units_) {
		board_squares_[eu->GetUnitSquarePos().row][eu->GetUnitSquarePos().col]->SetUnitPtrInSquare(eu);
		board_squares_[eu->GetUnitSquarePos().row][eu->GetUnitSquarePos().col]->SetEnemyPtrInSquare(eu);
	}



}

void Board::UpdateUnitsInBoard() {

	//���S����Unit��Board���珜�O
	for (auto& unit : party_units_in_board_) {
		if (unit->GetIsDead()) {
			party_units_in_board_.erase(std::remove(party_units_in_board_.begin(), party_units_in_board_.end(),unit),party_units_in_board_.end());
		}
	}

	for (auto& unit: enemy_units_in_board_) {
		if (unit->GetIsDead()) {
			enemy_units_in_board_.erase(std::remove(enemy_units_in_board_.begin(), enemy_units_in_board_.end(), unit), enemy_units_in_board_.end());
		}
	}

	for (auto& unit : all_units_in_board_) {
		if (unit->GetIsDead()) {
			all_units_in_board_.erase(std::remove(all_units_in_board_.begin(), all_units_in_board_.end(), unit), all_units_in_board_.end());

		}
	}



}

bool Board::IsAdjacentAlly(UnitEnemy* unit_enemy, UnitAlly* unit_ally)
{
	int row_diff = std::abs(unit_enemy->GetUnitSquarePos().row - unit_ally->GetUnitSquarePos().row);
	int col_diff = std::abs(unit_enemy->GetUnitSquarePos().col - unit_ally->GetUnitSquarePos().col);

	return (row_diff <= 1 && col_diff <= 1); return false;
}

bool Board::IsAllyNearby(UnitEnemy* unit_enemy, std::vector<UnitAlly*> party)
{
	int enemy_row = unit_enemy->GetUnitSquarePos().row;
	int enemy_col = unit_enemy->GetUnitSquarePos().col;

	for (auto ally : party) {

		if (std::abs(enemy_row - ally->GetUnitSquarePos().row) <= 1 && std::abs(enemy_col - ally->GetUnitSquarePos().col) <= 1) {
			return true;
		}

	}

	return false;
}



//�Ֆʏ��RangeTile��Render������
void Board::ResetRangeTile() {

	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {

			board_squares_[i][j]->SetRenderRangeTile(false);
			board_squares_[i][j]->SetRenderCandidateTile(false);
			board_squares_[i][j]->SetRenderTargetTile(false);



		}
	}

}
