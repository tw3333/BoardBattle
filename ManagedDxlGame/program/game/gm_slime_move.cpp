#include "gm_slime_move.h"

#include <vector>
#include <cstdlib> // std::rand, std::srand
#include <ctime> // std::time
#include <climits> // INT_MAX
#include <cmath> // std::abs
#include <algorithm> // std::shuffle
#include <queue>

#include "gm_unit.h"
#include "gm_unit_ally.h"
#include "gm_unit_enemy.h"
#include "gm_board.h"
#include "gm_data_board.h"


void SlimeMove::Move(UnitEnemy* turn_enemy, Board* board) {

	//�ׂ荇���Ă�����ړ����Ȃ�
    if (IsAllyAdjacent(turn_enemy,board)) {
        return;
    }

    //�ׂ荇���ĂȂ��ꍇ
    //target�Ȃ�ally���擾
    UnitAlly* target_ally = nullptr;
    std::vector<UnitAlly*> candidate_target_ally;
    int min_distance = INT_MAX;
    int max_taunt = INT_MIN;

    for (auto ally : board->GetPartyUnits()) {
        
        int distance = std::abs(turn_enemy->GetUnitSquarePos().row - ally->GetUnitSquarePos().row) + std::abs(turn_enemy->GetUnitSquarePos().col - ally->GetUnitSquarePos().col);

        if (ally->GetTauntValue() > max_taunt || (ally->GetTauntValue() == max_taunt && distance < min_distance)) {
            candidate_target_ally.clear();
            candidate_target_ally.push_back(ally);
            min_distance = distance;
            max_taunt = ally->GetTauntValue();
        }
        else if (ally->GetTauntValue() == max_taunt && distance == min_distance) {
            candidate_target_ally.push_back(ally);
        }
    }

    //taunt�l������Ally������ꍇ�A�����_����1�̑I��
    std::srand(std::time(nullptr));
    int randomIndex = std::rand() % candidate_target_ally.size();
    target_ally = candidate_target_ally[randomIndex];



    //Target�Ɉړ�(BTS�T���g�p)
    std::vector<std::vector<bool>> visited(10, std::vector<bool>(10, false));
    std::queue<std::pair<SquarePos, int>> q;
    SquarePos directions[] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} }; //�㉺���E�̕����x�N�g��

    int remaining_move = turn_enemy->GetCurrentMoveCost();
    SquarePos final_pos = turn_enemy->GetUnitSquarePos();
    SquarePos nearest_target_pos = final_pos;
    int nearest_distance = INT_MAX;

    q.push({ turn_enemy->GetUnitSquarePos(), remaining_move });

    while (!q.empty()) {
        SquarePos cur = q.front().first;
        remaining_move = q.front().second;
        q.pop();

        if (visited[cur.row][cur.col] || !board->getBoardSquares()[cur.row][cur.col]->GetIsCanMove()) {
            continue;
        }

        visited[cur.row][cur.col] = true;

        int distance_to_target = std::abs(cur.row - target_ally->GetUnitSquarePos().row)
            + std::abs(cur.col - target_ally->GetUnitSquarePos().col);

        if (distance_to_target == 1 && remaining_move >= 0) {
            nearest_target_pos = cur;
            nearest_distance = 0;
            break;
        }

        if (remaining_move == 0 && distance_to_target < nearest_distance) {
            nearest_distance = distance_to_target;
            nearest_target_pos = cur;
        }

        ////Ally�ɗׂ荇�����ꍇ�ړ��I��
        //if (std::abs(cur.row - target_ally->GetUnitSquarePos().row) + std::abs(cur.col - target_ally->GetUnitSquarePos().col) == 1) {
        //    //turn_enemy->SetUnitSquarePos(cur.row, cur.col);
        //    final_pos = cur;
        //    break;
        //}


        for (SquarePos dir : directions) {
            SquarePos next = { cur.row + dir.row, cur.col + dir.col };
            if (next.row >= 0 && next.row < 10 && next.col >= 0 && next.col < 10) {
                if (!visited[next.row][next.col] && remaining_move - 1 >= 0) {
                    q.push({ next, remaining_move - 1 });
                }
            }
        }

    }

    if (nearest_distance <= remaining_move) {
        final_pos = nearest_target_pos;
    }

    turn_enemy->SetUnitSquarePos(final_pos.row, final_pos.col);
    //turn_enemy->SetUnitSquarePos(1, 1);

}

bool SlimeMove::IsAllyAdjacent(UnitEnemy* turn_enemy, Board* board) {

    // �㉺���E�̕����x�N�g��
    std::vector<SquarePos> directions = {
        {0, 1},  // �E
        {0, -1}, // ��
        {1, 0},  // ��
        {-1, 0}  // ��
    };

    for (const auto& dir : directions) {
        SquarePos adjacentPos = { turn_enemy->GetUnitSquarePos().row + dir.row, turn_enemy->GetUnitSquarePos().col + dir.col};

        // Ally�����̈ʒu�ɂ��邩�m�F
        for (auto ally : board->GetPartyUnits()) {
            if (ally->GetUnitSquarePos().row == adjacentPos.row && ally->GetUnitSquarePos().col == adjacentPos.col) {


                return true;  // �㉺���E��Ally������
            }
        }
    }

    return false;
}
