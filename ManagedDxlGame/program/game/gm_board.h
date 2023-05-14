#pragma once
#include <vector>
#include <memory>
#include "gm_square.h"
#include "../dxlib_ext/dxlib_ext.h"

class Board {
public:

	Board(){}
	~Board(){}

	void Create();
	void Update(float delta_time);
	void Render(dxe::Camera* camera);

private:

	std::vector<Square*> board_squares_;

	std::vector<std::unique_ptr<Square>> ts_board_square_;


};