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
