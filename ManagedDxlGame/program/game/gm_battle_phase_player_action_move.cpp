#include "gm_battle_phase_player_action_move.h"

#include <queue>

void PhasePlayerActionMove::BeginPhase()
{
}

void PhasePlayerActionMove::EndPhase()
{
}

bool PhasePlayerActionMove::UpdateExecute(float delta_time) {

	select_square_row_ = select_square_->GetSelectSquareRow();
	select_square_col_ = select_square_->GetSelectSquareCol();

    flame_->Update(delta_time);


	DrawStringEx(500,30,-1,"PhasePlayerActionMove");

	MoveRange(turn_ally_);


	return true;
}

bool PhasePlayerActionMove::RenderExecute(dxe::Camera* camera){
	
   	flame_->Render(camera);
	
	return true;
}

void PhasePlayerActionMove::MoveRange(UnitAlly* unit) {
    
    // �ړ���̃}�X���擾
    int target_row = select_square_->GetSelectSquareRow();
    int target_col = select_square_->GetSelectSquareCol();

    // �ړ����̃}�X���擾
    int ally_row = unit->GetBoardPos().row;
    int ally_col = unit->GetBoardPos().col;

    board_squares_[ally_row][ally_col]->getObj()->parts_[ObjSquare::RangeTile]->is_render_ = false;

    // �ړ��\�Ȕ͈͂��擾
    std::array<std::array<int, 10>, 10> reachable = GetReachableSquares(unit);

    // �ړ��悪�ړ��\�Ȕ͈͓��ł��邩�`�F�b�N
    if (reachable[target_row][target_col] == -1) {
        return;  // �ړ��ł��Ȃ��̂ŏI��
    }


    if (tnl::Input::IsMouseTrigger(eMouseTrigger::IN_LEFT)) {
       
        // �ړ��R�X�g���`�F�b�N
        int move_cost = unit->GetCurrentMoveCost();

        // �ړ��R�X�g�����ɂȂ�Ȃ����`�F�b�N
        if (move_cost < 0) {
            return; // �ړ��R�X�g������Ȃ��̂ŏI��
        }
        
        // �ړ���Ƀ��j�b�g���ړ�
        unit->SetBoardPos(target_row, target_col);

  
        move_cost -= reachable[target_row][target_col];  // �ړ��R�X�g�����炷
        unit->SetCurrentMoveCost(move_cost);  // �ړ��R�X�g���X�V

    }





    // �ړ��\�͈͂��Čv�Z
    reachable = GetReachableSquares(unit);

    // �ړ��\�͈͂̕`����X�V
    UpdateRender(reachable,unit);

}

void PhasePlayerActionMove::CrearMoveRange() {

	for (auto& row : board_squares_) {
		for (auto& square : row) {
			square->getObj()->parts_[ObjSquare::RangeTile]->is_render_ = false;
		}
	}

    flame_->parts_[ObjMoveSelectFlame::MoveSelectFlame]->is_render_ = false;
}

void PhasePlayerActionMove::ExploreMoveRange(UnitAlly* unit, int cur_row, int cur_col, int remaining_cost)
{
    if (remaining_cost < 0) return;  // �R�X�g���Ȃ���ΏI��

 // �ړ��\�͈͂�`�悵�܂��B
    board_squares_[cur_row][cur_col]->getObj()->parts_[ObjSquare::RangeTile]->is_render_ = true;

    // ��`�F��, ��, ��, �E
    std::vector<std::pair<int, int>> directions{ {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

    // �㉺���E��T�����܂��B
    for (const auto& dir : directions) {
        int new_row = cur_row + dir.first;
        int new_col = cur_col + dir.second;

        // �V�����ʒu���{�[�h���ɑ��݂��A�ړ��\�ł���΁A�ċA�I�ɒT�����s���܂��B
        if (new_row >= 0 && new_row < 10 && new_col >= 0 && new_col < 10 &&
            board_squares_[new_row][new_col]->GetIsCanMove()) {
            ExploreMoveRange(unit, new_row, new_col, remaining_cost - 1);
        }
    }

}

std::array<std::array<int, 10>, 10> PhasePlayerActionMove::GetReachableSquares(UnitAlly* unit) {

    // �ړ����̈ʒu���擾
    int ally_row = unit->GetBoardPos().row;
    int ally_col = unit->GetBoardPos().col;

    // �ړ��R�X�g���擾
    int move_cost = unit->GetCurrentMoveCost();


    // ���B�\�͈͂�ۑ�����񎟌��z��
    std::array<std::array<int, 10>, 10> reachable;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            reachable[i][j] = -1; // ������
        }
    }

    if (move_cost <= 0) {
        return reachable;
    }

    // BFS�ŒT��
    std::queue<std::pair<int, int>> que;
    que.push({ ally_row, ally_col }); // �X�^�[�g�ʒu��queue�ɒǉ�
    reachable[ally_row][ally_col] = 0; // �X�^�[�g�ʒu�̃R�X�g��0

    while (!que.empty()) {
        auto current = que.front(); // ���ݒn�_
        que.pop();

        for (int i = 0; i < 4; ++i) { // 4�����ɑ΂��ĒT��
            int nx = current.first + dx_[i];
            int ny = current.second + dy_[i];

            // �ړ��\�͈̓`�F�b�N
            if (nx < 0 || ny < 0 || nx >= 10 || ny >= 10) {
                continue;
            }

            // �ړ��\�͈͂����K�₩�ړ��R�X�g�ȓ��Ȃ�T��
            if (reachable[nx][ny] == -1 && reachable[current.first][current.second] + 1 <= move_cost
                && board_squares_[nx][ny]->GetIsCanMove()) {
                reachable[nx][ny] = reachable[current.first][current.second] + 1;
                que.push({ nx, ny });
            }
        }
    }

    return reachable;
}

void PhasePlayerActionMove::UpdateRender(std::array<std::array<int, 10>, 10> reachable,UnitAlly* unit)
{

 
    // �ړ��\�͈͂̕`����X�V
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if ((i != unit->GetBoardPos().row || j != unit->GetBoardPos().col) && reachable[i][j] != -1) {
                board_squares_[i][j]->getObj()->parts_[ObjSquare::RangeTile]->is_render_ = true;
            }
            else {
               
                board_squares_[i][j]->getObj()->parts_[ObjSquare::RangeTile]->is_render_ = false;
            }
        }
    }




}






