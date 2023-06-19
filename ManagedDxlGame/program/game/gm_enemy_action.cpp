#include "gm_enemy_action.h"

//Enemy�̑��ʏ㉺���E�ɁAAlly�����邩�ǂ����𒲂ׂ�
bool EnemyAction::IsAdjacentAlly(UnitEnemy* unit_enemy, UnitAlly* unit_ally) {

    int row_diff = std::abs(unit_enemy->GetBoardPos().row - unit_ally->GetBoardPos().row);
    int col_diff = std::abs(unit_enemy->GetBoardPos().col - unit_ally->GetBoardPos().col);
        
    return (row_diff <= 1 && col_diff <= 1);
}

//Enemy�̏㉺���E�ɓG�����Ȃ����ǂ����𒲂ׂ�
//������true,���Ȃ�������false��Ԃ�
bool EnemyAction::IsAllyNearby(UnitEnemy* unit_enemy, std::vector<UnitAlly*> party) {

    int enemy_row = unit_enemy->GetBoardPos().row;
    int enemy_col = unit_enemy->GetBoardPos().col;

    for (auto ally : party) {

        if (std::abs(enemy_row - ally->GetBoardPos().row) <= 1 && std::abs(enemy_col - ally->GetBoardPos().col) <= 1) {
            return true;
        }

    }

    return false;
}


