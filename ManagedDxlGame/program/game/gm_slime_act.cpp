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

	//turn_enemyの位置を取得
	SquarePos turn_enemy_pos = turn_enemy->GetUnitSquarePos();

	//上下左右隣り合っているマスを取得
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

	//隣り合っているマスにUnitAllyがいたらaround_allyに追加
	std::vector<UnitAlly*> around_ally;
	for (auto pos : around_pos) {
		if (board->getBoardSquare(pos.row, pos.col)->GetAllyPtrInSquare()) {
			around_ally.push_back(board->getBoardSquare(pos.row, pos.col)->GetAllyPtrInSquare());
		}
	}

	UnitAlly* target_ally = nullptr;

	//いなかったら終了
	if (around_ally.empty()) { return; }
	//いる場合
	else if(!around_ally.empty()) {

		// taunt_ 値でソート
		std::sort(around_ally.begin(), around_ally.end(), [](UnitAlly* a, UnitAlly* b) {
			return a->GetTauntValue() < b->GetTauntValue();
		});
		
		// 最も高い taunt_ 値を持つ要素をすべて収集
		int highest_taunt = around_ally.back()->GetTauntValue();
		std::vector<UnitAlly*> highest_taunt_allies;
		std::copy_if(around_ally.begin(), around_ally.end(), std::back_inserter(highest_taunt_allies), [highest_taunt](UnitAlly* unit) {
			return unit->GetTauntValue() == highest_taunt;
		});

		// ランダムに1つ選ぶ
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> distr(0, highest_taunt_allies.size() - 1);
		
		target_ally = highest_taunt_allies[distr(gen)];
	}

	//damageを与える
	if (target_ally) {
		target_ally->DecreaseCurrentHp(turn_enemy->GetCurrentPower());
		
		anim_mgr_.GetAnim()[0]->SetObjPosToSquarePos(target_ally->GetUnitSquarePos().row, target_ally->GetUnitSquarePos().col);
		anim_mgr_.GetAnim()[0]->CardAnimPlay("anim_attack");

		mgr.PlayEnemyActSE(1);
		mgr.PlayAllyDamagedVoice(target_ally->GetAllyData()->GetAllyDataID());

	}

}

