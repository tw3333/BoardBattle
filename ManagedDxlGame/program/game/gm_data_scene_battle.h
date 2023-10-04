#pragma once

//memo
//SceneBattleで使用する数値など
//defineで定義すべきなのかどうか



enum class CardError{
	CantMove,
	NotEnoughCost,
	NoTarget,
};

struct BoardSize {

	int width = 0;
	int height = 0;
	
};

