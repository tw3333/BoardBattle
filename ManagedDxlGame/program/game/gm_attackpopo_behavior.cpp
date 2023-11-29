#include "gm_attackpopo_behavior.h"

#include "gm_unit_ally.h"
#include "gm_unit_enemy.h"
#include "gm_board.h"

#include <vector>
#include <cstdlib> // std::rand, std::srand
#include <ctime> // std::time
#include <climits> // INT_MAX
#include <cmath> // std::abs
#include <algorithm> // std::shuffle
#include <queue>


void AttackPopoBehavior::Move(UnitEnemy* turn_enemy, Board* board) {

	//1.Range����Ally�������ꍇ�͈ړ����Ȃ�
	if (IsAllyActInRange(turn_enemy, board)) {
		return;
	}

	//2.Ally���אڂ��Ă����ꍇ��}�X��������
	if (IsAllyAdjacent(turn_enemy, board)) {

		SquarePos enemy_pos = turn_enemy->GetUnitSquarePos();
		SquarePos directions[] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };  // ��A���A���A�E

		int max_distance = INT_MIN;
		SquarePos best_direction = enemy_pos;

		for (auto dir : directions) {
			SquarePos new_pos = { enemy_pos.row + dir.row, enemy_pos.col + dir.col };
			int min_distance_for_this_dir = INT_MAX;

			for (auto ally : board->GetPartyUnitsInBoard()) {
				SquarePos ally_pos = ally->GetUnitSquarePos();
				int distance = CalDistance(new_pos, ally_pos);
				min_distance_for_this_dir = (std::min)(min_distance_for_this_dir, distance);
			}

			if (min_distance_for_this_dir > max_distance) {
				max_distance = min_distance_for_this_dir;
				best_direction = new_pos;
			}
		}

		//�ړ��\�Ȃ�ړ�
		if (board->getBoardSquare(best_direction.row, best_direction.col)->GetIsCanMove()) {
			sound_mgr_.PlayAllyMoveSE();
			//���W���X�V
			turn_enemy->SetUnitSquarePos(best_direction.row, best_direction.col);
		}

		return;
	}

	//3.Range����Ally�����Ȃ��ꍇ�͈�ԋ߂�Ally�ɋ߂Â�
	if (!IsAllyActInRange(turn_enemy, board)) {

		// �S�Ă�Ally��1�}�X��̈ړ��\�ȃ}�X���W�߂�
		std::vector<SquarePos> all_adjacent_squares = GetAllAlliesOneStepAwaySquares(board);

		//�A�^�b�N�|�|�̌��݈ʒu����ŒZ�����ɂ���אڃ}�X��T��
		SquarePos current_pos = turn_enemy->GetUnitSquarePos();
		std::pair<SquarePos, std::vector<SquarePos>> move_data = GetBestMoveAlongPath(current_pos, all_adjacent_squares, board, turn_enemy->GetCurrentMoveCost());

		//�A�^�b�N�|�|�����̈ʒu�Ɉړ�
		if (!move_data.second.empty()) {
			SquarePos new_pos = move_data.second.front(); // ���ꂪ�V�����ʒu
			sound_mgr_.PlayAllyMoveSE();
			turn_enemy->SetUnitSquarePos(new_pos.row, new_pos.col);
		}
	}

}

