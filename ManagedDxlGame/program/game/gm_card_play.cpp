#include "gm_card_play.h"

#include "gm_card.h"
#include "gm_card_effect.h"

#include "gm_card_range.h"
#include "gm_card_range_self.h"
#include "gm_card_target.h"

#include "gm_unit.h"
#include "gm_unit_ally.h"
#include "gm_unit_enemy.h"

#include "gm_board.h"
#include "gm_ui_card.h"
#include "../dxlib_ext/dxlib_ext.h"

#include "gm_data_board.h"

#include <algorithm>
#include <vector>


void CardPlay::Update(float delta_time) {

	//for (auto a : anim_manager_.GetDebugAnimList()) {

	//	a->Update(delta_time);

	//}

	if (!card_effect_anim_.empty()) {
		for (auto cea : card_effect_anim_) { cea->Update(delta_time); }
	}

	if (select_uicard_) {

		if (tnl::Input::IsMouseTrigger(eMouseTrigger::IN_LEFT)) {

			//if (select_uicard_->GetCardPtr()->GetCardData()->GetTargetType() == TargetType::SpecifyTarget) {





			//}




		}




	}





}

void CardPlay::Render(dxe::Camera* camera) {

	DebugRender();

	if (!card_effect_anim_.empty()) {
		for (auto cea : card_effect_anim_) { cea->Render(camera); }
	}




}

//�I������Ă���UICard�̎˒���Ֆʂɕ\��
void CardPlay::RenderSelectCardRange(UnitAlly* turn_ally, Board* board) {

	if (select_uicard_) {

		for (auto a: select_uicard_->GetCardPtr()->GetCardData()->GetCardRangeList()) {
			a->DisplayRange(turn_ally,board);

		}


		//select_uicard_->GetCardPtr()->GetCardData()->card_range_->DisplayRange(turn_ally, board);
	}
	else if(!select_uicard_) {
		board->ResetRangeTile();
	}



}


//Card�̎��˒�����Unit��z��Ɋi�[
void CardPlay::UpdateSelectCardGetUnitInRange(UnitAlly* turn_ally, std::vector<Unit*> all_units) {

	if (select_uicard_) {

		total_units_in_range_.clear();

		for (auto a : select_uicard_->GetCardPtr()->GetCardData()->GetCardRangeList())
		{
			std::vector<Unit*> unit_in_range = a->GetUnitInRange(turn_ally, all_units);
			total_units_in_range_.insert(total_units_in_range_.end(), unit_in_range.begin(), unit_in_range.end());
		}

		//debugcode
		DrawStringEx(0,600,-1,"�Ώۂ�%d�l���܂�",total_units_in_range_.size());

	}

}

//�I������Ă���Card��RangePos���i�[�A���̍X�V
void CardPlay::UpdateSelectCardRangeSquarePos(SquarePos axis_pos) {

	
	if (select_uicard_) 
	{
		card_range_square_pos_.clear();

		if (card_range_square_pos_.empty()) {

			for (auto& a : select_uicard_->GetCardPtr()->GetCardData()->GetCardRangeList())
			{
				std::vector<SquarePos> range_square_pos = a->GetRangeSquarePos(axis_pos);
				card_range_square_pos_.insert(card_range_square_pos_.end(), range_square_pos.begin(), range_square_pos.end());
			}


		}


	}

}

void CardPlay::DebugRender() {

	if (select_uicard_) {

		DrawStringEx(0,650,-1,"���̃J�[�h��[%d]�ł�",select_uicard_->debug_cnt_);

	}
	else {
		DrawStringEx(0,650,-1,"select_uicard_��null�ł�");
	}


	for (int i = 0; i < total_units_in_range_.size(); ++i) {


		DrawStringEx(0, 250 + 20 * i, -1, "AnimPosX:%d", anim_manager_.GetDebugAnimList()[i]->pos_.x);


		

	}

}

