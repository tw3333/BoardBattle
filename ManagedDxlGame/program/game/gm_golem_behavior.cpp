#include "gm_golem_behavior.h"

#include "gm_unit_enemy.h"
#include "gm_unit_ally.h"
#include "gm_board.h"

#include <vector>
#include <cstdlib> // std::rand, std::srand
#include <ctime> // std::time
#include <climits> // INT_MAX
#include <cmath> // std::abs
#include <algorithm> // std::shuffle
#include <queue>



//memo
//�ړ��̓X���C���̃��W�b�N�Ɠ���
void GolemBehavior::Move(UnitEnemy* turn_enemy, Board* board) {

	//1.Ally���אڂ��Ă�����ړ����Ȃ�
	if (IsAllyAdjacent(turn_enemy, board)) {
		return;
	} //2.�����łȂ����
	else {

		// �S�Ă�Ally�̗אڂ���ړ��\�ȃ}�X���W�߂�
		std::vector<SquarePos> allAdjacentSquares = GetAllAlliesAdjacentSquares(board);

		//�S�[���������݈ʒu����ŒZ�����ɂ���אڃ}�X��T��
		SquarePos current_pos = turn_enemy->GetUnitSquarePos();
		std::pair<SquarePos, std::vector<SquarePos>> moveData = GetBestMoveAlongPath(current_pos, allAdjacentSquares, board, turn_enemy->GetCurrentMoveCost());

		//�S�[���������̈ʒu�Ɉړ�
		if (!moveData.second.empty()) {
			SquarePos new_pos = moveData.second.front(); // ���ꂪ�V�����ʒu
			sound_mgr_.PlayAllyMoveSE();
			turn_enemy->SetUnitSquarePos(new_pos.row, new_pos.col);
		}


	}


}

void GolemBehavior::Act(UnitEnemy* turn_enemy, Board* board) {

	//1.�O�̃^�[���s�����Ă�����
	if (is_pre_turn_acted_) {
		
		//turn_enemy�̈ʒu���擾
		SquarePos turn_enemy_pos = turn_enemy->GetUnitSquarePos();

		anim_mgr_.GetAnim()[0]->SetObjPosToSquarePos(turn_enemy_pos.row, turn_enemy_pos.col);
		anim_mgr_.GetAnim()[0]->CardAnimPlay("anim_debuff");
		sound_mgr_.PlayBattleStateSE(State::Snare);


		is_pre_turn_acted_ = false;
		return;
	}
	else {

		//turn_enemy�̈ʒu���擾
		SquarePos turn_enemy_pos = turn_enemy->GetUnitSquarePos();

		//�㉺���E�ׂ荇���Ă���}�X���擾
		std::vector<SquarePos> around_pos = GetActRangePos(turn_enemy);


		//�ׂ荇���Ă���}�X��UnitAlly��������around_ally�ɒǉ�
		std::vector<UnitAlly*> around_ally;
		for (auto pos : around_pos) {
			if (board->getBoardSquare(pos.row, pos.col)->GetAllyPtrInSquare()) {
				around_ally.push_back(board->getBoardSquare(pos.row, pos.col)->GetAllyPtrInSquare());
			}
		}

		UnitAlly* target_ally = nullptr;

		//���Ȃ�������I��
		if (around_ally.empty()) { return; }
		//����ꍇ
		else if (!around_ally.empty()) {

			target_ally = ExtractMostTauntAlly(around_ally);
		}

		//
		board->getBoardSquare(target_ally->GetUnitSquarePos().row, target_ally->GetUnitSquarePos().col)->SetRenderTargetTile(true);
		board->getBoardSquare(target_ally->GetUnitSquarePos().row, target_ally->GetUnitSquarePos().col)->SetRenderCandidateTile(true);


		//damage��^����
		if (target_ally) {
			target_ally->DecreaseCurrentHp(turn_enemy->GetCurrentPower());

			anim_mgr_.GetAnim()[0]->SetObjPosToSquarePos(target_ally->GetUnitSquarePos().row, target_ally->GetUnitSquarePos().col);
			anim_mgr_.GetAnim()[0]->CardAnimPlay("anim_attack");

			sound_mgr_.PlayEnemyActSE(1);
			sound_mgr_.PlayAllyDamagedVoice(target_ally->GetAllyData()->GetAllyDataID());


			board->getBoardSquare(target_ally->GetUnitSquarePos().row, target_ally->GetUnitSquarePos().col)->SetRenderTargetTile(false);
			board->getBoardSquare(target_ally->GetUnitSquarePos().row, target_ally->GetUnitSquarePos().col)->SetRenderCandidateTile(false);
		}

		is_pre_turn_acted_ = true;
	}

}

