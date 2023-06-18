#include "gm_slime_action.h"
#include <random>

void SlimeAction::Execute(UnitEnemy* unit_enemy) {

	int unit_row = unit_enemy->GetBoardPos().row;
	int unit_col = unit_enemy->GetBoardPos().col;

    if (!IsAllyNearby(unit_enemy)) {
        Move(unit_enemy);
    }


    Action(unit_enemy);
    

}

void SlimeAction::Render(dxe::Camera* camera) {





}

void SlimeAction::Move(UnitEnemy* unit_enemy) {

    std::default_random_engine engine(std::random_device{}());

    // We store all allies with the highest taunt in a vector
    std::vector<UnitAlly*> highestTauntAllies;
    int highestTaunt = 0;

    for (auto ally : party_) {
        int allyTaunt = ally->GetTauntValue();
        
        if (allyTaunt > highestTaunt) {
            highestTaunt = allyTaunt;
            highestTauntAllies.clear();
            highestTauntAllies.push_back(ally);
        }
        else if (allyTaunt == highestTaunt) {
            highestTauntAllies.push_back(ally);
        }

    }

    if (highestTauntAllies.empty()) {
        return;  // No allies to taunt
    }

    // Randomly pick one among the allies with the highest taunt
    std::uniform_int_distribution<int> dist(0, highestTauntAllies.size() - 1);
    UnitAlly* target = highestTauntAllies[dist(engine)];

    // Calculate direction towards the ally with highest taunt
    int dx = target->GetBoardPos().col - unit_enemy->GetBoardPos().row;
    int dy = target->GetBoardPos().row - unit_enemy->GetBoardPos().col;


    // Normalize direction
    if (dx != 0) dx /= std::abs(dx);
    if (dy != 0) dy /= std::abs(dy);

    // Move towards the ally
    int remaining_cost = unit_enemy->GetMaxMoveCost();
    
    while (remaining_cost > 0 && IsAllyNearby(unit_enemy)) {
       
        int nextRow = unit_enemy->GetBoardPos().row + dy;
        int nextCol = unit_enemy->GetBoardPos().col + dx;
        
        if (IsValidPosition(nextRow, nextCol)) {
            unit_enemy->SetBoardPos(nextRow, nextCol);
            remaining_cost--;
        }
    }

}



void SlimeAction::Action(UnitEnemy* unit_enemy) {

    // Prepare a random engine
    std::default_random_engine engine(std::random_device{}());

    // We store all adjacent allies with the highest taunt in a vector
    std::vector<UnitAlly*> highestTauntAdjacentAllies;
    int highestTaunt = 0;

    for (auto ally : party_) {

        if (IsAdjacentAlly(unit_enemy,ally)) {
            
            int allyTaunt = ally->GetTauntValue();
            
            if (allyTaunt > highestTaunt) {
                highestTaunt = allyTaunt;
                highestTauntAdjacentAllies.clear();
                highestTauntAdjacentAllies.push_back(ally);
            }
            else if (allyTaunt == highestTaunt) {
                highestTauntAdjacentAllies.push_back(ally);
            }

        }

    }

    if (highestTauntAdjacentAllies.empty()) {
        return;  // No adjacent allies to taunt
    }

    // Randomly pick one among the adjacent allies with the highest taunt
    std::uniform_int_distribution<int> dist(0, highestTauntAdjacentAllies.size() - 1);
    UnitAlly* target = highestTauntAdjacentAllies[dist(engine)];

    // Deal damage to the target
    target->DecreaseCurrentHp(damage_);

}



bool SlimeAction::IsAllyNearby(UnitEnemy* unit_enemy) {

    int enemy_row = unit_enemy->GetBoardPos().row;
    int enemy_col = unit_enemy->GetBoardPos().col;

    for (auto* ally : party_) {

        if (std::abs(enemy_row - ally->GetBoardPos().row) <= 1 && std::abs(enemy_col - ally->GetBoardPos().col) <= 1) {
            return true;
        }

    }

    return false;


}

bool SlimeAction::IsAdjacentAlly(UnitEnemy* unit_enemy,UnitAlly* unit_ally) {
    
    int row_diff = std::abs(unit_enemy->GetBoardPos().row - unit_ally->GetBoardPos().row);
    int col_diff = std::abs(unit_enemy->GetBoardPos().col - unit_ally->GetBoardPos().col);
    
    return (row_diff <= 1 && col_diff <= 1);
}
