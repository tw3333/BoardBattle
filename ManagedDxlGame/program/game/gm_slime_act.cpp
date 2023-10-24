#include "gm_slime_act.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

#include "gm_data_board.h"
#include "gm_board.h"
#include "gm_unit.h"
#include "gm_unit_enemy.h"
#include "gm_unit_ally.h"

#include "gm_sound_manager.h"

void SlimeAct::Act(UnitEnemy* turn_enemy, Board* board) {

	//turn_enemy�̈ʒu���擾
	SquarePos turn_enemy_pos = turn_enemy->GetUnitSquarePos();

	//�㉺���E�ׂ荇���Ă���}�X���擾
	std::vector<SquarePos> around_pos;
	if (turn_enemy_pos.row > 0) {
		around_pos.push_back(SquarePos(turn_enemy_pos.row -1, turn_enemy_pos.col));
	}
	if (turn_enemy_pos.row < 9) {
		around_pos.push_back(SquarePos(turn_enemy_pos.row + 1, turn_enemy_pos.col));
	}
	if (turn_enemy_pos.col > 0) {
		around_pos.push_back(SquarePos(turn_enemy_pos.row, turn_enemy_pos.col -1));
	}
	if (turn_enemy_pos.col < 9) {
		around_pos.push_back(SquarePos(turn_enemy_pos.row, turn_enemy_pos.col + 1));
	}

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
	else if(!around_ally.empty()) {

		// taunt_ �l�Ń\�[�g
		std::sort(around_ally.begin(), around_ally.end(), [](UnitAlly* a, UnitAlly* b) {
			return a->GetTauntValue() < b->GetTauntValue();
		});
		
		// �ł����� taunt_ �l�����v�f�����ׂĎ��W
		int highest_taunt = around_ally.back()->GetTauntValue();
		std::vector<UnitAlly*> highest_taunt_allies;
		std::copy_if(around_ally.begin(), around_ally.end(), std::back_inserter(highest_taunt_allies), [highest_taunt](UnitAlly* unit) {
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
		anim_mgr_.GetAnim()[0]->CardAnimPlay("anim_attack");

		mgr.PlayEnemyActSE(1);
		mgr.PlayAllyDamagedVoice(target_ally->GetAllyData()->GetAllyDataID());

	}

}

