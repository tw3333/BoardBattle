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
    
    // 移動先のマスを取得
    int target_row = select_square_->GetSelectSquareRow();
    int target_col = select_square_->GetSelectSquareCol();

    // 移動元のマスを取得
    int ally_row = unit->GetBoardPos().row;
    int ally_col = unit->GetBoardPos().col;

    board_squares_[ally_row][ally_col]->getObj()->parts_[ObjSquare::RangeTile]->is_render_ = false;

    // 移動可能な範囲を取得
    std::array<std::array<int, 10>, 10> reachable = GetReachableSquares(unit);

    // 移動先が移動可能な範囲内であるかチェック
    if (reachable[target_row][target_col] == -1) {
        return;  // 移動できないので終了
    }


    if (tnl::Input::IsMouseTrigger(eMouseTrigger::IN_LEFT)) {
       
        // 移動コストをチェック
        int move_cost = unit->GetCurrentMoveCost();

        // 移動コストが負にならないかチェック
        if (move_cost < 0) {
            return; // 移動コストが足りないので終了
        }
        
        // 移動先にユニットを移動
        unit->SetBoardPos(target_row, target_col);

  
        move_cost -= reachable[target_row][target_col];  // 移動コストを減らす
        unit->SetCurrentMoveCost(move_cost);  // 移動コストを更新

    }





    // 移動可能範囲を再計算
    reachable = GetReachableSquares(unit);

    // 移動可能範囲の描画を更新
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
    if (remaining_cost < 0) return;  // コストがなければ終了

 // 移動可能範囲を描画します。
    board_squares_[cur_row][cur_col]->getObj()->parts_[ObjSquare::RangeTile]->is_render_ = true;

    // 定義：上, 下, 左, 右
    std::vector<std::pair<int, int>> directions{ {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

    // 上下左右を探索します。
    for (const auto& dir : directions) {
        int new_row = cur_row + dir.first;
        int new_col = cur_col + dir.second;

        // 新しい位置がボード内に存在し、移動可能であれば、再帰的に探索を行います。
        if (new_row >= 0 && new_row < 10 && new_col >= 0 && new_col < 10 &&
            board_squares_[new_row][new_col]->GetIsCanMove()) {
            ExploreMoveRange(unit, new_row, new_col, remaining_cost - 1);
        }
    }

}

std::array<std::array<int, 10>, 10> PhasePlayerActionMove::GetReachableSquares(UnitAlly* unit) {

    // 移動元の位置を取得
    int ally_row = unit->GetBoardPos().row;
    int ally_col = unit->GetBoardPos().col;

    // 移動コストを取得
    int move_cost = unit->GetCurrentMoveCost();


    // 到達可能範囲を保存する二次元配列
    std::array<std::array<int, 10>, 10> reachable;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            reachable[i][j] = -1; // 初期化
        }
    }

    if (move_cost <= 0) {
        return reachable;
    }

    // BFSで探索
    std::queue<std::pair<int, int>> que;
    que.push({ ally_row, ally_col }); // スタート位置をqueueに追加
    reachable[ally_row][ally_col] = 0; // スタート位置のコストは0

    while (!que.empty()) {
        auto current = que.front(); // 現在地点
        que.pop();

        for (int i = 0; i < 4; ++i) { // 4方向に対して探索
            int nx = current.first + dx_[i];
            int ny = current.second + dy_[i];

            // 移動可能範囲チェック
            if (nx < 0 || ny < 0 || nx >= 10 || ny >= 10) {
                continue;
            }

            // 移動可能範囲かつ未訪問かつ移動コスト以内なら探索
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

 
    // 移動可能範囲の描画を更新
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






