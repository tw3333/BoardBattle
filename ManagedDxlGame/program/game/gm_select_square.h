#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include "../dxlib_ext/dxlib_ext_camera.h"
#include "gm_object_select_flame.h"
#include "gm_square.h"
#include <array>

#include "gm_data_board.h"

//memo
//盤面上の１マスをマウスで選択できるようにするクラス
//

class SelectSquare {
public:

	SelectSquare(const std::array<std::array<Square*,10>,10> board_squares) 
	:board_squares_(board_squares) 
	{
		obj_ = ObjSelectFlame::Create();
	}
	~SelectSquare(){}


	void Update(float delta_time,dxe::Camera* camera);
	void Render(dxe::Camera* camera);
	bool IsSelectFlameOutOfBoard(tnl::Vector3 hit);

	//アクセッサー
	ObjSelectFlame* GetObj() { return obj_; }
	int GetSelectSquareRow() { return select_square_row_; }
	int GetSelectSquareCol() { return select_square_col_; }
	tnl::Vector3 GetSelectSquareObjPos() { return select_square_obj_pos_; }

	Square* GetSelectSquare() { return select_square_; }

	SquarePos GetSelectSquarePos() { return select_square_pos_; }


private:

	ObjSelectFlame* obj_; //p
	tnl::Vector3 hit_;

	int board_w_ = (DXE_WINDOW_WIDTH / 10) * 8;
	int board_h_ = (DXE_WINDOW_HEIGHT / 10) * 8;

	int bw1_ = board_w_ / 10;
	int bh1_ = board_h_ / 10;

	std::array<std::array<Square*, 10>, 10> board_squares_; //p

	int select_square_row_ = 0; //選択されているsquareのrow
	int select_square_col_ = 0; //選択されているsquareのcol

	SquarePos select_square_pos_; //選択されているsquareのpos
	
	Square* select_square_ = nullptr;
	
	tnl::Vector3 select_square_obj_pos_; //選択されているSquareのObjPos\
	 
};