#pragma once
#include <array>
#include <vector>
#include <memory>
#include "gm_square.h"
#include "../dxlib_ext/dxlib_ext.h"
#include "gm_object_manager.h"

class Board {
public:

	Board(){}
	~Board(){}

	void Create();
	void Update(float delta_time);
	void Render(dxe::Camera* camera);

	std::array<std::array<Square*, 10>, 10> getBoardSquares() { return test_board_squares_;}

private:

	std::vector<Square*> board_squares_;

	std::vector<Square*> ts_board_squares_;


	Square* square_[9][9];

	std::array<std::array<Square*, 10>,10> test_board_squares_;

	ObjectManager& omgr_ = ObjectManager::GetInstance();

};