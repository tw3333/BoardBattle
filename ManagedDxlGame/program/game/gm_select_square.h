#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include "../dxlib_ext/dxlib_ext_camera.h"

//memo
//盤面上の１マスをマウスで選択できるようにするクラス
//

class SelectSquare {
public:

	SelectSquare() {}
	~SelectSquare(){}

	struct MousePos {
		int x;
		int y;
	};

	void Update(float delta_time,dxe::Camera* camera);
	void Render();


private:

	





};