bool GolemBehavior::IsAllyAdjacent(UnitEnemy* turn_enemy, Board* board) {
	
	SquarePos directions[] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
	SquarePos enemy_pos = turn_enemy->GetUnitSquarePos();

	for (auto dir : directions) {
		SquarePos check_pos = { enemy_pos.row + dir.row, enemy_pos.col + dir.col };

		if (check_pos.row >= 0 && check_pos.row < 10 && check_pos.col >= 0 && check_pos.col < 10) {

			for (auto ally : board->GetPartyUnitsInBoard()) {
				if (ally->GetUnitSquarePos().row == check_pos.row && ally->GetUnitSquarePos().col == check_pos.col) {
					return true;
				}
			}

		}
	}

	return false;
}

std::vector<SquarePos> GolemBehavior::GetActRangePos(UnitEnemy* turn_enemy) {
	
	std::vector<SquarePos> ret_act_range_pos;

	SquarePos turn_enemy_pos = turn_enemy->GetUnitSquarePos();

	// �㉺���E�̃I�t�Z�b�g
	std::vector<SquarePos> offsets = {
		{-1, 0}, // ��
		{1, 0},  // ��
		{0, -1}, // ��
		{0, 1}   // �E
	};

	for (const auto& offset : offsets) {
		int newRow = turn_enemy_pos.row + offset.row;
		int newCol = turn_enemy_pos.col + offset.col;

		if (newRow >= 0 && newRow < 10 && newCol >= 0 && newCol < 10) {
			ret_act_range_pos.push_back(SquarePos(newRow, newCol));
		}

	}

	return ret_act_range_pos;
}

std::pair<SquarePos, std::vector<SquarePos>> GolemBehavior::GetBestMoveAlongPath(SquarePos start_pos, const std::vector<SquarePos>& targetPositions, Board* board, int move_cost) {

	std::queue<SquarePos> q;
	std::map<SquarePos, SquarePos> prev;
	std::vector<SquarePos> path;
	std::vector<std::vector<bool>> visited(10, std::vector<bool>(10, false));
	SquarePos directions[] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} }; // ��A���A���A�E

	q.push(start_pos);
	visited[start_pos.row][start_pos.col] = true;
	prev[start_pos] = { -1, -1 };

	while (!q.empty()) {
		SquarePos current = q.front();
		q.pop();

		if (std::find(targetPositions.begin(), targetPositions.end(), current) != targetPositions.end()) {
			for (SquarePos at = current; at != SquarePos{-1, -1}; at = prev[at]) {
				path.push_back(at);
			}
			std::reverse(path.begin(), path.end());
			break;
		}

		for (SquarePos dir : directions) {
			SquarePos next = { current.row + dir.row, current.col + dir.col };
			if (next.row >= 0 && next.row < 10 && next.col >= 0 && next.col < 10 && !visited[next.row][next.col] && board->getBoardSquares()[next.row][next.col]->GetIsCanMove()) {
				q.push(next);
				visited[next.row][next.col] = true;
				prev[next] = current;
			}
		}
	}

	// �ŒZ�o�H��move_cost�������i��
	std::vector<SquarePos> movePath;
	int path_length = path.size();
	if (path_length > 1 && move_cost > 0) { // path_length > 1 �̓X�^�[�g�ʒu���܂ނ���
		int moves = (std::min)(path_length - 1, move_cost); // �X�^�[�g�ʒu�͏��O���ăJ�E���g
		movePath.assign(path.begin() + 1, path.begin() + 1 + moves); // +1 �̓X�^�[�g�ʒu���X�L�b�v
	}

	SquarePos final_pos = movePath.empty() ? start_pos : movePath.back();
	return { final_pos, movePath };
}
