#include "gm_card.h"

//�J�[�h�̃R�s�[��Ԃ�
std::shared_ptr<Card> Card::CopyCard()
{
    auto ret_card = std::make_shared<Card>(card_data_);

    return ret_card;
}
