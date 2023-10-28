#pragma once
#include <array>
#include <vector>
#include <memory>
#include "gm_square.h"
#include "../dxlib_ext/dxlib_ext.h"
#include "gm_object_manager.h"
#include "gm_data_board.h"


class Unit;
class UnitAlly;
class UnitEnemy;
class UnitObstacle;
class SelectSquare;

//memo
//SceneBattle�̔Ֆʏ���Ǘ�����N���X
//1�}�X(Square�N���X)�������Ő���

//ToDo
//�����ŃX�e�[�W���̃}�X�ڂ�G�̐������Ǘ��H

class Board {
public:

	Board(){
		Create();
		

	}
	~Board() { delete camera_; }

	void Create();
	void Update(float delta_time);
	void Render(dxe::Camera* camera);

	std::array<std::array<Square*, 10>, 10>& getBoardSquares() { return board_squares_;}
	Square* getBoardSquare(int row, int col) { return board_squares_[row][col]; }
	void SetCamera(dxe::Camera* camera) { camera_ = camera; }

	void DisplayRangePosRangeTile(std::vector<SquarePos> range_square_pos);
	
	void AddUnitInBoard(Unit* unit); //Board���Unit��ǉ�

	void ResetDisplayRangeTile();
	void ResetDisPlayCandidateTile();
	void ResetDisPlayTargetTile();
	void ResetAllTile();

	void UpdateCanMoveSquare();
	void UpdateSquareState();
	void UpdateUnitPtrInSquare(); //Square�Ɋi�[����Unit�̍X�V
	void UpdateUnitsInBoard(); //Board��̊eUnit�̍X�V

	void SetParty(UnitAlly* party[3]) { std::copy(party, party + 3, party_); }

	void SetPartyUnits(std::vector<UnitAlly*> party_units) { party_units_ = party_units; }

	std::vector<UnitAlly*> GetPartyUnits() { return party_units_; }
	void SetEnemyUnits(std::vector<UnitEnemy*> enemy_units) { enemy_units_ = enemy_units; }
	std::vector<UnitEnemy*> GetEnemyUnits() { return enemy_units_; }
	void SetAllUnits(std::vector<Unit*> all_units) { all_units_ = all_units; }
	std::vector<Unit*> GetAllUnits() { return all_units_; }


	bool IsAdjacentAlly(UnitEnemy* unit_enemy, UnitAlly* unit_ally);
	bool IsAllyNearby(UnitEnemy* unit_enemy, std::vector<UnitAlly*> party);
	bool IsValidPosition(int row, int col) {
		return 0 <= row && row < 10 && 0 <= col && col < 10;
	}

	void ResetRangeTile();

	void SetPartyUnitsInBoard(std::vector<UnitAlly*> party_units) { party_units_in_board_ = party_units; }
	void SetEnemyUnitsInBoard(std::vector<UnitEnemy*> enemy_units) { enemy_units_in_board_ = enemy_units; }
	void SetAllUnitsInBoard(std::vector<Unit*> units) { all_units_in_board_ = units; }
	std::vector<UnitAlly*>& GetPartyUnitsInBoard() { return party_units_in_board_; }
	std::vector<UnitEnemy*>& GetEnemyUnitsInBoard() { return enemy_units_in_board_; }
	std::vector<Unit*> GetAllUnitsInBoard() { return all_units_in_board_; }


private:

	UnitAlly* party_[3];
	
	//
	std::vector<UnitAlly*> party_units_;
	std::vector<UnitEnemy*> enemy_units_;
	std::vector<Unit*> all_units_;



	//Board��̊eUnit
	std::vector<UnitAlly*> party_units_in_board_; //Board��ɂ���UnitAlly(Party)
	std::vector<UnitEnemy*> enemy_units_in_board_; //Board��ɂ���UnitEnemy
	
	std::vector<Unit*> all_units_in_board_; //Board��ɂ���S�Ă�Unit


	ObjectManager& omgr_ = ObjectManager::GetInstance();

	std::array<std::array<Square*, 10>, 10> board_squares_;//10x10�̃}�X�z��

	SelectSquare* select_square_ = nullptr;

	dxe::Camera* camera_; //select_square�̃��C�v�Z�p

	int w1 = DXE_WINDOW_WIDTH / 10;
	int h1 = DXE_WINDOW_HEIGHT / 10;

	//ColorCode
	int gray_ = GetColor(128, 128, 128);

};