void CardPlay::EffectExecute()
{
	if (select_uicard_ && turn_ally_) {

		if (tnl::Input::IsMouseTrigger(eMouseTrigger::IN_LEFT)) {

			//�ǂ̎˒��ɂ��N�����Ȃ��ꍇ�͏����𒆒f����
			//for (auto a : select_uicard_->GetCardPtr()->GetCardData()->GetCardRangeList()) {

			//	if (a->GetIsUnitInRange() == false) {

			//		//debugcode
			//		DrawStringEx(0, 500, -1, "�˒��ɒN�����Ȃ���I");

			//		return;
			//	}
			//}
			if (total_units_in_range_.empty()) {

				//debugcode
				DrawStringEx(0, 500, -1, "�˒��ɒN�����Ȃ���I");

				return;
			}


			//���ʎ��s����
			for (auto a : select_uicard_->GetCardPtr()->GetCardData()->GetCardEffectList()) {

				a->Effect(total_units_in_range_);
			}

			for (int i = 0; i < total_units_in_range_.size(); ++i) {

				if (total_units_in_range_[i]->GetUnitType() == UnitType::Ally) {

					UnitAlly* unit_ally = dynamic_cast<UnitAlly*>(total_units_in_range_[i]);
					card_effect_anim_[i]->pos_ = unit_ally->GetObj()->pos_;

				}
				else if (total_units_in_range_[i]->GetUnitType() == UnitType::Enemy) {

					UnitEnemy* unit_enemy = dynamic_cast<UnitEnemy*>(total_units_in_range_[i]);
					card_effect_anim_[i]->pos_ = unit_enemy->GetObj()->pos_;

				}

				card_effect_anim_[i]->setCurrentAnim(select_uicard_->GetCardPtr()->GetCardData()->debug_anim_name_);

			}
			
			for (int i = 0; i < total_units_in_range_.size(); ++i) {

				card_effect_anim_[i]->getCurrentAnimSeekUnit()->play();

			}

			//Se�Đ�
			//sound_manager_.PlayCardSE(select_uicard_->GetCardPtr()->GetCardData()->GetCardID());
			sound_manager_.PlayCardSE(1);




			int select_serial_num = select_uicard_->GetCardPtr()->GetSerialNum();

			

			//turn_ally_->GetHand().pop_back();
			//UI�Ɠ����J�[�hPtr��Hand����폜
			turn_ally_->GetHand().erase(std::remove_if(turn_ally_->GetHand().begin(), turn_ally_->GetHand().end(),
				[select_serial_num](const std::shared_ptr<Card>& card) {
				return card->GetSerialNum() == select_serial_num;
				}), turn_ally_->GetHand().end());
		
		}

	}

}




//�J�[�h�̌��ʂ����s
void CardPlay::PlayCardExecute(Board* board) {

	//if (anim_manager_.GetDebugAnim()->getCurrentAnimSeekUnit()->GetIsPlaying()) {
	//	return;
	//}



	if (play_card_ && turn_ally_) {
		
		//ref_num����v����Target�Ɋi�[����Ă���Unit��Effect
		for (auto a : play_card_->GetCardData()->GetCardEffectList()) {

			for (auto b : play_card_->GetCardData()->GetCardTargetList()) {

				if (a->GetEffectRefNum() == b->GetTargetRefNum()) {

					//a->Effect(b->GetTargetUnits());
					a->EffectExcute(b->GetTargetSquaresPos(), board);
				
				}
			}
		}

		//Anim���Đ�������W��ݒ�
		for (auto &target : play_card_->GetCardData()->GetCardTargetList()) {

			for (auto &square : target->GetTargetSquaresPos()) {

				anim_manager_.GetDebugAnim()->SetObjPosToSquarePos(square.row, square.col);

			}
		}

		anim_manager_.GetDebugAnim()->CardAnimPlay(play_card_->GetCardData()->debug_anim_name_);


		//CardTarge�Ɋi�[����SquarePos�����Z�b�g
		for (auto a : play_card_->GetCardData()->GetCardTargetList()) {

			//a->GetTargetUnits().clear();
			a->GetTargetSquaresPos().clear();

		}


		int select_serial_num = play_card_->GetSerialNum();


		//play_card�Ɠ����J�[�hPtr��Hand����폜
		turn_ally_->GetHand().erase(std::remove_if(turn_ally_->GetHand().begin(), turn_ally_->GetHand().end(),
			[select_serial_num](const std::shared_ptr<Card>& card) {
				return card->GetSerialNum() == select_serial_num;
			}), turn_ally_->GetHand().end());

	}



}



bool CardPlay::CanPlayCardExecute(Board* board)
{

	if (play_card_ && turn_ally_) {

		//ref_num����v����Target�Ɋi�[����Ă���Unit��Effect
		for (auto a : play_card_->GetCardData()->GetCardEffectList()) {

			for (auto b : play_card_->GetCardData()->GetCardTargetList()) {

				if (a->GetEffectRefNum() == b->GetTargetRefNum()) {

					if (!a->CanEffectExcute(b->GetTargetSquaresPos(),board)) {

						return false;
					}

				}
			}

		}

	}

	return true;
}

bool CardPlay::CanPlaySelectCard() {

	//�R�X�g����
	if (select_uicard_->GetCardPtr()->GetCardData()->GetCardCost() > turn_ally_->GetCurrentCardCost()) {

		return false;
	}

	//�˒�����






	return true;
}

bool CardPlay::IsSelectCardCostEnough() {

	//�R�X�g����
	if (select_uicard_->GetCardPtr()->GetCardData()->GetCardCost() > turn_ally_->GetCurrentCardCost()) {
		return false;
	}

	return true;
}

