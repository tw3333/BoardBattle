#include "gm_enemy_behavior.h"

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
#include <random>
#include <chrono>
#include <iostream>


UnitAlly* EnemyBehavior::GetNearestAlly(UnitEnemy* turn_enemy, Board* board) {

    //最も近いAllyを探す
    std::vector<UnitAlly*> nearest_allies;

    int min_distance = INT_MAX;
    for (auto ally : board->GetPartyUnitsInBoard()) {
        int distance = std::abs(turn_enemy->GetUnitSquarePos().row - ally->GetUnitSquarePos().row)
            + std::abs(turn_enemy->GetUnitSquarePos().col - ally->GetUnitSquarePos().col);

        if (distance < min_distance) {
            nearest_allies.clear();
            nearest_allies.push_back(ally);
            min_distance = distance;
        }
        else if (distance == min_distance) {
            nearest_allies.push_back(ally);
        }
    }

    //重複していた場合、ランダムに1つ選ぶ
    std::uniform_int_distribution<int> dist(0, nearest_allies.size() - 1);
    UnitAlly* target_ally = nearest_allies[dist(rng)];


	return target_ally;
}



//渡したUnitAllyの配列の中から最もTaunt値が高いUnitAllyを返す
//同値が複数ある場合はランダムに1つ選ぶ
UnitAlly* EnemyBehavior::ExtractMostTauntAlly(std::vector<UnitAlly*> allies) {
    
    if (allies.empty()) {
        return nullptr;
    }

    std::vector<UnitAlly*> max_taunt_ally;
    int max_taunt = allies[0]->GetTauntValue();
    max_taunt_ally.push_back(allies[0]);

    for (size_t i = 1; i < allies.size(); ++i) {
        int current_taunt = allies[i]->GetTauntValue();
        if (current_taunt > max_taunt) {
            max_taunt = current_taunt;
            max_taunt_ally.clear();
            max_taunt_ally.push_back(allies[i]);
        }
        else if (current_taunt == max_taunt) {
            max_taunt_ally.push_back(allies[i]);
        }
    }

    if (max_taunt_ally.size() == 1) {
        return max_taunt_ally[0];
    }
    else {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distr(0, max_taunt_ally.size() - 1);

        return max_taunt_ally[distr(gen)];
    }

}


//渡した座標を軸に上下左右の移動可能なSquarePosを返す
std::vector<SquarePos> EnemyBehavior::GetCanMoveAdjacentSquares(SquarePos target_square_pos, Board* board) {

    std::vector<SquarePos> ret_adjacent_squares;
    SquarePos directions[] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    
    for (SquarePos dir : directions) {
       
        SquarePos adjPos = { target_square_pos.row + dir.row, target_square_pos.col + dir.col };
        
        if (adjPos.row >= 0 && adjPos.row < 10 && adjPos.col >= 0 && adjPos.col < 10
            && board->getBoardSquares()[adjPos.row][adjPos.col]->GetIsCanMove()) {
            ret_adjacent_squares.push_back(adjPos);
        
        }
    }


    return ret_adjacent_squares;
}

std::vector<SquarePos> EnemyBehavior::GetAllAlliesAdjacentSquares(Board* board) {

    std::vector<SquarePos> ret_all_adjacent_squares;
    
    for (int row = 0; row < 10; ++row) {
        for (int col = 0; col < 10; ++col) {

            if (board->getBoardSquares()[row][col]->GetAllyPtrInSquare()) {

                std::vector<SquarePos> adjacent_squares = GetAdjacentSquares(SquarePos{ row, col }, board);
                
                ret_all_adjacent_squares.insert(ret_all_adjacent_squares.end(), adjacent_squares.begin(), adjacent_squares.end());
            }
        }
    }

    return ret_all_adjacent_squares;
}



std::vector<SquarePos> EnemyBehavior::GetAdjacentSquares(SquarePos pos, Board* board) {
    
    std::vector<SquarePos> ret_adjacent_squares;
    SquarePos directions[] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} }; // 上、下、左、右

    for (SquarePos dir : directions) {
        SquarePos adjPos = { pos.row + dir.row, pos.col + dir.col };
        
        if (adjPos.row >= 0 && adjPos.row < 10 && adjPos.col >= 0 && adjPos.col < 10
            && board->getBoardSquares()[adjPos.row][adjPos.col]->GetIsCanMove()) {
            
            ret_adjacent_squares.push_back(adjPos);
        }
    }

    return ret_adjacent_squares;
}
