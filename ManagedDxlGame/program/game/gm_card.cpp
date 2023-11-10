#include "gm_card.h"

//カードのコピーを返す
std::shared_ptr<Card> Card::CopyCard()
{
    auto ret_card = std::make_shared<Card>(card_data_);

    return ret_card;
}