bool CardPlay::IsSelectCardTargetInRange(Board* board)
{
	//if (total_units_in_range_.empty()) {
	//	return false;
	//}

	if (card_range_square_pos_.empty()) {
		return false;
	}

	for (auto a : select_uicard_->GetCardPtr()->GetCardData()->GetCardTargetList()) {

		//InRange����
		if (a->GetTargetType() == TARGETTYPE::InRange) {

			if (a->GetToTarget() == TOTARGET::All) {
				//if (total_units_in_range_.empty()) {
				//	return false;
				//}
			
				for (auto pos : card_range_square_pos_) {

					if (board->getBoardSquare(pos.row, pos.col)->GetUnitPtrInSquare()) {
						return true;
					}
				}

			}
			else if (a->GetToTarget() == TOTARGET::Ally) {
				
				//for (auto tuir : total_units_in_range_) {
				//	if (tuir->GetUnitType() == UnitType::Ally) {
				//		return true;
				//	}
				//}

				for (auto pos : card_range_square_pos_) {

					if (board->getBoardSquare(pos.row, pos.col)->GetAllyPtrInSquare()) {
						return true;
					}
				}

				return false;
			}
			else if (a->GetToTarget() == TOTARGET::Enemy) {
				
				//for (auto tuir : total_units_in_range_) {
				//	if (tuir->GetUnitType() == UnitType::Enemy) {
				//		return true;
				//	}
				//}

				for (auto pos : card_range_square_pos_) {

					if (board->getBoardSquare(pos.row, pos.col)->GetEnemyPtrInSquare()) {
						return true;
					}

				}
				return false;
			}

		}

		//Specify����
		if (a->GetTargetType() == TARGETTYPE::Specify) {

			if (a->GetToTarget() == TOTARGET::All) {
				//if (total_units_in_range_.empty()) {
				//	return false;
				//}

				for (auto pos : card_range_square_pos_) {
					if (board->getBoardSquare(pos.row, pos.col)->GetUnitPtrInSquare()) {
						return true;
					}	
				}

			}
			else if (a->GetToTarget() == TOTARGET::Ally) {

				//for (auto tuir : total_units_in_range_) {
				//	if (tuir->GetUnitType() == UnitType::Ally) {
				//		return true;
				//	}
				//}

				for (auto pos : card_range_square_pos_) {

					if (board->getBoardSquare(pos.row, pos.col)->GetAllyPtrInSquare()) {
						return true;
					}
				}

				return false;
			}
			else if (a->GetToTarget() == TOTARGET::Enemy) {

				//for (auto tuir : total_units_in_range_) {
				//	if (tuir->GetUnitType() == UnitType::Enemy) {
				//		return true;
				//	}
				//}

				for (auto pos : card_range_square_pos_) {

					if (board->getBoardSquare(pos.row, pos.col)->GetEnemyPtrInSquare()) {
						return true;
					}

				}
				return false;
			}
		}
	}
}

std::vector<Unit*> CardPlay::ExtractUnitInRange(TOTARGET to_target) {

	std::vector<Unit*> extract_unit;

	for (auto a : total_units_in_range_) {

		if (to_target == TOTARGET::Ally) {

			if (a->GetUnitType() == UnitType::Ally) {

				extract_unit.push_back(a);
			}

		}
		else if (to_target == TOTARGET::Enemy) {

			if (a->GetUnitType() == UnitType::Enemy) {

				extract_unit.push_back(a);
			}

		}
	}

	return extract_unit;
}

//Range����e��Target�̍��W�𒊏o
std::vector<SquarePos> CardPlay::ExtractTargetSquarePosInRange(TOTARGET to_target, Board* board)
{
	std::vector<SquarePos> target_square_pos;

	for (auto pos : card_range_square_pos_) {

		if (to_target == TOTARGET::All) {

			if (board->getBoardSquare(pos.row, pos.col)->GetUnitPtrInSquare()) {

				target_square_pos.push_back(pos);

			}

		}
		else if (to_target == TOTARGET::Ally) {

			if (board->getBoardSquare(pos.row, pos.col)->GetAllyPtrInSquare()) {

				target_square_pos.push_back(pos);

			}

		}
		else if (to_target == TOTARGET::Enemy) {

			if (board->getBoardSquare(pos.row, pos.col)->GetEnemyPtrInSquare()) {

				target_square_pos.push_back(pos);

			}

		}

	}

	return target_square_pos;
}

int CardPlay::GetInRangeTargetNum(TOTARGET to_target, Board* board)
{
	int cnt = 0;

	if (to_target == TOTARGET::All) {

		for (auto range_pos : card_range_square_pos_) {
			if (board->getBoardSquare(range_pos.row, range_pos.col)->GetUnitPtrInSquare()) {
				cnt++;
			}
		}

		return cnt;
	}
	else if (to_target == TOTARGET::Ally) {
		
		for (auto range_pos : card_range_square_pos_) {
			if (board->getBoardSquare(range_pos.row, range_pos.col)->GetAllyPtrInSquare()) {
				cnt++;
			}
		}
			
		return cnt;
	}
	else  if (to_target == TOTARGET::Enemy) {

		for (auto range_pos : card_range_square_pos_) {
			if (board->getBoardSquare(range_pos.row, range_pos.col)->GetEnemyPtrInSquare()) {
				cnt++;
			}
		}

		return cnt;
	}

}

void CardPlay::SetCameraToCardEffectAnim(dxe::Camera* camera) {

	if (!card_effect_anim_.empty()) {

		for (auto cra : card_effect_anim_) {
			cra->SetCamera(camera);
			cra->setCurrentAnim("none");
		}

	}

}