void AttackPopoBehavior::Act(UnitEnemy* turn_enemy, Board* board) {

	//turn_enemy�̈ʒu���擾
	SquarePos turn_enemy_pos = turn_enemy->GetUnitSquarePos();

	//Range���̃}�X�ڂ��擾
	std::vector<SquarePos> around_pos;
	if (turn_enemy_pos.row > 0) {
		around_pos.push_back(SquarePos(turn_enemy_pos.row - 2, turn_enemy_pos.col));
	}
	if (turn_enemy_pos.row < 9) {
		around_pos.push_back(SquarePos(turn_enemy_pos.row + 2, turn_enemy_pos.col));
	}
	if (turn_enemy_pos.col > 0) {
		around_pos.push_back(SquarePos(turn_enemy_pos.row, turn_enemy_pos.col - 2));
	}
	if (turn_enemy_pos.col < 9) {
		around_pos.push_back(SquarePos(turn_enemy_pos.row, turn_enemy_pos.col + 2));
	}

	//�ׂ荇���Ă���}�X��UnitAlly��������around_ally�ɒǉ�
	std::vector<UnitAlly*> in_range_ally; //�i�[�z��

	for (auto& pos : around_pos) {

		if (board->getBoardSquare(pos.row, pos.col)->GetAllyPtrInSquare()) {
			in_range_ally.push_back(board->getBoardSquare(pos.row, pos.col)->GetAllyPtrInSquare());
		}
	}

	//�U������
	UnitAlly* target_ally = nullptr; //�U���Ώ�

	//���Ȃ�������I��
	if (in_range_ally.empty()) { return; }
	else if (!in_range_ally.empty()) {    //����ꍇ

		// taunt_ �l�Ń\�[�g
		std::sort(in_range_ally.begin(), in_range_ally.end(), [](UnitAlly* a, UnitAlly* b) {
			return a->GetTauntValue() < b->GetTauntValue();
			});

		// �ł����� taunt_ �l�����v�f�����ׂĎ��W
		int highest_taunt = in_range_ally.back()->GetTauntValue();
		std::vector<UnitAlly*> highest_taunt_allies;
		std::copy_if(in_range_ally.begin(), in_range_ally.end(), std::back_inserter(highest_taunt_allies), [highest_taunt](UnitAlly* unit) {
			return unit->GetTauntValue() == highest_taunt;
			});

		// �����_����1�I��
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> distr(0, highest_taunt_allies.size() - 1);

		target_ally = highest_taunt_allies[distr(gen)];
	}

	//damage��^����
	if (target_ally) {
		target_ally->DecreaseCurrentHp(turn_enemy->GetCurrentPower());

		anim_mgr_.GetAnim()[0]->SetObjPosToSquarePos(target_ally->GetUnitSquarePos().row, target_ally->GetUnitSquarePos().col);
		anim_mgr_.GetAnim()[0]->CardAnimPlay("anim_flame");

		sound_mgr_.PlayCardSE(11);
		sound_mgr_.PlayAllyDamagedVoice(target_ally->GetAllyData()->GetAllyDataID());

	}

}

bool AttackPopoBehavior::IsAllyActInRange(UnitEnemy* turn_enemy, Board* board) {

	SquarePos directions[] = { {-2, 0}, {2, 0}, {0, -2}, {0, 2} };
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


bool AttackPopoBehavior::IsAllyAdjacent(UnitEnemy* turn_enemy, Board* board) {

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

std::pair<SquarePos, std::vector<SquarePos>> AttackPopoBehavior::GetBestMoveAlongPath(SquarePos start_pos, const std::vector<SquarePos>& targetPositions, Board* board, int move_cost) {

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

std::vector<SquarePos> AttackPopoBehavior::GetOneStepAwaySquares(SquarePos pos, Board* board) {

	std::vector<SquarePos> ret_one_step_away_squares;
	SquarePos directions[] = { {-2, 0}, {2, 0}, {0, -2}, {0, 2} }; // 1�}�X��̈ʒu

	for (SquarePos dir : directions) {
		SquarePos one_step_away_pos = { pos.row + dir.row, pos.col + dir.col };

		if (one_step_away_pos.row >= 0 && one_step_away_pos.row < 10 && one_step_away_pos.col >= 0 && one_step_away_pos.col < 10
			&& board->getBoardSquares()[one_step_away_pos.row][one_step_away_pos.col]->GetIsCanMove()) {
			ret_one_step_away_squares.push_back(one_step_away_pos);
		}
	}

	return ret_one_step_away_squares;

}



std::vector<SquarePos> AttackPopoBehavior::GetAllAlliesOneStepAwaySquares(Board* board) {

	std::vector<SquarePos> ret_all_one_step_away_squares;

	for (int row = 0; row < 10; ++row) {
		for (int col = 0; col < 10; ++col) {
			if (board->getBoardSquares()[row][col]->GetAllyPtrInSquare()) {
				std::vector<SquarePos> one_step_away_squares = GetOneStepAwaySquares(SquarePos{ row, col }, board);
				ret_all_one_step_away_squares.insert(ret_all_one_step_away_squares.end(), one_step_away_squares.begin(), one_step_away_squares.end());
			}
		}
	}

	return ret_all_one_step_away_squares;

}
